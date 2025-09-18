#include <stdio.h>

int main() {
    int n, i, j;                                    // ประกาศตัวแปร n สำหรับขนาดอาเรย์, i/j เป็นตัวนับลูป

    printf("Enter N : ");  
    if (scanf("%d", &n) != 1) {                     // ตรวจสอบการป้อนค่า ต้องเป็นตัวเลขเท่านั้น
        printf("ให้กรอกเฉพาะตัวเลขเท่านั้น\n");          
        return 0;
    }// End if

    if (n <= 0) {                                   // ถ้า N น้อยกว่าหรือเท่ากับ 0 ไม่สามารถสร้างอาเรย์ได้
        printf("N ต้องมากกว่า 0\n");   
        return 0;   
    }// End if

    int a[n];                                       // อาเรย์เก็บตัวเลขที่ผู้ใช้ป้อน
    int isprime[n];                                 // อาเรย์เก็บสถานะ (1 = prime, 0 = not prime)

    for (i = 0; i < n; i++) {                       // ลูปรับค่าทีละตำแหน่ง
        printf("Enter value[%d] : ", i);            // แสดงข้อความบอก index
        if (scanf("%d", &a[i]) != 1) {              // รับค่าเข้าสู่อาเรย์ a[i]
            printf("ให้กรอกเฉพาะตัวเลขเท่านั้น\n");      // ถ้าป้อนไม่ใช่ตัวเลข
            return 0;
        }// End if

        if (a[i] < 2) {                             // ถ้าเลขน้อยกว่า 2 ไม่ใช่จำนวนเฉพาะ เพราะจำนวนเฉพาะเริ่มที่ 2
            isprime[i] = 0;                         // กำหนดว่าไม่เป็น prime
        } else {
            for (j = 2; j < a[i]; j++) {            // ตรวจสอบตัวหารตั้งแต่ 2 จนถึง (a[i]-1)
                if (a[i] % j == 0) {                // ถ้ามีตัวหารลงตัว
                    isprime[i] = 0;                 // ไม่ใช่ prime
                    break; 
                }// End if
            }// End for

            if (j == a[i]) {                        // ถ้าไม่มีตัวหารเลย (j วิ่งจนเท่ากับ a[i])
                isprime[i] = 1;                     // เป็น prime
            }// End if
        }// End else
    }// End for

    printf("Index: ");   
    for (i = 0; i < n; i++) {                       // วนลูปพิมพ์ index
        printf("%d", i);                            // พิมพ์ค่าของ index
        if (i != n - 1) printf("  ");               // เว้นวรรค 2 ช่องถ้าไม่ใช่ตัวสุดท้าย
    }// End for
    printf("\n");

    printf("Array: ");                              
    for (i = 0; i < n; i++) {                       // วนลูปพิมพ์ค่าในอาเรย์
        if (isprime[i] == 1) {                      // ถ้าเป็นจำนวนเฉพาะ
            printf("%d", a[i]);                     // แสดงค่าตัวเลขที่อาเรย์เก็บไว้
        } else {
            printf("#");                            // ถ้าไม่ใช่ prime ให้พิมพ์ #
        }// End if
        if (i != n - 1) printf("  ");               // เว้นวรรค 2 ช่องถ้าไม่ใช่ตัวสุดท้าย
    }// End for

    printf("\n");

    return 0;
}// End main
