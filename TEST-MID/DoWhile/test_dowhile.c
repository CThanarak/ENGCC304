#include <stdio.h>

int main() {

    int n = 0 ;
    int i = 0 ; 
    int j = 0 ;

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

    i = n;
    do
    {
        j = 2 ;
        do
        {
            if ( i % j == 0 ){
                break ;              //ถ้าเจอตัวหารอื่นแล้วให้หยุดตรวจ
            }//end if
            j++ ;
        } while ( j < i);

        if ( j == i ){              //ถ้าไม่มีตัวหารอื่นนอกจากตัวมันเองคือจำนวนเฉพาะ
            printf( "%d " , i ) ;   
        }//end if
        i-- ;

    } while (i >= 2);
    
    

    printf( "\n" ) ;
    return 0 ;
}//end main
