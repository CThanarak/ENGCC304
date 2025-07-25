#include <stdio.h>

int main() {
    int score = 0;

    printf( "Enter your score: " ) ;
    if ( scanf( "%d", & score ) != 1 ) {
        printf( "Please Enter number only. \n" ) ;
    } else if ( score >= 80 && score <= 100 ) {
        printf( "A ! \n" ) ;
    } else if ( score >= 75 && score < 80 ) {
        printf( "B+ ! \n" ) ;
    } else if ( score >= 70 && score < 75 ) {
        printf( "B ! \n" ) ;
    } else if ( score >= 65 && score < 70 ) {
        printf( "C+ ! \n" ) ;
    } else if ( score >= 60 && score < 65 ) {
        printf( "C ! \n" ) ;
    } else if ( score >= 55 && score < 60 ) {
        printf( "D+ ! \n" ) ;
    } else if ( score >= 50 && score < 55 ) {
        printf( "D ! \n" ) ;
    } else if ( score >= 0 && score < 50 ) {
        printf( "F ! \n" ) ;
    } else {
        printf( "Please enter a score between 0 and 100. \n" );
    } //end if
    
    return 0;
} //end main