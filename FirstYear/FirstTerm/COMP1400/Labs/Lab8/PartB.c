#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[30];
    int num, frequency = 0;
    
    srand(time(NULL));
    
    for(int i = 0; i < 30; i++) {
        arr[i] = rand() % 21;
    }
    
    printf("Enter a number between 0 and 20: ");
    scanf("%d", &num);
    
    while(num < 0 || num > 20) {
        printf("Invalid input! Please enter a number between 0 and 20: ");
        scanf("%d", &num);
    }
    
    printf("\nArray elements:\n");
    for(int i = 0; i < 30; i++) {
        printf("%d ", arr[i]);
        if(arr[i] == num) {
            frequency++;
        }
        if((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    
    printf("\nFrequency of %d in the array: %d\n", num, frequency);
    
    return 0;
}