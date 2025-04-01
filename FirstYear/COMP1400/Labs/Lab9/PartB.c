#include <stdio.h>

long long fact(int n);

int main()
{
    int n;
    printf("Please enter number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %lld", n, fact(n));
}

long long fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}