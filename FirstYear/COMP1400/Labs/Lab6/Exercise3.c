#include <stdio.h>

int main()
{
    int n;
    printf("Please enter number of rows: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j<=i;j++)
            printf("* ");
        printf("\n");
    }
    puts(" ");
}