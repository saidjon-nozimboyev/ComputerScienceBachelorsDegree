#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char name[20];
    float weight;
    float maxPoints;
    float earnedPoints;
} CourseComponent;

typedef struct {
    char name[50];
    CourseComponent *components;
    int numComponents;
    double finalGrade;
    char letterGrade[3];
} Student;

int programActive = 1;
Student *students = NULL;
int studentCount = 0;

float ComputeOverallScore(CourseComponent elements[], int elementCount);
const char *DetermineGradeSymbol(float score);
void SortStudentArray(Student *students, int arraySize);
int FindStudentByName(Student *students, int arraySize, const char *name);

void ProcessSingleStudent()
{
    Student student;

    printf("Enter student's full name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; 

    printf("Enter number of course components: ");
    scanf("%d", &student.numComponents);
    getchar(); 

    if (student.numComponents <= 0)
    {
        printf("Number of components must be positive.\n");
        return;
    }

    student.components = (CourseComponent *)malloc(student.numComponents * sizeof(CourseComponent));
    if (student.components == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    float weightSum = 0;
    int weightsValid = 0;

    while (!weightsValid)
    {
        weightSum = 0;
        for (int i = 0; i < student.numComponents; i++)
        {
            printf("\nComponent %d:\n", i + 1);
            printf("Name: ");
            fgets(student.components[i].name, sizeof(student.components[i].name), stdin);
            student.components[i].name[strcspn(student.components[i].name, "\n")] = '\0';

            do
            {
                printf("Weight (as percentage): ");
                scanf("%f", &student.components[i].weight);
                if (student.components[i].weight <= 0)
                {
                    printf("Weight must be positive.\n");
                }
            } while (student.components[i].weight <= 0);

            do
            {
                printf("Max Allocated Points: ");
                scanf("%f", &student.components[i].maxPoints);
                if (student.components[i].maxPoints <= 0)
                {
                    printf("Maximum marks must be positive.\n");
                }
            } while (student.components[i].maxPoints <= 0);

            do
            {
                printf("Earned Points: ");
                scanf("%f", &student.components[i].earnedPoints);
                if (student.components[i].earnedPoints < 0)
                {
                    printf("Earned points cannot be negative.\n");
                }
                else if (student.components[i].earnedPoints > student.components[i].maxPoints)
                {
                    printf("Error: Earned points cannot exceed maximum allocated points.\nPlease re-enter.\n");
                }
            } while (student.components[i].earnedPoints < 0 ||
                     student.components[i].earnedPoints > student.components[i].maxPoints);

            weightSum += student.components[i].weight;
            getchar(); 
        }

        if (fabs(weightSum - 100.0) > 0.01)
        {
            printf("Error: Total weight = %.2f%%. Total weight must equal 100%%! Please re-enter all components.\n", weightSum);
        }
        else
        {
            weightsValid = 1;
        }
    }

    student.finalGrade = ComputeOverallScore(student.components, student.numComponents);
    int roundedScore = (int)round(student.finalGrade);
    strcpy(student.letterGrade, DetermineGradeSymbol(roundedScore));

    printf("\n-- Summary of Scores --\n");
    printf("Final Weighted Grade: %d%%\n", roundedScore);
    printf("Letter Grade: %s\n", student.letterGrade);

    free(student.components);
}

void ProcessMultipleStudents()
{
    int componentCount;
    printf("Enter number of course components: ");
    scanf("%d", &componentCount);
    getchar();

    if (componentCount <= 0)
    {
        printf("Number of components must be positive.\n");
        return;
    }

    CourseComponent *componentBlueprint = (CourseComponent *)malloc(componentCount * sizeof(CourseComponent));
    if (componentBlueprint == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    float weightSum = 0;
    int weightsValid = 0;

    while (!weightsValid)
    {
        weightSum = 0;
        for (int i = 0; i < componentCount; i++)
        {
            printf("\nComponent %d:\n", i + 1);
            printf("Name: ");
            fgets(componentBlueprint[i].name, sizeof(componentBlueprint[i].name), stdin);
            componentBlueprint[i].name[strcspn(componentBlueprint[i].name, "\n")] = '\0';

            do
            {
                printf("Weight (as percentage): ");
                scanf("%f", &componentBlueprint[i].weight);
                if (componentBlueprint[i].weight <= 0)
                {
                    printf("Weight must be positive.\n");
                }
            } while (componentBlueprint[i].weight <= 0);

            do
            {
                printf("Max Allocated Points: ");
                scanf("%f", &componentBlueprint[i].maxPoints);
                if (componentBlueprint[i].maxPoints <= 0)
                {
                    printf("Maximum marks must be positive.\n");
                }
            } while (componentBlueprint[i].maxPoints <= 0);

            weightSum += componentBlueprint[i].weight;
            getchar(); 
        }

        if (fabs(weightSum - 100.0) > 0.01)
        {
            printf("Error: Total weight = %.2f%%. Total weight must equal 100%%! Please re-enter all components.\n", weightSum);
        }
        else
        {
            weightsValid = 1;
        }
    }

    printf("\nEnter student's full name (or type DONE to stop): ");
    char nameInput[50];

    while (1)
    {
        fgets(nameInput, sizeof(nameInput), stdin);
        nameInput[strcspn(nameInput, "\n")] = '\0';

        if (strcmp(nameInput, "DONE") == 0)
        {
            break;
        }

        Student *tempPtr = (Student *)realloc(students, (studentCount + 1) * sizeof(Student));
        if (tempPtr == NULL)
        {
            printf("Memory allocation failed!\n");
            free(componentBlueprint);
            return;
        }
        students = tempPtr;

        strcpy(students[studentCount].name, nameInput);
        students[studentCount].numComponents = componentCount;

        students[studentCount].components = (CourseComponent *)malloc(componentCount * sizeof(CourseComponent));
        if (students[studentCount].components == NULL)
        {
            printf("Memory allocation failed!\n");
            free(componentBlueprint);
            return;
        }

        for (int i = 0; i < componentCount; i++)
        {
            strcpy(students[studentCount].components[i].name, componentBlueprint[i].name);
            students[studentCount].components[i].weight = componentBlueprint[i].weight;
            students[studentCount].components[i].maxPoints = componentBlueprint[i].maxPoints;

            do
            {
                printf("Score for \"%s\": ", componentBlueprint[i].name);
                scanf("%f", &students[studentCount].components[i].earnedPoints);
                if (students[studentCount].components[i].earnedPoints < 0)
                {
                    printf("Earned points cannot be negative.\n");
                }
                else if (students[studentCount].components[i].earnedPoints > componentBlueprint[i].maxPoints)
                {
                    printf("Error: Earned points cannot exceed maximum allocated points.\nPlease re-enter.\n");
                }
            } while (students[studentCount].components[i].earnedPoints < 0 ||
                     students[studentCount].components[i].earnedPoints > componentBlueprint[i].maxPoints);
        }
        getchar(); 

        students[studentCount].finalGrade = ComputeOverallScore(students[studentCount].components, componentCount);
        int roundedScore = (int)round(students[studentCount].finalGrade);
        strcpy(students[studentCount].letterGrade, DetermineGradeSymbol(roundedScore));

        printf("Enter student's full name (or type DONE to stop): ");
        studentCount++;
    }

    printf("\n-- Class Summary --\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("%s - %d%% (%s)\n", students[i].name, (int)round(students[i].finalGrade), students[i].letterGrade);
    }

    if (studentCount > 0)
    {
        float highestScore = 0;
        float scoreSum = 0;

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].finalGrade > highestScore)
            {
                highestScore = students[i].finalGrade;
            }
            scoreSum += students[i].finalGrade;
        }

        float medianScore;
        SortStudentArray(students, studentCount);
        if (studentCount % 2 == 0)
        {
            medianScore = (students[studentCount / 2 - 1].finalGrade + students[studentCount / 2].finalGrade) / 2;
        }
        else
        {
            medianScore = students[studentCount / 2].finalGrade;
        }

        printf("\nMaximum: %.2f%% (Students: ", highestScore);
        int firstStudent = 1;
        for (int i = 0; i < studentCount; i++)
        {
            if (fabs(students[i].finalGrade - highestScore) < 0.01)
            {
                if (!firstStudent)
                    printf(", ");
                printf("%s", students[i].name);
                firstStudent = 0;
            }
        }
        printf(")\n");

        printf("Average: %.2f%%\n", scoreSum / studentCount);
        printf("Median: %.2f%%\n", medianScore);
    }

    free(componentBlueprint);
}

