#include <stdio.h>

// Function prototypes
int power(int base, int exp);
int isArmstrong(int num);

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;
    int temp = num;

    // นับจำนวนหลัก
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    // คำนวณผลรวมของแต่ละหลักยกกำลังจำนวนหลัก
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main(void) {
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("Pass.\n");
    else
        printf("Not Pass.\n");

    return 0;
}
