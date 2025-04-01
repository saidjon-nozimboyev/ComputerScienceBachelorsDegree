#include <stdio.h>
#include <math.h>

long long decimalToBinary(int decimal);

int main()
{
    int n;
    printf("Please enter number: ");
    scanf("%d", &n);
    printf("%d in binary is %lld", n, decimalToBinary(n));
    return 0;
}

long long decimalToBinary(int decimal)
{
    if (decimal < 0)
        return -1;

    long long binary = 0;
    int position = 0;

    if (decimal == 0)
        return 0;

    while (decimal > 0)
    {
        binary += (decimal % 2) * (long long)pow(10, position);
        decimal /= 2;
        position++;
    }

    return binary;
}