#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "idgen.h"
#include "random.h"

static const int area[26] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34,
        18, 19, 20, 21, 22, 35, 23, 24, 25,
        26, 27, 28, 29, 30, 31, 32, 33
};

static const int weight[9] = {
        9, 8, 7, 6, 5, 4, 3, 2, 1
};


char * idgen_for_Taiwan( int country, int sex )
{
        int checksum = 0, i = 0;
        char *ID = ( char * ) malloc( sizeof( char * ) * 10 + 1 );
        
        /* 如果性別的選項為 "隨機" */
        if ( 0 == sex ) {
                sex = randgen(2) + 1;
        }
        /* 如果城市的選項為 "隨機" */
        if ( 0 == country ) {
                country = randgen(26) + 1;
        }

        i = country - 1;

        ID[0] = country + 'A' - 1;
        ID[1] = sex + '0';

        /* 計算縣市的加值 */
        checksum += ( area[i] / 10 ) + ( area[i] % 10 ) * weight[0];
        /* 計算性別的加值 */
        checksum += sex * weight[1];

        for( i = 2; i < 9; i++ ) {
                ID[i] = rand_digit();
        }

        for( i = 2; i < 9; i++ ) {
                checksum += ( ID[i] - '0' ) * weight[i];
        }

        checksum %= 10;
        
        if( 0 == checksum ) {
                ID[9] = '0';
        }
        else {
                ID[9] = 10 - checksum + '0';
        }

        ID[10] = '\0';
        
        return ID;
}


