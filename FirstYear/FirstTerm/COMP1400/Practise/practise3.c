#include <stdio.h>

int main()
{ 
    int a, b, c, x;
    printf("Please enter values for a b c x: ");
    scanf("%d %d %d %d", &a, &b, &c, &x);
    printf("Q(%d) = %d * %d ^ 2 + %d * %d + %d = %d", x, a, x, b, x, c, a * (x * x) + b * x + c);
}