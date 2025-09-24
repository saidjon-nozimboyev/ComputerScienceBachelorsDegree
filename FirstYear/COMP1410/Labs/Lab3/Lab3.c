#include <stdio.h>

int Recursion_Original(int num);
int Recursion_Reverse(int num);
void Iterate_Original(int num);
void Iterate_Reverse(int num);

int main()
{
    int num;
    printf("Please enter number: ");
    scanf("%d", &num);
    printf("Testing Iterate Original: ");
    Iterate_Original(num);
    printf("\n");

    printf("Testing Iterate Reverse: ");
    Iterate_Reverse(num);
    printf("\n");
    printf("\n");

    printf("Testing Recursion Reverse: ");
    Recursion_Reverse(num);
    printf("\n");

    printf("Testing Recursion Original: ");
    Recursion_Original(num);
    printf("\n");
}

int Recursion_Reverse(int num)
{
    if (num == 0)
        return 1;
    printf("%d ", num % 10);
    num = num / 10;
    return Recursion_Reverse(num);
}

int Recursion_Original(int num)
{
    if (num == 0)
        return 1;
    int temp = num % 10;
    num = num / 10;
    Recursion_Original(num);
    printf("%d ", temp);
}

void Iterate_Original(int num)
{
    int reverse = 0;
    while (num != 0)
    {
        reverse = reverse * 10 + (num % 10);
        num /= 10;
    }
    while (reverse != 0)
    {
        printf("%d ", reverse % 10);
        reverse /= 10;
    }
}
void Iterate_Reverse(int num)
{
    while (num != 0)
    {
        printf("%d ", num % 10);
        num /= 10;
    }
}