#include <stdio.h>

int main() {
    char filename[100] ;
    FILE *fp ;
    char word[100] ;
    int count = 0 ;

    printf("Enter file name: ") ;
    scanf( "%s", filename ) ;

    fp = fopen( filename, "r" ) ;
    if ( fp == NULL ) {
        printf( "File not found.\n" ) ;
        return 1 ;
    }//end if

    while ( fscanf( fp, "%s", word ) == 1 ) {
        count++ ;
    }//end while

    fclose( fp ) ;
    printf( "Total number of words in '%s' : %d words\n", filename, count ) ;

    return 0 ;
}//end main

//Flowchart: https://drive.google.com/file/d/1_ZlqXp4ggNUVywKvCn_qeUwmHlCXe4Td/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1dFtM07TL2JnqJvDuk5TVNQX6933wzIf64W8Ncft7rFo/edit?usp=sharing