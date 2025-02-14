#include <stdio.h>

int main()
{
    int a,b;
    printf("Please enter two values:");
    scanf("%i %i", &a, &b);
    printf("Remainder if %i by %i is %i",a,b,a%b);
    return 0;
}