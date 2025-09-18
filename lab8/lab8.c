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

    switch( position ) {           // ตรวจสอบตำแหน่งงานเพื่อกำหนดเงินเดือนพื้นฐาน
        case 1 :                   // Junior
            baseSalary = 20000 ;   // เงินเดือนพื้นฐาน 20,000
            break ;
        case 2 :                   // Mid-Level
            baseSalary = 35000 ;   // เงินเดือนพื้นฐาน 35,000
            break ;
        case 3 :                   // Senior
            baseSalary = 50000 ;   // เงินเดือนพื้นฐาน 50,000
            break ;
        default :                               // ป้อนค่าอื่นที่ไม่ถูกต้อง
            printf( "ตำแหน่งงานไม่ถูกต้อง!\n" ) ;   // แสดงข้อความ error
            return 1 ;
    }

    if( years < 1 ) {                          // ถ้าประสบการณ์น้อยกว่า 1 ปี
        bonus = 0 ;                            // ไม่มีโบนัส
    } else if( years >= 1 && years <= 3 ) {    // ถ้ามีประสบการณ์ 1–3 ปี
        bonus = 0.10 * baseSalary ;            // โบนัส 10% ของเงินเดือนพื้นฐาน
    } else if( years >= 4 && years <= 5 ) {    // ถ้ามีประสบการณ์ 4–5 ปี
        bonus = 0.15 * baseSalary ;            // โบนัส 15% ของเงินเดือนพื้นฐาน
    } else {                                   // ถ้ามีประสบการณ์มากกว่า 5 ปี
        bonus = 0.20 * baseSalary ;            // โบนัส 20% ของเงินเดือนพื้นฐาน
    }

    if( projects > 5 ) {                       // ถ้าทำโปรเจกต์มากกว่า 5 งาน
        specialBonus = 0.05 * baseSalary ;     // ได้โบนัสพิเศษเพิ่ม 5% ของเงินเดือนพื้นฐาน
    }

    netSalary = baseSalary + bonus + specialBonus ;   // คำนวณเงินเดือนสุทธิ = เงินเดือนพื้นฐาน + โบนัส + โบนัสพิเศษ

    printf( "\n--- รายงานเงินเดือน ---\n" ) ;
    printf( "Base Salary: %d THB\n", baseSalary ) ;
    printf( "Experience Bonus: %d THB\n", bonus ) ;
    printf( "Special Bonus: %d THB\n", specialBonus ) ;
    printf( "Net Salary: %d THB\n", netSalary ) ;

    return 0 ;
}//end main