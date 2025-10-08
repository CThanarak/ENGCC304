#include <stdio.h>

int main() {
    char id[10] ;
    int  hrs= 0 ;
    float salary = 0 ;

    printf( "Input the Employees ID(Max. 10 chars): " ) ;
    scanf( "%s", id ) ;

    printf( "Input the working hrs: " ) ;
    scanf( "%d", & hrs ) ;

    printf( "Salary amount/hr: " ) ;
    scanf( "%f", & salary ) ;

    printf( "- - - - - -\n" ) ;
    printf( "Expected Output:  \n" ) ;
    printf( "Employee ID: %s \n", id ) ;
    printf( "Salary = U$ %.2f\n", hrs * salary ) ; 
 
    return 0 ;  
}//end main

//Debug : https://docs.google.com/spreadsheets/d/11DJ-HqsQA9u2CSPDB3lsSBNdn8fEuBZMt-unclNGyIY/edit?usp=sharing
//Flowchart : https://drive.google.com/file/d/1kXm7UwtJVpdgl97k4x7nIZ1usIdVx3q9/view?usp=sharing