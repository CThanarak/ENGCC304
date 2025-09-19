#include <stdio.h>

int power( int base, int exp ) {                  // ฟังก์ชันยกกำลัง
    int result = 1 ;
    for ( int i = 0 ; i < exp ; i++ ) {
        result *= base ;                         // คูณซ้ำไปเรื่อย ๆ ตามค่าของ exp
    } // End for
    return result ;                              // คืนค่าผลลัพธ์ที่ได้จากการยกกำลัง
} // End power

int isArmstrong( int num ) {                      // ฟังก์ชันตรวจสอบ Armstrong Number
    int original = num, remainder, n = 0 ;       // original คือ เลขเดิมที่รับเข้ามา, remainder คือ หลักสุดท้ายของเลข, n คือ จำนวนหลัก
    int result = 0 ;

    int temp = num ;                             // temp คือ จำนวนที่เราจะใช้ในการนับหลัก

    while ( temp != 0 ) {    
        temp /= 10 ;                             // หาร 10 เพื่อเลื่อนตัวเลขไปเรื่อย ๆ
        n++ ;                                    // ทุกครั้งที่หารได้ก็นับเป็นอีก 1 หลัก
    } // End while

    temp = num ;
    while ( temp != 0 ) {
        remainder = temp % 10 ;                  // เอาหลักสุดท้ายของตัวเลข
        result += power( remainder, n ) ;          // ยกกำลัง n แล้วบวกเข้ากับผลรวม
        temp /= 10 ;                             // ตัดหลักสุดท้ายทิ้ง (เลื่อนไปหลักถัดไป)
    } // End while 

    return result == original ;                  // ถ้าผลรวมที่ได้เท่ากับเลขเดิม เป็น Armstrong Number
} // End isArmstrong

int main() {
    int num ;

    printf("Enter Number: ") ;
    scanf("%d", &num) ;                          // รับค่าจากผู้ใช้

    if (isArmstrong(num)) {
        printf("Pass.\n") ;                      // ถ้าใช่ Armstrong Number
    } else {
        printf("Not Pass.\n") ;                  // ถ้าไม่ใช่ Armstrong Number
    }

    return 0;
} // End main
