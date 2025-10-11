#include <stdio.h>
#include <string.h>

struct Book {
    int ID ;
    char Title[100] ;
    char Author[100] ;
    int Year ;
} ; //end struct

void addBook( struct Book books[], int *count ) ;
void searchBook( struct Book books[], int count, char title[] ) ;
void displayBooks( struct Book books[], int count ) ;


int main(){

    struct Book books[100] ;
    int count = 0 ;
    int choice ;
    char title[100] ;

    do{
        printf( "\n--- Library Management System ---\n" ) ;
        printf( "1. Add new book\n" ) ;
        printf( "2. Search book by title\n" ) ;
        printf( "3. Display all books\n" ) ;
        printf( "4. Exit\n" ) ;
        printf( "Enter your choice: " ) ;
        scanf( "%d", &choice ) ;

        if( choice == 1 ){
            addBook( books, &count ) ;
        }//end if
        else if( choice == 2 ){
            printf( "Enter Title to Search: " ) ;
            scanf( " %[^\n]", title ) ;
            searchBook( books, count, title ) ;
        }//end else if
        else if( choice == 3 ){
            displayBooks( books, count ) ;
        }//end else if
        else if( choice == 4 ){
            printf( "Exiting program...\n" ) ;
        }//end else if
        else{
            printf( "Invalid choice! Please try again.\n" ) ;
        }//end else

    }while( choice != 4 ) ;

    return 0 ;
}//end main

void addBook( struct Book books[], int *count ){

    printf( "Enter Book ID: " ) ;
    scanf( "%d", &books[*count].ID ) ;

    printf( "Enter Title: " ) ;
    scanf( " %[^\n]", books[*count].Title ) ;           //%[^\n] ใช้เพื่อรับสตริงที่มีช่องว่าง

    printf( "Enter Author: " ) ;
    scanf( " %[^\n]", books[*count].Author ) ;

    printf( "Enter Year: " ) ;
    scanf( "%d", &books[*count].Year ) ;

    (*count)++ ;

    printf( "Book added successfully!\n" ) ;

}//end addBook

void searchBook( struct Book books[], int count, char title[] ){

    int i ;
    int found = 0 ;

    for( i = 0 ; i < count ; i++ ){
        if( strcmp( books[i].Title, title ) == 0 ){
            printf( "\n--- Book Found ---\n" ) ;
            printf( "Book ID: %d\n", books[i].ID ) ;
            printf( "Title: %s\n", books[i].Title ) ;
            printf( "Author: %s\n", books[i].Author ) ;
            printf( "Year: %d\n", books[i].Year ) ;
            found = 1 ;
        }//end if
    }//end for

    if( found == 0 ){
        printf( "Book not found.\n" ) ;
    }//end if

}//end searchBook

void displayBooks( struct Book books[], int count ){

    int i ;

    if( count == 0 ){
        printf( "No books available.\n" ) ;
    }//end if
    else{
        printf( "\n--- All Books ---\n" ) ;
        for( i = 0 ; i < count ; i++ ){
            printf( "Book ID: %d\n", books[i].ID ) ;
            printf( "Title: %s\n", books[i].Title ) ;
            printf( "Author: %s\n", books[i].Author ) ;
            printf( "Year: %d\n\n", books[i].Year ) ;
        }//end for
    }//end else

}//end displayBooks

//Flowchart : https://drive.google.com/file/d/1F25N-0TOR-6vFARbC6Dj5xC5DqxK-h76/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1f2vKuk4XAI3fgv6BeRMgDAW8uSc8wifoXqcx__weNQI/edit?usp=sharing