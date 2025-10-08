#include <stdio.h>

long daytoseconds(int day) {
    return (long)day * 24 * 60 * 60;
}//end daystoseconds

int main() {
    int day ;
    printf( "Input Days : " ) ;
    scanf( "%d", &day ) ;
    printf( "%d days = %ld seconds\n", day, daytoseconds(day) ) ;
    return 0 ;
}//end main

//Debug sheet : https://docs.google.com/spreadsheets/d/1isy_FWzxCvI9VjYG4QPVcBzbGOLXfGKDQxlWLHEuhqA/edit?usp=sharing
//Flowchart : https://drive.google.com/file/d/1k6a0bNSLlz7yDt_sYf4RSXlRkjjJ8la6/view?usp=sharingß