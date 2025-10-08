#include <stdio.h>

int main() {
    char Name[50] ;
    int  Age = 0 ;
    printf( "Enter your name: " ) ;
    scanf( "%s", Name ) ;

    printf( "Enter your age: " ) ;
    scanf( "%d", &Age ) ;
    printf( "- - - - - -\n" ) ;
    printf( "Hello %s \n", Name ) ; 
    printf( "Age = %d\n", Age ) ; 
 
    return 0 ;  
}

//Debug sheet : https://docs.google.com/spreadsheets/d/1Z4qheAnPLyaCdjV-d3AmaE9LgnulQdEkjzsf-ZgwpJs/edit?gid=498912388#gid=498912388
//Flowchart : https://drive.google.com/file/d/18Yo3ZUALi-tMeM4DTV__apUT8BlkeYqn/view?usp=sharing