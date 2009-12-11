#ifndef _ID_RANDOM_H
#define _ID_RANDOM_H 

#if defined( __unix__ )
#		include <sys/types.h>
#		include <unistd.h>
#		include <fcntl.h>
#else
#		include <time.h>
#endif /* defined( __unix__ ) */

unsigned int randgen( unsigned int max );
char rand_digit(void);
char rand_letter_upcase(void);
char rand_letter_downcase(void);

#endif /* _ID_RANDOM_H */

