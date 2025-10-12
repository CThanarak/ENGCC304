#include <stdio.h>
#include <string.h>

int inputNumber();
int power( int base, int exp ) ;
int isArmstrong( int num ) ;
void showResult( int num, int isArm ) ;

int main() {
    int num = inputNumber() ;
    int check = isArmstrong(num) ;
    showResult( num, check ) ;          
    return 0 ;
}// End main

int inputNumber() {
    int n ;
    printf( "Enter Number: " ) ;
    scanf( "%d", &n ) ;
    return n ;
}// End inputNumber

int power( int base, int exp ) {
    int result = 1 ;
    for (int i = 0 ; i < exp; i++ ) {
        result *= base ;
    }
    return result ;
}// End power

int isArmstrong( int num ) {
    char str[20] ;
    sprintf( str, "%d", num ) ;
    int n = strlen( str ) ;

    int result = 0 ;
    for ( int i = 0 ; i < n; i++ ) {
        int digit = str[i] - '0' ;
        result += power( digit, n ) ;
    }// End for

    return result == num ;
}// End isArmstrong

void showResult( int num, int isArm ) {
    if (isArm) {
        printf( "%d is an Armstrong number.\n", num ) ;
        printf( "Pass.\n" );
    } else {
        printf( "%d is not an Armstrong number.\n", num ) ;
        printf( "Not Pass.\n" ) ;
    }// End if
}// End main

//Flowchart : https://drive.google.com/file/d/1ba1wJe4b_rNVQ4tjV3tJi1p8OcTME4AA/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1ZsbDRCG94QgdBYijshNNdR8neTAcYeebOOe0mIxrPtg/edit?usp=sharing