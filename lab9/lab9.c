#include <stdio.h>

int isPrime( int num ) ;
int inputArray( int a[], int n ) ;
void printArrays( int a[], int isprime[], int n ) ;

int main() {
    int n;
    printf( "Enter N : " ) ;
    if (scanf( "%d", &n) != 1 ) {
        printf( "ให้กรอกเฉพาะตัวเลขเท่านั้น\n" ) ;
        return 0 ;
    }//end if

    if (n <= 0) {
        printf( "N ต้องมากกว่า 0\n" ) ;
        return 0 ;
    }//end if

    int a[n] ;
    int isprime[n] ;

    if (!inputArray(a, n)) return 0 ;

    for ( int i = 0; i < n; i++ ) {
        isprime[i] = isPrime(a[i]) ;
    }//end for

    printArrays( a, isprime, n ) ;

    return 0 ;
}//end main

int isPrime( int num ) {
    if ( num < 2 ) return 0 ;
    for ( int j = 2; j < num; j++ ) {
        if ( num % j == 0 )
            return 0 ;
    }
    return 1 ; 
}//end of isPrime

int inputArray( int a[], int n ) {
    for ( int i = 0; i < n; i++ ) {
        printf( "Enter value[%d] : ", i ) ;
        if (scanf( "%d", &a[i]) != 1 ) {
            printf( "ให้กรอกเฉพาะตัวเลขเท่านั้น\n" ) ;
            return 0 ;
        }
    }
    return 1 ;
}//end of inputArray

void printArrays( int a[], int isprime[], int n ) {
    printf( "Index: " ) ;
    for ( int i = 0; i < n; i++ ) {
        printf( "%d", i ) ;
        if ( i != n - 1 ) 
        printf( "  " ) ;
    }//end for
    printf( "\n" ) ;

    printf( "Array: " ) ;
    for ( int i = 0; i < n; i++ ) {
        if ( isprime[i] == 1 )
            printf( "%d", a[i] ) ;
        else
            printf( "#" ) ;
        if ( i != n - 1 ) printf( "  " ) ;
    }//end for
    printf( "\n" ) ;
}//end of printArrays


//Flowchart : https://drive.google.com/file/d/1PaTuZCfbUTKcVskS8Udwgtmb2Fty_5nx/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1ChU6rFiffE68_t5jBppZAfGIcK2D4Op69akJbFn6AXA/edit?usp=sharing