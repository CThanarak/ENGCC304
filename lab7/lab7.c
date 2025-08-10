#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int answer = 0 ;
    srand ( time ( NULL ) ) ;

    do {
        do {
            printf( "Do you want to play a game? (1 = play / -1 = exit): " ) ;
            if (scanf( "%d" , &answer ) != 1 ) {
                printf( "Please enter only 1 or -1.\n" ) ;
                while( getchar() != '\n' ) ;
                answer = 0 ;
            }//end if

        } while (answer != 1 && answer != -1);

        if ( answer == -1 ) break ;
        int score = 100 ;
        int num = 0 ;
        int high = 100 ;
        int low = 1 ;
        int random = rand() % 100 + 1 ;

        printf( "(Score = %d)\n" , score ) ;

        while ( num != random && score > 0 ) {
            printf( "Guess the winning number (%d-%d): ", low, high ) ;

            if ( scanf ( "%d" , &num ) != 1 ) {
                printf( "Please enter 1 to 100.\n" ) ;
                while( getchar() != '\n' ) ;
                continue;
            }//end if

            if ( num != random ) {
                score -= 10 ;

                if ( num < random ) {
                    low = num + 1 ;
                    printf( "Sorry, the winning number is HIGHER than %d (Score = %d)\n", num, score ) ;
                } else {
                    high = num - 1 ;
                    printf( "Sorry, the winning number is LOWER than %d (Score = %d)\n", num, score ) ;
                }//end if
            }//end if
        }//end while

        if ( score <= 0 ) {
            printf( "Game over! Your score is 0.\n" );
        } else {
            printf( "That is correct! The winning number is %d.\n", num ) ;
            printf( "Your score is %d\n", score ) ;
        }//end if

    } while ( answer == 1 ) ;

    printf( "See you again!\n" ) ;
    return 0 ;
    
}// end main