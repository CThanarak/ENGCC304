#include <stdio.h>

int findMax( int arr[], int n ) ;
int findMin( int arr[], int n ) ;

int main() {
    int arr[100] ;
    int n = 0 ;

    printf( "Enter value:\n" ) ;
    while ( scanf( "%d", &arr[n] ) == 1 ) {
        n++ ;
        if ( getchar() == '\n' ) break ;
    }

    printf( "Index: " ) ;
    for ( int i = 0; i < n; i++ )
        printf( "%d ", i ) ;

    printf( "\nArray: " ) ;
    for ( int i = 0; i < n; i++ )
        printf( "%d ", arr[i] ) ;

    printf( "\n\nMin : %d\n", findMin(arr, n) ) ;
    printf( "Max : %d\n", findMax(arr, n) ) ;

    return 0 ;
}//end main

int findMax(int arr[], int n) {
    int max = arr[0] ;
    for ( int i = 1; i < n; i++ )
        if ( arr[i] > max )
            max = arr[i] ;
    return max ;
}//end of findMax

int findMin( int arr[], int n ) {
    int min = arr[0] ;
    for ( int i = 1; i < n; i++ )
        if ( arr[i] < min )
            min = arr[i] ;
    return min ;
}//end of findMin

//Flowchart : https://drive.google.com/file/d/19hD4PZDuZa-wPyv5F-B7jeEnHWOAyLvK/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1ulLFBGCTwtLtZEzYmeToNVhijork6DnbheMpsPBQzIs/edit?usp=sharing