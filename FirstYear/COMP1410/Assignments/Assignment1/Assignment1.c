#include <stdio.h>
#include <string.h>

void CalculateSingleStudentGrade();
void CalculateMultipleStudentsGrades();
void SortArray(float arr[], int size);
float FindMax(float arr[], int size);
float FindSum(float arr[], int size);
float FindMedian(float arr[], int size);
float CalculateFinalGrade(float earnedMarks[], float MaxAllotedMarks[], float weights[], int size);
double CalculateMedian(float arr[], int size);
double CalculateAverage(float arr[], int size);
char CalculateLetterGrade(float grade);

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
    case 2:
        CalculateMultipleStudentsGrades();
        break;
    case 3:
        printf("--- HAVE A GOOD DAY! ---\n");
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
    char letterGrade = CalculateLetterGrade(finalMarks);

    printf("--Final Grade--\n");
    printf("Final Weighted Grade: %.2f%%\n", finalMarks);
    printf("Letter Grade: %c\n", letterGrade);
}

void CalculateMultipleStudentsGrades()
{
    int numComponents;
    printf("Number of components: ");
    scanf("%d", &numComponents);

    char componentNames[numComponents][50];
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
    float temp;

    for (int s = 0; s < numStudents; s++)
    {
        printf("-- Student %d --\n", s + 1);
        float total = 0;
        for (int i = 0; i < numComponents; i++)
        {
            float score;
            printf("Score for \"%s\": ", componentNames[i]);
            scanf("%f", &score);
            total += (score / MaxAllotedMarks[i]) * (weights[i]/100) * 100;
        }

        finalGrades[s] = total;

        printf("Final Weighted Grade: %.0f%%\n", total);
        char letterGrade = CalculateLetterGrade(total);
        printf("Letter Grade: %c\n", letterGrade);
    }

    SortArray(finalGrades, numStudents);

    float max = FindMax(finalGrades, numStudents);

    float sum = FindSum(finalGrades, numStudents);

    float avg = sum / numStudents;

    float median = FindMedian(finalGrades, numStudents);

    printf("Class Summary:\n");
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

char CalculateLetterGrade(float grade)
{
    if (grade >= 80) return 'A';
    else if (grade >= 70) return 'B';
    else if (grade >= 60) return 'C';
    else if (grade >= 50) return 'D';
    else return 'F';
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

float FindSum(float arr[], int size)
{
    float sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float FindMedian(float arr[], int size)
{
    if (size % 2 == 0)
        return (arr[size/2 - 1] + arr[size/2]) / 2;
    else
        return arr[size/2];
}