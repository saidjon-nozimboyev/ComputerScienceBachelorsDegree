#include <stdio.h>

struct Car
{
    char model[50];
    int year;
    float mileage;
};

void printHighMileageCars(struct Car cars[], int size, float threshold) 
{
    printf("Cars with mileage >= %.2f km/l:\n", threshold);
    for (int i = 0; i < size; i++) 
    {
        if (cars[i].mileage >= threshold) 
        {
            printf("Model: %s, Year: %d, Mileage: %.2f km/l\n", cars[i].model, cars[i].year, cars[i].mileage);
        }
    }
}

int main() 
{
    struct Car cars[4];

    printf("Enter details for 4 cars:\n");
    for (int i = 0; i < 4; i++) 
    {
        printf("Car: %d\n", i + 1);
        printf("Model: ");
        scanf(" %[^\n]", cars[i].model);
        printf("Year: ");
        scanf("%d", &cars[i].year);
        printf("Mileage: ");
        scanf("%f", &cars[i].mileage);
    }

    printHighMileageCars(cars, 4, 15.0);

    return 0;
}