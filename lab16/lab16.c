#include <stdio.h>

int main() {

    int a[] = { 15, 7, 25, 3, 73, 32, 45} ;
    int n = 7, i, j, temp ;

    printf( "Old Series : " ) ;

    for( i = 0; i < n; i++ ) {
    printf( "%d%s", a[i], (i < n-1) ? ", " : "" ) ;
    }//end for

    printf( "\n" ) ;
    
    for( i = 0; i < n; i++ ) {
        for( j = i + 1; j < n; j++ ) {
            if( a[i] > a[j] ) {
                temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp ;
            }//end if
        }//end for
    }//end for

    printf( "New Series : " ) ;

    for( i = 0; i < n; i++ ) {
    printf( "%d%s", a[i], (i < n-1) ? ", " : "" ) ;
    }//end for
    printf( "\n" ) ;

    for( i = 0; i < n; i++ ) {
        if( a[i] == 32 ) {
            printf( "Pos of 32 : %d\n", i ) ;
        }//end if
    }//end for

    return 0 ;
}//end main

//Flowchart : https://drive.google.com/file/d/17fSdwb-v7J9_gw4qZO-AKTt4IolKdN_X/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1_TZ3PFDpPGqq1W7nn8Ak2uGnquwmIdS2LssMo46gL9U/edit?usp=sharing