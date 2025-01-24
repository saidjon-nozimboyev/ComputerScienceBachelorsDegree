#include <stdio.h>

int main()
{
    int n=125;
    printf("Please enter number: ");
    scanf("%i", &n);
    int digit_counter = 0;
    while (n != 0)
    {
        n /= 10; // n = n / 10
        digit_counter++; // digit_counter = digit_counter +1
    }
    printf("The numnber of digits: %i", digit_counter);

}

// 125 / 10 = 12
// 12 / 10 = 1
// 1 / 10 = 0

// 1652 / 10 = 165
// 165 / 10 = 16
// 16 / 10 = 1
// 1 / 10 = 0