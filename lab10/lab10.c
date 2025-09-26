#include <stdio.h>
#include <string.h>

int main() {
    char word[100] ;
    int i, length, isPalindrome = 1 ;

    printf( "Enter word: " ) ;
    scanf( "%s" , word ) ;

    length = strlen( word ) ;

    for ( i = 0 ; i < length / 2 ; i++ ) {
        char left = word[i] ;
        char right = word[length - i - 1] ;

        if ( left >= 'A' && left <= 'Z' ) {
            left = left + 32 ;
        }//end if

        if ( right >= 'A' && right <= 'Z' ) { 
            right = right + 32 ;             
        }//end if

        if ( left != right ) {
            isPalindrome = 0 ;
            break ;
        }// End if
    }// End for

    if ( isPalindrome )
        printf( "Pass.\n" ) ;
    else
        printf( "Not Pass.\n" ) ;

    return 0 ;
}// End main
