#include <stdio.h>

int Sum_Of_Digits(int num);

int main()
{
    int num;
    printf("Please enter number: ");
    scanf("%d", &num);
    int ans = Sum_Of_Digits(num);
    printf("Sum of digits is: %d", ans);
}

int Sum_Of_Digits(int num) {
    if (num == 0)
        return 0;
    return (num % 10) + Sum_Of_Digits(num / 10); 

    // last digit + sum of remaining digits

    // 1234 % 10 = 4 + sumOfDigits(123)
    // 123 % 10 = 3 + sumOfDigits(12)
    // 12 % 10 = 2 + sumOfDigits(1)
    // 1 % 10 = 1 + sumOfDigits(0)
    // num == 0
    // return 0 and goes back
}