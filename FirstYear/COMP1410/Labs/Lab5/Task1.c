#include <stdio.h>

int main()
{
    int product[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &product[i][j]);
        }
    }

    // Output values
    printf("\nThe 3x4 array is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n"); // move to next row
    }
}