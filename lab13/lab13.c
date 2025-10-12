#include <stdio.h>

void swapNumbers( int *a, int *b ) ;
void Enter( int *a, int *b ) ;
void PrintbeforeSwap( int a, int b ) ;
void PrintafterSwap( int a, int b ) ;

int main(){

    int num1 , num2 ;
    int *ptr1 = &num1 ;
    int *ptr2 = &num2 ;

    Enter( ptr1, ptr2 ) ;
    PrintbeforeSwap( num1, num2 ) ;
    swapNumbers( ptr1, ptr2 ) ;
    PrintafterSwap( num1, num2 ) ;

    return 0 ;
}//end main

void swapNumbers( int *a, int *b ) {
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}//end swapNumbers

void Enter( int *a, int *b ) {
    printf( "Enter num1 :\n") ;
    scanf( "%d", a) ;
    printf( "Enter num2 :\n") ;
    scanf( "%d", b ) ;
}//end Enter

void PrintbeforeSwap( int a, int b ) {
    printf( "Before swap(num1 & num2) : %d, %d\n", a, b ) ;
}//end PrintbeforeSwap

void PrintafterSwap( int a, int b ) {
    printf( "After swap(num1 & num2) : %d, %d\n", a, b ) ;
}//end PrintafterSwap

//Flowchart : https://drive.google.com/file/d/1XVWzbGP9Ss2AicXsZnXDEdMhUPACp1YY/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1UgHFGwqzFX_R86GMiRxk_LSsjwiGPXwtGSVUhIKzu5M/edit?usp=sharing