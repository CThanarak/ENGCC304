#include <stdio.h>

int power( int base, int exp ) {
    int result = 1 ;
    for ( int i = 0 ; i < exp ; i++ ) {
        result *= base ;
    } // End for
    return result ;
} // End power

int isArmstrong( int num ) {
    int original = num, remainder, n = 0 ;
    int result = 0 ;

    int temp = num ;

    while ( temp != 0 ) {    
        temp /= 10 ;
        n++ ;
    } // End while

    temp = num ;
    while ( temp != 0 ) {
        remainder = temp % 10 ;
        result += power( remainder, n ) ;
        temp /= 10 ;
    } // End while 

    return result == original ;
} // End isArmstrong

int main() {
    int num ;

    printf("Enter Number: ") ;
    scanf("%d", &num) ;

    if (isArmstrong(num)) {
        printf("Pass.\n") ;
    } else {
        printf("Not Pass.\n") ;
    }

    return 0;
} // End main
