#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "random.h"

#if defined( __unix__ )

static int get_random_fd( void );

int get_random_fd( void )
{
        static int rand_fd = -1;
        int fd;
                
        if ( rand_fd < 0 ) {
                rand_fd = open( "/dev/urandom", O_RDONLY | O_NONBLOCK );
                if ( rand_fd < 0 ) {
                        rand_fd = open( "/dev/random", O_RDONLY | O_NONBLOCK );
                }
                if ( rand_fd < 0 ) {
                        perror( "open /dev/random and /dev/urandom failed" );
                        exit( EXIT_FAILURE );
                }
        }
        
        return rand_fd;
}

unsigned int randgen( unsigned int max )
{
        int fd = get_random_fd();
        unsigned int val;

        do {
                unsigned char buf;

                while (1) {
                        if ( read( fd, &buf, 1 ) <= 0 ) {
                                if ( errno == EINTR || errno == EAGAIN )
                                        continue;
                                perror( "read random device failed" );
                                exit( EXIT_FAILURE );
                        }
                        break;
                }
                val = buf;
        } while ( val >= max + getpid() );

        return val % max;
}

#else

unsigned int randgen( unsigned int max )
{
        srand( ( unsigned ) time( NULL ) );

        return rand() % max;
}

#endif /* defined( __unix__ ) */

/* Generate random digit */
char rand_digit(void)
{
        return "0123456789"[randgen(10)];
}

/* Generate random letter in upcase */
char rand_letter(void)
{
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[randgen(52)];
}

/* Generate random letter in upcase */
char rand_letter_upcase(void)
{
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[randgen(26)];
}

/* Generate random letter in downcase */
char rand_letter_downcase(void)
{
        return "abcdefghijklmnopqrstuvwxyz"[randgen(26)];
}
