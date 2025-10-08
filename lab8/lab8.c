#include <stdio.h>

int calbasesalary( int position ) {
    if ( position == 1 ) 
        return 20000 ;
    else if ( position == 2 ) 
        return 35000 ;
    else if ( position == 3 ) 
        return 50000 ;
    else return 0 ;
}//end calbasesalary

int calbonus( int years, int basesalary ) {
    if ( years < 1 ) 
        return 0 ;
    else if ( years <= 3 ) 
        return 0.10 * basesalary ;
    else if ( years <= 5 ) 
        return 0.15 * basesalary ;
    else 
        return 0.20 * basesalary ;
}//end calbonus

int calspecial( int project, int basesalary ) {
    int special = 0 ;
    for ( int i = 0 ; i < project; i++ ) { 
        if ( i == 5 ) {
            special = 0.05 * basesalary ;
            break ;
        }//end if
    }//end for
    return special ;
}//end calspecial

int main() {
    int position, year, project ;
    int basesalary, bonus, special, netsalary ;

    printf( "Position (1=Junior, 2=Mid-Level, 3=Senior): " ) ;
    scanf( "%d", &position ) ;

    printf( "Years of Experience: " ) ;
    scanf( "%d", &year ) ;

    printf( "Number of Projects Completed this Year: " ) ;
    scanf( "%d", &project ) ;

    basesalary = calbasesalary( position ) ;
    if ( basesalary == 0 ) {
        printf( "ตำแหน่งงานไม่ถูกต้อง!\n" ) ;
        return 1 ;
    }//end if

    bonus = calbonus( year, basesalary ) ;
    special = calspecial( project, basesalary ) ;
    netsalary = basesalary + bonus + special ;

    printf( "\n--- รายงานเงินเดือน ---\n" ) ;
    printf( "Base Salary: %d THB\n", basesalary ) ;
    printf( "Experience Bonus: %d THB\n", bonus ) ;
    printf( "Special Bonus: %d THB\n", special ) ;
    printf( "Net Salary: %d THB\n", netsalary ) ;

    return 0 ;
}//end main

//Flowchart: https://drive.google.com/file/d/1CKzknJA8Ol7NxRDGX127EumY7aTYDG5K/view?usp=sharing
//Debug : https://docs.google.com/spreadsheets/d/1ZCAheC4T1c3T7PEUHI5gPjmhOYnUDUiExRACmXHS5QA/edit?usp=sharing