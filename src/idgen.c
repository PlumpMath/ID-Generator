#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "idgen.h"

static const int area[26] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34,
        18, 19, 20, 21, 22, 35, 23, 24, 25,
        26, 27, 28, 29, 30, 31, 32, 33
};

/**
 * 產生身份證字號
 *
 * @param country
 * @param sex
 *
 */
char * idgen( int country, int sex )
{
        int checksum = 0, count = 7, i = 0;
        char *ID = ( char * ) malloc( sizeof( char * ) * 10 + 1 );

        srand( ( unsigned ) time( NULL ) );
        
        /* 如果性別的選項為 "隨機" */
        if ( 0 == sex ) {
                sex = rand() % 2 + 1;
        }
        /* 如果城市的選項為 "隨機" */
        if ( 0 == country ) {
                country = rand() % 26 + 1;
        }

        i = country - 1;
        ID[0] = country + 'A' - 1;
        ID[1] = sex + '0';

        /* 計算性別的加值 */
        checksum += sex * 8;
        /* 計算縣市的加值 */
        checksum += ( area[i] / 10 ) + ( area[i] % 10 ) * 9;

        for( i = 2; i < 9; i++ ) {
                ID[i] = rand() % 10 + '0';
        }

        for( i = 2; i < 9; i++ ) {
                checksum += ( ID[i] - '0' ) * count;
                count--;
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


