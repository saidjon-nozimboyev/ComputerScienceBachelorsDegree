#include <stdio.h>
#include <stdlib.h>

int *createSquaresArray(int n);
void printArray(int *arr, int n);

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *squares = createSquaresArray(n);

    printArray(squares, n);

    free(squares);
    return 0;
}

int *createSquaresArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * (i + 1);
    }

    return arr;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
