#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void move_zeros_to_end(int arr[], int n) {
    int index = 0; // Position for next non-zero element

    // Move non-zero elements forward
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the rest with zeros
    while (index < n) {
        arr[index++] = 0;
    }
}

int main() {
    int n;

    do {
        printf("Enter the number of elements (1 to 100): ");
        scanf("%d", &n);

        if (n < 1 || n > 100) {
            printf("Please enter a value between 1 and 100.\n");
        }
    } while (n < 1 || n > 100);

    int arr[n];

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    print_array(arr, n);

    move_zeros_to_end(arr, n);

    printf("Array after moving zeros to the end: ");
    print_array(arr, n);

    return 0;
}
