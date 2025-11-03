#include "gradecalc.h"
#include <math.h>

float CalculateFinalGrade(float earnedMarks[], float MaxAllotedMarks[], float weights[], int size)
{
    double finalGrade = 0.0;
    for (int i = 0; i < size; i++)
        finalGrade += (earnedMarks[i] / MaxAllotedMarks[i]) * (weights[i] / 100) * 100;
    return finalGrade;
}

const char* CalculateLetterGrade(float grade)
{
    int rounded = (int)round(grade);

    if (rounded >= 90 && rounded <= 100)
        return "A+";
    else if (rounded >= 85)
        return "A";
    else if (rounded >= 80)
        return "A-";
    else if (rounded >= 75)
        return "B+";
    else if (rounded >= 70)
        return "B";
    else if (rounded >= 65)
        return "C+";
    else if (rounded >= 60)
        return "C";
    else if (rounded >= 50)
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