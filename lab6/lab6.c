#include <stdio.h>

int n = 0;

int main() {
    
    printf( "Enter Value: " ) ;

    if ( scanf( "%d", &n ) != 1 ) {
        printf( "Please Enter number only\n" ) ;
        return 1 ;
    }//end if

    if( n % 2 != 0) {
        printf( "Series: " );
        for ( int i = 1; i <= n; i += 2 ) {
            printf( "%d ", i ) ;
        }
    }else{
        printf( "Series: " ) ;
        for ( int i = n ; i >= 0 ; i -= 2 ) {
            printf( "%d ", i );
        }
    }//end if

    printf( "\n" ) ;
    return 0 ;
}//end main