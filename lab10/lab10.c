#include <stdio.h>
#include <string.h>

int main() {
    char word[100] ;                             // สมมติว่าคำที่ป้อนจะไม่เกิน 99 ตัวอักษร
    int i, length, isPalindrome = 1 ;            // สมมติว่าเป็น Palindrome

    printf( "Enter word: " ) ;                   // รับคำจากผู้ใช้
    scanf( "%s" , word ) ;

    length = strlen( word ) ;                    // หาความยาวของคำ

    for ( i = 0 ; i < length / 2 ; i++ ) {       // ตรวจสอบแค่ครึ่งเดียวของคำเพราะจะเปรียบเทียบสองข้าง
        char left = word[i] ;                    // ตัวอักษรทางซ้าย คือ ตัวอักษรใน array ตำแหน่งที่ i
        char right = word[length - i - 1] ;      // ตัวอักษรทางขวา คือ ตัวอักษรใน array ตำแหน่งที่ (lenght ของคำ - i - 1), ลบ 1 เพราะ index เริ่มที่ 0

        if ( left >= 'A' && left <= 'Z' ) {      // ถ้าตัวอักษรทางซ้ายเป็นตัวใหญ่ (A-Z)
            left = left + 32 ;                   // นำ 32 ไปบวกเพื่อแปลงเป็นตัวเล็ก (A-Z → a-z), ASCII offset 32
        }//end if

        if ( right >= 'A' && right <= 'Z' ) { 
            right = right + 32 ;             
        }//end if

        if ( left != right ) {                    // ถ้าตัวอักษรไม่ตรงกัน
            isPalindrome = 0 ;                    // ไม่ใช่ Palindrome   
            break ;
        }// End if
    }// End for

    if ( isPalindrome )
        printf( "Pass.\n" ) ;
    else
        printf( "Not Pass.\n" ) ;

    return 0 ;
}// End main
