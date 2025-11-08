#include <stdio.h>
#include <string.h>
#include <math.h>

void CalculateSingleStudentGrade();
void CalculateMultipleStudentsGrades();
void SortArray(double arr[], int size);

double FindMax(double arr[], int size);
double FindSumRecursive(double arr[], int size); // Recursive sum function
double FindMedian(double arr[], int size);

double CalculateFinalGrade(double earnedMarks[], double MaxAllotedMarks[], double weights[], int size);
const char* CalculateLetterGrade(double grade);

int running = 1;

int main()
{
    while (running)
    {
        printf("=====================================\n");
        printf("Weighted Grade Calculation Program\n");
        printf("=====================================\n");
        printf("1. Single student\n");
        printf("2. Multiple students\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        
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
                printf("--- HAVE A GOOD DAY! ---\n");
                printf("=====================================\n");
                running = 0;
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void CalculateSingleStudentGrade()
{
    int numComponents;
    printf("\nNumber of components: ");
    scanf("%d", &numComponents);

    if (numComponents <= 0)
    {
        printf("Number of components must be positive.\n");
        return;
    }

    char componentNames[numComponents][15];
    double weights[numComponents];
    double MaxAllotedMarks[numComponents];
    double earnedMarks[numComponents];

    double totalWeight = 0;

    for (int i = 0; i < numComponents; i++)
    {
        printf("\nComponent %d:\n", i + 1);
        printf("Name: ");
        scanf(" %14[^\n]", componentNames[i]);

        do
        {
            printf("Weight: ");
            scanf("%lf", &weights[i]);
            if (weights[i] <= 0)
            {
                printf("Weight must be positive.\n");
                printf("Enter a valid weight.\n");
            }
        } while (weights[i] <= 0);

        do
        {
            printf("Max Allocated Point: ");
            scanf("%lf", &MaxAllotedMarks[i]);
            if (MaxAllotedMarks[i] <= 0)
            {
                printf("Maximum marks must be positive.\n");
                printf("Enter valid maximum marks.\n");
            }
        } while (MaxAllotedMarks[i] <= 0);

        totalWeight += weights[i];
    }

    if ((totalWeight - 100.0) != 0.0)
    {
        printf("\nTotal component weights must equal 100 (current total = %.2f)\n", totalWeight);
        return;
    }

    printf("\n-- Summary of Scores --\n");
    for (int i = 0; i < numComponents; i++)
    {
        do
        {
            printf("Score for \"%s\" (Max %.2f): ", componentNames[i], MaxAllotedMarks[i]);
            scanf("%lf", &earnedMarks[i]);
            if (earnedMarks[i] < 0 || earnedMarks[i] > MaxAllotedMarks[i])
                printf("Invalid score. It must be between 0 and %.2f\n", MaxAllotedMarks[i]);
        } while (earnedMarks[i] < 0 || earnedMarks[i] > MaxAllotedMarks[i]);
    }

    double finalMarks = CalculateFinalGrade(earnedMarks, MaxAllotedMarks, weights, numComponents);
    int roundedGrade = (int)round(finalMarks);
    const char* letterGrade = CalculateLetterGrade(roundedGrade);

    printf("\n-- Final Grade --\n");
    printf("Final Weighted Grade: %d%%\n", roundedGrade);
    printf("Letter Grade: %s\n", letterGrade);

    int again;
    printf("\nWould you like to continue? (1 for Yes / 0 for No): ");
    scanf("%d", &again);
    if (!again)
        running = 0;
}

void CalculateMultipleStudentsGrades()
{
    int numComponents;
    printf("\nNumber of components: ");
    scanf("%d", &numComponents);

    if (numComponents <= 0)
    {
        printf("Number of components must be positive.\n");
        return;
    }

    char componentNames[numComponents][15];
    double weights[numComponents];
    double MaxAllotedMarks[numComponents];

    double totalWeight = 0;

    for (int i = 0; i < numComponents; i++)
    {
        printf("\nComponent %d:\n", i + 1);
        printf("Name: ");
        scanf(" %14[^\n]", componentNames[i]);

        do
        {
            printf("Weight: ");
            scanf("%lf", &weights[i]);
            if (weights[i] <= 0)
            {
                printf("Weight must be positive.\n");
                printf("Enter a valid weight.\n");
            }
        } while (weights[i] <= 0);

        do
        {
            printf("Max Allocated Point: ");
            scanf("%lf", &MaxAllotedMarks[i]);
            if (MaxAllotedMarks[i] <= 0)
            {
                printf("Maximum marks must be positive.\n");
                printf("Enter valid maximum marks.\n");
            }
        } while (MaxAllotedMarks[i] <= 0);

        totalWeight += weights[i];
    }

    if ((totalWeight - 100.0) != 0)
    {
        printf("\nTotal component weights must equal 100 (current total = %.2f)\n", totalWeight);
        return;
    }

    int numStudents;
    printf("\nNumber of students: ");
    scanf("%d", &numStudents);

    if (numStudents <= 0)
    {
        printf("Number of students must be positive.\n");
        return;
    }

    double finalGrades[numStudents];

    for (int s = 0; s < numStudents; s++)
    {
        printf("\n-- Student %d --\n", s + 1);
        double total = 0;

        for (int i = 0; i < numComponents; i++)
        {
            double score;
            do
            {
                printf("Score for \"%s\" (Max %.2f): ", componentNames[i], MaxAllotedMarks[i]);
                scanf("%lf", &score);
                if (score < 0 || score > MaxAllotedMarks[i])
                    printf("Invalid score. It must be between 0 and %.2f\n", MaxAllotedMarks[i]);
            } while (score < 0 || score > MaxAllotedMarks[i]);

            total += (score / MaxAllotedMarks[i]) * (weights[i] / 100) * 100;
        }

        finalGrades[s] = total;
        int roundedGrade = (int)round(total);
        const char* letterGrade = CalculateLetterGrade(roundedGrade);

        printf("Final Weighted Grade: %d%%\n", roundedGrade);
        printf("Letter Grade: %s\n", letterGrade);
    }

    SortArray(finalGrades, numStudents);

    double max = FindMax(finalGrades, numStudents);
    double sum = FindSumRecursive(finalGrades, numStudents);
    double avg = sum / (double)numStudents;
    double median = FindMedian(finalGrades, numStudents);

    printf("\nClass Summary:\n");
    printf("Maximum: %.2f\n", max);
    printf("Average: %.2f\n", avg);
    printf("Median: %.2f\n", median);

    printf("\nWould you like to continue? (1 for Yes / 0 for No): ");
    int again;
    scanf("%d", &again);
    if (!again)
        running = 0;
}

double CalculateFinalGrade(double earnedMarks[], double MaxAllotedMarks[], double weights[], int size)
{
    double finalGrade = 0.0;
    for (int i = 0; i < size; i++)
        finalGrade += (earnedMarks[i] / MaxAllotedMarks[i]) * (weights[i] / 100) * 100;
    return finalGrade;
}

const char* CalculateLetterGrade(double grade)
{
    if (grade >= 90)
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

void SortArray(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
            {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

double FindMax(double arr[], int size)
{
    return arr[size - 1];
}

double FindSumRecursive(double arr[], int size)
{
    if (size == 0)
        return 0;
    return arr[size - 1] + FindSumRecursive(arr, size - 1);
}

double FindMedian(double arr[], int size)
{
    if (size % 2 == 0)
        return (arr[size / 2 - 1] + arr[size / 2]) / 2;
    else
        return arr[size / 2];
}