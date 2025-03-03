#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        int n;
        printf("Please enter number %d: ", i);
        scanf("%d", &n);
        sum += n;
    }
    printf("Sum is: %d\n", sum);
    printf("Average is: %.3f", (float)sum / 10.0);
}