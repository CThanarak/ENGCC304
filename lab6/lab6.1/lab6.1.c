#include <stdio.h>

void numtoword( int num ) {
    char *word[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven",
        "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    } ;

    for ( int i = 0; i < 20; i++ ) {
        if ( num == i ) {
            printf( "Result : %s\n", word[i] ) ;
            break ;
        }
    }
}//end numtoword

int main() {
    int num, i ;

    printf( "User Input :" ) ;
    if ( scanf( "%d", &num ) != 1 ) {
        printf( "Please Enter number only. \n" ) ;
        return 0 ;
    }//end if
    
    if ( num < 0 || num > 19 ) {
        printf( "Please enter a number between 0 and 19. \n" ) ;
        return 0 ;
    }//end if

    numtoword( num ) ;

    return 0 ;
}//end main


//Flowchart: https://drive.google.com/file/d/1BjNw8_kc2OqQPBM6gg0pS9_r_17y003F/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1C94HADPytsfg525t4VLmSA68uFjVTjPCd1LTLh_2YfY/edit?usp=sharing