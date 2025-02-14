#include <stdio.h>

int main()
{
    int a, b, c, max, min;
    printf("Please enter 1st number: ");
    scanf("%i", &a);

    printf("Please enter 2nd number: ");
    scanf("%i", &b);

    printf("Please enter 3rd number: ");
    scanf("%i", &c);

    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }

    min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }

    printf("Max is: %i\n", max);
    printf("Min is: %i\n", min);

    return 0;
}