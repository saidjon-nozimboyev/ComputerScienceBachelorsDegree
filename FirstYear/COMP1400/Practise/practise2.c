#include <stdio.h>

int main()
{
    // int a, b, c, x;
    // printf("Please enter values for a b c x: ");
    // scanf("%d %d %d %d", &a, &b, &c, &x);
    // printf("Q(%d) = %d * %d ^ 2 + %d * %d + %d = %d", x, a, x, b, x, c, a * (x * x) + b * x + c);

    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int sum1 = 0;
    int sum2 = 0;
    int digit1 = 0;
    int digit2 = 0;

    while (num1 !=0)
    {
        int dg = num1 % 10;
        sum1 = sum1 + dg;
        digit1++;
        num1 /= 10;
    }

    while (num2 !=0)
    {
        int dg = num2 % 10;
        sum2 = sum2 + dg;
        digit2++;
        num2 /= 10;
    }
    
    if (digit1 != digit2)
        printf("Numbers have different lenght\n");
    if (sum1 != sum2)
        printf("Numbers are not equal\n");
    else
        printf("Numbers are equal");
}