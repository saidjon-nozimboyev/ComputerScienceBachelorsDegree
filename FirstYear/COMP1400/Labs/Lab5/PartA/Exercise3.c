#include <stdio.h>

int main()
{
    int year;
    printf("Please enter year: ");
    scanf("%i", &year);
    if (year % 4 == 0 || (year % 400 == 0 && year % 100 != 0))
        printf("%i is leap year", year);
    else
        printf("%i is not a leap", year);
    return 0;
}