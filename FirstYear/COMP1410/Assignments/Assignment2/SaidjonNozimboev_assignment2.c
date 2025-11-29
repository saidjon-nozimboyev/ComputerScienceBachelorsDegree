#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char name[15];
    double weight;
    double maxPoints;
    double earnedPoints;
} CourseComponent;

typedef struct
{
    char name[50];
    CourseComponent *components;
    int numComponents;
    double finalGrade;
    char letterGrade[3];
} Student;

void CalculateSingleStudentGrade();
void CalculateMultipleStudentsGrades();
void SortStudentsByGrade();
void SearchStudent();
void FreeStudents(Student *students, int count);
void FreeStudentComponents(Student *student);

double CalculateFinalGrade(CourseComponent components[], int numComponents);
const char *CalculateLetterGrade(double grade);
void SortArray(Student *students, int size);
int SearchStudentByName(Student *students, int size, const char *name);

int running = 1;
Student *students = NULL;
int studentCount = 0;

int main()
{
    while (running)
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

        int choice;
        scanf("%d", &choice);
        getchar(); 

        switch (choice)
        {
        case 1:
            CalculateSingleStudentGrade();
            break;
        case 2:
            CalculateMultipleStudentsGrades();
            break;
        case 3:
            SortStudentsByGrade();
            break;
        case 4:
            SearchStudent();
            break;
        case 5:
            printf("--- HAVE A GOOD DAY! ---\n");
            running = 0;
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    FreeStudents(students, studentCount);
    return 0;
}

void CalculateSingleStudentGrade()
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

    double totalWeight = 0;
    int validWeights = 0;

    while (!validWeights)
    {
        totalWeight = 0;
        for (int i = 0; i < student.numComponents; i++)
        {
            printf("\nComponent %d:\n", i + 1);
            printf("Name: ");
            fgets(student.components[i].name, sizeof(student.components[i].name), stdin);
            student.components[i].name[strcspn(student.components[i].name, "\n")] = '\0';

            do
            {
                printf("Weight (as percentage): ");
                scanf("%lf", &student.components[i].weight);
                if (student.components[i].weight <= 0)
                {
                    printf("Weight must be positive.\n");
                }
            } while (student.components[i].weight <= 0);

            do
            {
                printf("Max Allocated Points: ");
                scanf("%lf", &student.components[i].maxPoints);
                if (student.components[i].maxPoints <= 0)
                {
                    printf("Maximum marks must be positive.\n");
                }
            } while (student.components[i].maxPoints <= 0);

            do
            {
                printf("Earned Points: ");
                scanf("%lf", &student.components[i].earnedPoints);
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

            totalWeight += student.components[i].weight;
            getchar(); 
        }

        if (fabs(totalWeight - 100.0) > 0.01)
        {
            printf("Error: Total weight = %.2f%%. Total weight must equal 100%%! Please re-enter all components.\n", totalWeight);
        }
        else
        {
            validWeights = 1;
        }
    }

    student.finalGrade = CalculateFinalGrade(student.components, student.numComponents);
    int roundedGrade = (int)round(student.finalGrade);
    strcpy(student.letterGrade, CalculateLetterGrade(roundedGrade));

    printf("\n-- Summary of Scores --\n");
    printf("Final Weighted Grade: %d%%\n", roundedGrade);
    printf("Letter Grade: %s\n", student.letterGrade);

    free(student.components);
}

void CalculateMultipleStudentsGrades()
{
    int numComponents;
    printf("Enter number of course components: ");
    scanf("%d", &numComponents);
    getchar();

    if (numComponents <= 0)
    {
        printf("Number of components must be positive.\n");
        return;
    }

    CourseComponent *componentTemplate = (CourseComponent *)malloc(numComponents * sizeof(CourseComponent));
    if (componentTemplate == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    double totalWeight = 0;
    int validWeights = 0;

    while (!validWeights)
    {
        totalWeight = 0;
        for (int i = 0; i < numComponents; i++)
        {
            printf("\nComponent %d:\n", i + 1);
            printf("Name: ");
            fgets(componentTemplate[i].name, sizeof(componentTemplate[i].name), stdin);
            componentTemplate[i].name[strcspn(componentTemplate[i].name, "\n")] = '\0';

            do
            {
                printf("Weight (as percentage): ");
                scanf("%lf", &componentTemplate[i].weight);
                if (componentTemplate[i].weight <= 0)
                {
                    printf("Weight must be positive.\n");
                }
            } while (componentTemplate[i].weight <= 0);

            do
            {
                printf("Max Allocated Points: ");
                scanf("%lf", &componentTemplate[i].maxPoints);
                if (componentTemplate[i].maxPoints <= 0)
                {
                    printf("Maximum marks must be positive.\n");
                }
            } while (componentTemplate[i].maxPoints <= 0);

            totalWeight += componentTemplate[i].weight;
            getchar(); 
        }

        if (fabs(totalWeight - 100.0) > 0.01)
        {
            printf("Error: Total weight = %.2f%%. Total weight must equal 100%%! Please re-enter all components.\n", totalWeight);
        }
        else
        {
            validWeights = 1;
        }
    }

    printf("\nEnter student's full name (or type DONE to stop): ");
    char name[50];

    while (1)
    {
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strcmp(name, "DONE") == 0)
        {
            break;
        }

        Student *temp = (Student *)realloc(students, (studentCount + 1) * sizeof(Student));
        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            free(componentTemplate);
            return;
        }
        students = temp;

        strcpy(students[studentCount].name, name);
        students[studentCount].numComponents = numComponents;

        students[studentCount].components = (CourseComponent *)malloc(numComponents * sizeof(CourseComponent));
        if (students[studentCount].components == NULL)
        {
            printf("Memory allocation failed!\n");
            free(componentTemplate);
            return;
        }

        for (int i = 0; i < numComponents; i++)
        {
            strcpy(students[studentCount].components[i].name, componentTemplate[i].name);
            students[studentCount].components[i].weight = componentTemplate[i].weight;
            students[studentCount].components[i].maxPoints = componentTemplate[i].maxPoints;

            do
            {
                printf("Score for \"%s\": ", componentTemplate[i].name);
                scanf("%lf", &students[studentCount].components[i].earnedPoints);
                if (students[studentCount].components[i].earnedPoints < 0)
                {
                    printf("Earned points cannot be negative.\n");
                }
                else if (students[studentCount].components[i].earnedPoints > componentTemplate[i].maxPoints)
                {
                    printf("Error: Earned points cannot exceed maximum allocated points.\nPlease re-enter.\n");
                }
            } while (students[studentCount].components[i].earnedPoints < 0 ||
                     students[studentCount].components[i].earnedPoints > componentTemplate[i].maxPoints);
        }
        getchar(); 

        students[studentCount].finalGrade = CalculateFinalGrade(students[studentCount].components, numComponents);
        int roundedGrade = (int)round(students[studentCount].finalGrade);
        strcpy(students[studentCount].letterGrade, CalculateLetterGrade(roundedGrade));

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
        double maxGrade = 0;
        double sum = 0;

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].finalGrade > maxGrade)
            {
                maxGrade = students[i].finalGrade;
            }
            sum += students[i].finalGrade;
        }

        double median;
        SortArray(students, studentCount);
        if (studentCount % 2 == 0)
        {
            median = (students[studentCount / 2 - 1].finalGrade + students[studentCount / 2].finalGrade) / 2;
        }
        else
        {
            median = students[studentCount / 2].finalGrade;
        }

        printf("\nMaximum: %.2f%% (Students: ", maxGrade);
        int first = 1;
        for (int i = 0; i < studentCount; i++)
        {
            if (fabs(students[i].finalGrade - maxGrade) < 0.01)
            {
                if (!first)
                    printf(", ");
                printf("%s", students[i].name);
                first = 0;
            }
        }
        printf(")\n");

        printf("Average: %.2f%%\n", sum / studentCount);
        printf("Median: %.2f%%\n", median);
    }

    free(componentTemplate);
}

