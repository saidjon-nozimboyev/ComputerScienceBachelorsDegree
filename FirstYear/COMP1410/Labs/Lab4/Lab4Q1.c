#include <stdio.h>

void printReverseIndex(int arr[], int n);
void printReversePointer(int *arr, int n);

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printReverseIndex(arr, n);
    printReversePointer(arr, n);

    return 0;
}

void printReverseIndex(int arr[], int n)
{
    printf("Reverse (using array indexing): ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printReversePointer(int *arr, int n)
{
    printf("Reverse (using pointer arithmetic): ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}