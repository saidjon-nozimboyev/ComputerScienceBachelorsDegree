#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Please enter array size: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = ((rand() % 2001) - 1000);
    }
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    float elapse_time = ((float)(end - start));
    // print each elemt of the array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken: %.3f\n", elapse_time);
}