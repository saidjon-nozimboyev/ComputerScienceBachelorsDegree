#include <stdio.h>

int main()
{
    long long isbn;
    printf("Please enter ISBN: ");
    scanf("%lld", &isbn);

    // Get the number of digits
    int digit_count = 0;
    long long reverse = 0;
    while (isbn != 0)
    {
        short digit = isbn % 10;
        reverse = reverse * 10 + digit;
        isbn /= 10;
        digit_count++;
    }
    printf("Digit count: %i\n", digit_count);
    printf("Reversed: %lld\n", reverse);
    // *1 when digit_count % 2 == 1
    // *3 when diigit_count % 2 == 0
    int sum = 0;
    if (digit_count % 2 == 0)
    {
        short switcher = 1;
        while (reverse != 0)
        {
            short digit = reverse % 10;
            if (switcher)
            {
                sum += digit * 1;
                switcher = 0;
            }
            else
            {
                sum += digit * 3;
                switcher = 1;
            }
            reverse /= 10;
        }
        printf("Sum is: %i\n", sum);
        printf("Check digit is: %i", (10 - (sum % 10)));
    }
    else if (digit_count % 2 == 1)
    {
        short switcher = 1;
        while (reverse != 0)
        {
            short digit = reverse % 10;
            if (switcher)
            {
                sum += digit * 1;
                switcher = 0; 
            }
            else
            {
                sum += digit * 3;
                switcher = 1; 
            }
            reverse /= 10;
        }
        
        printf("Sum is: %i\n", sum);
        printf("Check digit is: %i", (10 - (sum % 10)));
        // deleted comment test
        
    }
}