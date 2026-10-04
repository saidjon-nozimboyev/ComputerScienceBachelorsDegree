#include <stdio.h>

int main()
{
    int n;
    printf("Please enter number of rows: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) { // 6 - 0 - 1 
            printf(" ");
        }

        for (int j = 0; j < (2 * i + 1); j++) { // 0*2 + 1  1*2+1
            printf("*");
        }

        printf("\n");
    }

}