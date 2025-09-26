#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter N : ");  
    if (scanf("%d", &n) != 1) {
        printf("ให้กรอกเฉพาะตัวเลขเท่านั้น\n");          
        return 0;
    }// End if

    if (n <= 0) {
        printf("N ต้องมากกว่า 0\n");   
        return 0;   
    }// End if

    int a[n];
    int isprime[n];

    for (i = 0; i < n; i++) {
        printf("Enter value[%d] : ", i);
        if (scanf("%d", &a[i]) != 1) {
            printf("ให้กรอกเฉพาะตัวเลขเท่านั้น\n");
            return 0;
        }// End if

        if (a[i] < 2) {
            isprime[i] = 0;
        } else {
            for (j = 2; j < a[i]; j++) {
                if (a[i] % j == 0) {
                    isprime[i] = 0;
                    break; 
                }// End if
            }// End for

            if (j == a[i]) {
                isprime[i] = 1;
            }// End if
        }// End else
    }// End for

    printf("Index: ");   
    for (i = 0; i < n; i++) {
        printf("%d", i);
        if (i != n - 1) printf("  ");
    }// End for
    printf("\n");

    printf("Array: ");                              
    for (i = 0; i < n; i++) {
        if (isprime[i] == 1) {
            printf("%d", a[i]);
        } else {
            printf("#");
        }// End if
        if (i != n - 1) printf("  ");
    }// End for

    printf("\n");

    return 0;
}// End main
