#include <stdio.h>
#include <string.h>

void CalculateSingleStudentGrade();

int main()
{
    printf("Weighted Grade Calculation Program: \n");
    printf("===================================\n");
    printf("1. Single Student Grades\n");
    printf("2. Multiple Students Grades\n");
    printf("3. Exit\n");
    printf("===================================\n");
    int choice;
    printf("Please enter your choice(1/2/3): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        CalculateSingleStudentGrade();
        break;
    default:
        break;
    }
}

void CalculateSingleStudentGrade()
{
    printf("Number of components: ");
    int numComponents;
    scanf("%d", &numComponents);
    
    char componentNames[numComponents][50];
    float weights[numComponents];
    float MaxAllotedMarks[numComponents];
    float earnedMarks[numComponents];
    float finalMarks = 0;

    for (int i = 0; i < numComponents; i++)
    {
        printf("Component %d: \n", i + 1);

        printf("Name: ");
        scanf(" %49[^\n]", componentNames[i]); // Note the space before %

        printf("Weight: ");
        scanf("%f", &weights[i]);

        printf("Max Alloted Marks: ");
        scanf("%f", &MaxAllotedMarks[i]);
    }

    printf("--Summary of Score--\n");
    for (int i = 0; i < numComponents; i++)
    {
        printf("Enter marks obtained for %s: ", componentNames[i]);
        scanf("%f", &earnedMarks[i]);
        finalMarks += (earnedMarks[i] / MaxAllotedMarks[i]) * (weights[i]/100) * 100;
    }

    printf("--Final Grade--\n");
    printf("Final Weighted Grade: %.2f%%\n", finalMarks);
}