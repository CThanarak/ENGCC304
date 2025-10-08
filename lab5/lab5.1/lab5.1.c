#include <stdio.h>

int main() {
    char id[10] ;
    int  hrs= 0 ;
    float salary = 0 ;

    printf( "Input the Employees ID(Max. 10 chars): " ) ;
    if (scanf( "%s", id ) != 1) {
        printf( "Invalid input. Please enter a valid ID.\n" );
        return 1 ;
    }//end if

    printf( "Input the working hrs: " ) ;
    if (scanf( "%d", & hrs ) != 1) {
        printf( "Invalid input. Please enter a valid number of hours.\n" );
        return 1 ;
    }//end if

    printf( "Salary amount/hr: " ) ;
    if (scanf( "%f", & salary ) != 1){
        printf( "Invalid input. Please enter a valid salary amount.\n" );
        return 1 ;
    }//end if
    
    printf( "- - - - - -\n" ) ;
    if (hrs > 0 && salary > 0) {
        salary = hrs * salary;
        printf("\nExpected Output:\n");
        printf("Employees ID = %s\n", id);
        printf("Salary = U$ %.2f\n", salary);
    } else {
        printf("\nError: Invalid input. Working hours and rate must be positive numbers.\n");
    }//end if
    return 0 ;  
}//end main

//Debug : https://docs.google.com/spreadsheets/d/1kst26gHPXukD8YxO4vYCmZA9LGUkSdVsPIU0BG_jL1Q/edit?usp=sharing
//Flowchart : https://drive.google.com/file/d/1o38mEMQ7tf880xqjmPJQwly_RBULXfUl/view?usp=sharing