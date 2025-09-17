#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num);
void Prime_Factors(int num);

void main()
{
    int num;
    printf("Please enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Please enter a positive integer\n");
        return;
    }

    Prime_Factors(num);

    // printf("The prime factors of %d are: ", num);
    //  for (int i = 2; i <= num; i++)
    //  {
    //      if (isPrime(i)) // check for a prime number
    //      {
    //          while (num % i == 0) // dividing to its prime factors
    //          {
    //                  printf("%d ", i);
    //                  num /= i;
    //          }
    //      }
    //  }
}

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void Prime_Factors(int num)
{
    printf("The prime factors of %d: ", num);

    for (int i = 2; i <= num; i++)
    {
        if (isPrime(i)) // check for a prime number
        {
            while (num % i == 0) // dividing to its prime factors
            {
                printf("%d ", i);
                num /= i;
            }
        }
    }
}