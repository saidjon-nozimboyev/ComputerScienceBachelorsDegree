#include <stdio.h>
#include <string.h>

void CalculateSingleStudentGrade();
void CalculateMultipleStudentsGrades();

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
    float finalMarks = 0;

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
        finalMarks += (earnedMarks[i] / MaxAllotedMarks[i]) * (weights[i]/100) * 100;
    }

    printf("--Final Grade--\n");
    printf("Final Weighted Grade: %.2f%%\n", finalMarks);
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
        if (total >= 90) printf("Letter Grade: A+\n");
        else if (total >= 80) printf("Letter Grade: A\n");
        else if (total >= 70) printf("Letter Grade: B\n");
        else if (total >= 60) printf("Letter Grade: C\n");
        else if (total >= 50) printf("Letter Grade: D\n");
        else printf("Letter Grade: F\n");
    }

    for (int i = 0; i < numStudents - 1; i++)
        for (int j = i + 1; j < numStudents; j++)
            if (finalGrades[i] > finalGrades[j])
            {
                temp = finalGrades[i];
                finalGrades[i] = finalGrades[j];
                finalGrades[j] = temp;
            }

    float max = finalGrades[numStudents - 1];
    float sum = 0;
    for (int i = 0; i < numStudents; i++) 
        sum += finalGrades[i];

    float avg = sum / numStudents;

    float median;
    if (numStudents % 2 == 0)
        median = (finalGrades[numStudents/2 - 1] + finalGrades[numStudents/2]) / 2;
    else
        median = finalGrades[numStudents/2];

    printf("Class Summary:\n");
    printf("Maximum: %.2f\n", max);
    printf("Average: %.2f\n", avg);
    printf("Median: %.2f\n", median);
}
