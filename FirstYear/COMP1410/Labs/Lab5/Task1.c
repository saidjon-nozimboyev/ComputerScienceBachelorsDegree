#include <stdio.h>

void computeRowAverage(int production[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += production[i][j];
        }
        printf("Product %d : %.1f \n", i + 1, sum / 4.0);
    }
}

int main()
{
    int product[3][4] = {{120, 135, 150, 140}, {90, 100, 95, 110}, {200,210,190, 205}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         scanf("%d", &product[i][j]);
    //     }
    // }
    computeRowAverage(product);
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ", product[i][j]);
    //     }
    //     printf("\n");
    // }
}