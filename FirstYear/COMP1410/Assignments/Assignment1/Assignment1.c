#include <stdio.h>
#include <string.h>
#include <math.h> 

void CalculateSingleStudentGrade();
void CalculateMultipleStudentsGrades();
void SortArray(float arr[], int size);

float FindMax(float arr[], int size);
float FindSumRecursive(float arr[], int size);
float FindMedian(float arr[], int size);

float CalculateFinalGrade(float earnedMarks[], float MaxAllotedMarks[], float weights[], int size);
const char* CalculateLetterGrade(float grade); 

int running = 1;

int main()
{
    while (running)
    {
        printf("Grade Calculator Menu:\n");
        printf("1. Calculate grade for a single student\n");
        printf("2. Calculate grades for multiple students\n");
        printf("3. Exit\n");
        printf("Select an option (1/2/3): ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                CalculateSingleStudentGrade();
                break;
            case 2:
                CalculateMultipleStudentsGrades();
                break;
            case 3:
                printf("HAVE A GOOD DAY\n");
                running = 0;
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void CalculateSingleStudentGrade()
{
    printf("Number of components: ");
    int numComponents;
    scanf("%d", &numComponents);
    
    char componentNames[numComponents][20];
    float weights[numComponents];
    float MaxAllotedMarks[numComponents];
    float earnedMarks[numComponents];

    for (int i = 0; i < numComponents; i++)
    {
        printf("Component %d: \n", i + 1);
        printf("Name: ");
        scanf(" %49[^\n]", componentNames[i]);
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
    }
    
    float finalMarks = CalculateFinalGrade(earnedMarks, MaxAllotedMarks, weights, numComponents);
    int roundedGrade = (int)round(finalMarks);
    const char* letterGrade = CalculateLetterGrade(roundedGrade);

    printf("--Final Grade--\n");
    printf("Final Weighted Grade: %.2f (rounded to %d)\n", finalMarks, roundedGrade);
    printf("Letter Grade: %s\n", letterGrade);
    
    printf("Would you like to calculate another grade? (1 for Yes / 0 for No): ");
    int again;
    scanf("%d", &again);
    if (!again)
        running = 0;
}

void CalculateMultipleStudentsGrades()
{
    int numComponents;
    printf("Number of components: ");
    scanf("%d", &numComponents);

    char componentNames[numComponents][20];
    float weights[numComponents];
    float MaxAllotedMarks[numComponents];

    for (int i = 0; i < numComponents; i++)
    {
        printf("Component %d:\n", i + 1);
        printf("Name: ");
        scanf(" %49[^\n]", componentNames[i]);
        printf("Weight: ");
        scanf("%f", &weights[i]);
        printf("Max Allocated Point: ");
        scanf("%f", &MaxAllotedMarks[i]);
    }

    int numStudents;
    printf("Number of students: ");
    scanf("%d", &numStudents);

    float finalGrades[numStudents];

    for (int s = 0; s < numStudents; s++)
    {
        printf("-- Student %d --\n", s + 1);
        float total = 0;
        for (int i = 0; i < numComponents; i++)
        {
            float score;
            printf("Score for \"%s\": ", componentNames[i]);
            scanf("%f", &score);
            total += (score / MaxAllotedMarks[i]) * (weights[i] / 100) * 100;
        }

        finalGrades[s] = total;

        int roundedGrade = (int)round(total);
        const char* letterGrade = CalculateLetterGrade(roundedGrade);

        printf("Final Weighted Grade: %.2f (rounded to %d)\n", total, roundedGrade);
        printf("Letter Grade: %s\n", letterGrade);
    }

    SortArray(finalGrades, numStudents);

    float max = FindMax(finalGrades, numStudents);
    float sum = FindSumRecursive(finalGrades, numStudents);
    float avg = sum / numStudents;
    float median = FindMedian(finalGrades, numStudents);

    printf("\n-- Class Summary --\n");
    printf("Maximum: %.2f\n", max);
    printf("Average: %.2f\n", avg);
    printf("Median: %.2f\n", median);
}

float CalculateFinalGrade(float earnedMarks[], float MaxAllotedMarks[], float weights[], int size)
{
    double finalGrade = 0.0;
    for (int i = 0; i < size; i++)
    {
        finalGrade += (earnedMarks[i] / MaxAllotedMarks[i]) * (weights[i] / 100) * 100;
    }
    return finalGrade;
}

// Updated letter grade function using your exact table
const char* CalculateLetterGrade(float grade)
{
    if (grade >= 90 && grade <= 100)
        return "A+";
    else if (grade >= 85)
        return "A";
    else if (grade >= 80)
        return "A-";
    else if (grade >= 75)
        return "B+";
    else if (grade >= 70)
        return "B";
    else if (grade >= 65)
        return "C+";
    else if (grade >= 60)
        return "C";
    else if (grade >= 50)
        return "D";
    else
        return "F";
}

void SortArray(float arr[], int size)
{
    float temp;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

float FindMax(float arr[], int size)
{
    return arr[size - 1];
}

float FindSumRecursive(float arr[], int size)
{   
    if (size == 0)
        return 0;
    return arr[size - 1] + FindSumRecursive(arr, size - 1);
}

float FindMedian(float arr[], int size)
{
    if (size % 2 == 0)
        return (arr[size/2 - 1] + arr[size/2]) / 2;
    else
        return arr[size/2];
}