void SortStudentsByScore()
{
    if (studentCount == 0)
    {
        printf("No students to sort.\n");
        return;
    }

    printf("======================================\n");
    printf("Sorting students by final grade...\n");
    printf("======================================\n");

    SortStudentArray(students, studentCount);

    printf("Class Ranking:\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("%d. %s - %d%% (%s)\n", i + 1, students[i].name,
               (int)round(students[i].finalGrade), students[i].letterGrade);
    }
}

void FindStudent()
{
    if (studentCount == 0)
    {
        printf("No students to search.\n");
        return;
    }

    char searchName[50];
    printf("Enter student name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int foundIndex = FindStudentByName(students, studentCount, searchName);
    if (foundIndex != -1)
    {
        printf("Result: %s - %d%% (%s)\n", students[foundIndex].name,
               (int)round(students[foundIndex].finalGrade), students[foundIndex].letterGrade);
    }
    else
    {
        printf("Student not found.\n");
    }
}

void CleanupStudentData(Student *students, int count)
{
    if (students == NULL) return;
    
    for (int i = 0; i < count; i++)
    {
        free(students[i].components);
    }
    free(students);
}

float ComputeOverallScore(CourseComponent elements[], int elementCount)
{
    float finalScore = 0.0;
    for (int i = 0; i < elementCount; i++)
    {
        finalScore += (elements[i].earnedPoints / elements[i].maxPoints) * (elements[i].weight / 100) * 100;
    }
    return finalScore;
}

const char *DetermineGradeSymbol(float score)
{
    if (score >= 90)
        return "A+";
    else if (score >= 85)
        return "A";
    else if (score >= 80)
        return "A-";
    else if (score >= 75)
        return "B+";
    else if (score >= 70)
        return "B";
    else if (score >= 65)
        return "C+";
    else if (score >= 60)
        return "C";
    else if (score >= 50)
        return "D";
    else
        return "F";
}

void SortStudentArray(Student *students, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (students[i].finalGrade < students[j].finalGrade)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int FindStudentByName(Student *students, int arraySize, const char *name)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    while (programActive)
    {
        printf("======================================\n");
        printf("Weighted Grade Calculation Program\n");
        printf("======================================\n");
        printf("1. Single Student Grades\n");
        printf("2. Multiple Students Grades\n");
        printf("3. Sort Students by Grade\n");
        printf("4. Search for a Student\n");
        printf("5. Exit\n");
        printf("Enter your choice (1/2/3/4/5): ");

        int userChoice;
        scanf("%d", &userChoice);
        getchar(); 

        switch (userChoice)
        {
        case 1:
            ProcessSingleStudent();
            break;
        case 2:
            ProcessMultipleStudents();
            break;
        case 3:
            SortStudentsByScore();
            break;
        case 4:
            FindStudent();
            break;
        case 5:
            printf("--- HAVE A GOOD DAY! ---\n");
            printf("======================================\n");
            programActive = 0;
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    CleanupStudentData(students, studentCount);
    return 0;
}