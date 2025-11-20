#include <stdio.h>


int main() 
{
    FILE *file = fopen("Marks.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    int lineCount = 0;
    int passedCount = 0;
    
    printf("\nStudents:\n");
    while (fgets(line, sizeof(line), file)) 
    {
        lineCount++;
        printf("%s", line);
    }

    rewind(file);
    while (fgets(line, sizeof(line), file)) 
    {
        char name[50];
        int mark;
        sscanf(line, "%s %d", name, &mark);
        if (mark >= 50) 
        {
            passedCount++;
        }
    }

    printf("\n\nStudents passed %d out of %d\n", passedCount, lineCount);
    printf("Students failed %d out of %d\n", lineCount - passedCount, lineCount);   
    
    fclose(file);
    return 0;
}