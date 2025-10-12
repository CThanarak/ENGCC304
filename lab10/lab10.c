#include <stdio.h>
#include <string.h>

int main() {
    int num, sum = 0 ;
    char s[20] ;
    printf( "Enter Number: " ) ;
    scanf( "%d", &num ) ;

    sprintf( s, "%d", num ) ;
    int n = strlen(s) ;

    for ( int i = 0; s[i]; i++ ) {
        int d = s[i] - '0', p = 1 ;
        for ( int j = 0; j < n; j++ ) p *= d ;
        sum += p ;
    }

    printf( sum == num ? "Pass.\n" : "Not Pass.\n" ) ;
    return 0 ;
}
