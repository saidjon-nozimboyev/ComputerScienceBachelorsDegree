#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    short IsPrime = 1;
    printf("Please enter number: ");
    scanf("%d",&n);

    if (n < 2)
    {
        printf("Number is not Prime");
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
           IsPrime = 0;
           break;
        }
    }
    
    if (IsPrime)
        printf("Number is prime");
    else 
        printf("Number is not prime");
}