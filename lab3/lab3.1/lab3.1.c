#include <stdio.h>

int main() {
    float H, W, Area ;

    printf( "Enter height (H): " ) ;
    scanf( "%f", &H ) ;

    printf( "Enter base (W): " ) ;
    scanf( "%f", &W ) ;

    Area = ( H * W ) / 2 ;

    printf( "Area = %.1f\n", Area ) ;

    return 0;
}//end main

//Debug : https://docs.google.com/spreadsheets/d/1_BcxAFvN4ySQmBOnkfN1PFLuHv43kSGk3RYEgrZ1yrk/edit?usp=sharing
//Flowchart : https://drive.google.com/file/d/1uprO-wHcgb1AmcUop8rFx5rQBHl4wvCH/view?usp=sharing