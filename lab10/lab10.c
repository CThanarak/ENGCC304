#include <stdio.h>
#include <string.h>

void toLowerCase( char str[] ) ;
int isPalindrome( char str[] ) ;

int main() {
    char word[100] ;

    printf( "Enter word:\n" ) ;
    scanf( "%s", word ) ;

    toLowerCase( word ) ;

    if( isPalindrome(word) )
        printf( "Pass.\n" ) ;
    else
        printf( "Not Pass.\n" ) ;

    return 0 ;
}// End main

void toLowerCase( char str[] ) {
    int i ;
    for( i = 0; str[i] != '\0'; i++ ) {
        if( str[i] >= 'A' && str[i] <= 'Z' ) {
            str[i] = str[i] + 32 ;
        }// End if
    }// End for
}// End toLowerCase

int isPalindrome( char str[] ) {
    int i, len = strlen( str ) ;

    for( i = 0; i < len / 2; i++ ) {
        if( str[i] != str[len - i - 1] ) {
            return 0 ;
        }// End if
    }// End for
    return 1 ;
}// End isPalindrome

//Flowchart : https://drive.google.com/file/d/1vf-OX_ht8mdRfGrUjoQnCoLpAXZzarO8/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1LyPwU0w_RuBO0FEiRQHoB1XJ4CrJyo_DjKDuGc0yf10/edit?usp=sharing