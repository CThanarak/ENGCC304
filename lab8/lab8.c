#include <stdio.h>

int main() {
    int position, years, projects;
    int baseSalary = 0, bonus = 0, specialBonus = 0, netSalary = 0 ;

    printf( "Position (1=Junior, 2=Mid-Level, 3=Senior): " ) ;
    scanf( "%d", &position ) ;

    printf( "Years of Experience: " ) ;
    scanf( "%d", &years ) ;

    printf( "Number of Projects Completed this Year: " ) ;
    scanf( "%d", &projects ) ;

    switch( position ) {  
        case 1 :
            baseSalary = 20000 ;
            break ;
        case 2 :
            baseSalary = 35000 ;
            break ;
        case 3 :
            baseSalary = 50000 ;
            break ;
        default :
            printf( "ตำแหน่งงานไม่ถูกต้อง!\n" ) ;
            return 1 ;
    }//end switch

    if( years < 1 ) {
        bonus = 0 ;
    } else if( years >= 1 && years <= 3 ) {
        bonus = 0.10 * baseSalary ;
    } else if( years >= 4 && years <= 5 ) {
        bonus = 0.15 * baseSalary ;
    } else {
        bonus = 0.20 * baseSalary ;
    }//end if-else

    if( projects > 5 ) {
        specialBonus = 0.05 * baseSalary ;
    }//end if

    netSalary = baseSalary + bonus + specialBonus ;

    printf( "\n--- รายงานเงินเดือน ---\n" ) ;
    printf( "Base Salary: %d THB\n", baseSalary ) ;
    printf( "Experience Bonus: %d THB\n", bonus ) ;
    printf( "Special Bonus: %d THB\n", specialBonus ) ;
    printf( "Net Salary: %d THB\n", netSalary ) ;

    return 0 ;
}//end main