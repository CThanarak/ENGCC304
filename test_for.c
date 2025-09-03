#include <stdio.h>

int main() {

    int n, i, j ;

    printf( "Enter Number : " ) ;
    if(scanf("%d", &n) != 1){
        printf( "ให้กรอกเฉพาะตัวเลขเท่านั้น\n" ) ;
        return 0 ;
    }

    if ( n < 2 ) {
        printf( "ไม่มีจำนวนเฉพาะในช่วง 1 ถึง %d\n" , n ) ;
        return 0;
    }

    printf( "จำนวนเฉพาะ : " );
    for (i = n; i >= 2; i--) {        // ตรวจทุกจำนวนจาก n ถึง 2 (2 เป็นจำนวนเฉพาะตัวแรก)

        for ( j = 2; j < i; j++ ){   // ตรวจว่ามีตัวหารอื่นไหมนอกจาก 1 กับตัวมันเอง
            if ( i % j == 0 ){
                break ;              //ถ้าเจอตัวหารอื่นแล้วให้หยุดตรวจ
            }//end if
        }//end for

        if ( j == i ){              //ถ้าไม่มีตัวหารอื่นนอกจากตัวมันเองคือจำนวนเฉพาะ
            printf( "%d " , i ) ;   
        }//end if

    }//end for

    printf( "\n" ) ;
    return 0 ;
}//end main
