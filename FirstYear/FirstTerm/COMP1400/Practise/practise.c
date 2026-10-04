#include <stdio.h>

int fact(int n);

int main()
{
    int n;
    float sum = 0;
    printf("Please enter number: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        sum = sum + (1.0 / (fact(i)));
    }
    printf("Sum is %.2f", sum);
}

int fact(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}