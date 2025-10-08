#include <stdio.h>

int main() {
    float h = 0 ;
    float w = 0 ;
    float area = 0;

    printf( "Enter H : " ) ;
    scanf( "%f", &h ) ;

    printf( "Enter W: " ) ;
    scanf( "%f", &w ) ;

    area = ( h * w ) / 2 ;

    printf( "Area = %.1f\n", area ) ;

    return 0;
}//end main

//Debug : https://docs.google.com/spreadsheets/d/1_BcxAFvN4ySQmBOnkfN1PFLuHv43kSGk3RYEgrZ1yrk/edit?usp=sharing
//Flowchart : https://drive.google.com/file/d/1uprO-wHcgb1AmcUop8rFx5rQBHl4wvCH/view?usp=sharing