void SortStudentsByGrade()
{
    if (studentCount == 0)
    {
        printf("No students to sort.\n");
        return;
    }

    printf("======================================\n");
    printf("Sorting students by final grade...\n");
    printf("======================================\n");

    SortArray(students, studentCount);

    printf("Class Ranking:\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("%d. %s - %d%% (%s)\n", i + 1, students[i].name,
               (int)round(students[i].finalGrade), students[i].letterGrade);
    }
}

void SearchStudent()
{
    if (studentCount == 0)
    {
        printf("No students to search.\n");
        return;
    }

    char name[50];
    printf("Enter student name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = SearchStudentByName(students, studentCount, name);
    if (index != -1)
    {
        printf("Result: %s - %d%% (%s)\n", students[index].name,
               (int)round(students[index].finalGrade), students[index].letterGrade);
    }
    else
    {
        printf("Student not found.\n");
    }
}

double CalculateFinalGrade(CourseComponent components[], int numComponents)
{
    double finalGrade = 0.0;
    for (int i = 0; i < numComponents; i++)
    {
        finalGrade += (components[i].earnedPoints / components[i].maxPoints) * (components[i].weight / 100) * 100;
    }
    return finalGrade;
}

const char *CalculateLetterGrade(double grade)
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

void SortArray(Student *students, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
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

int SearchStudentByName(Student *students, int size, const char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void FreeStudents(Student *students, int count)
{
    for (int i = 0; i < count; i++)
    {
        FreeStudentComponents(&students[i]);
    }
    free(students);
}

void FreeStudentComponents(Student *student)
{
    free(student->components);
}