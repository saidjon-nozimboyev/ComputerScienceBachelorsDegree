#ifndef GRADECALC_H
#define GRADECALC_H

// Function declarations
float CalculateFinalGrade(float earnedMarks[], float MaxAllotedMarks[], float weights[], int size);
const char* CalculateLetterGrade(float grade);
float FindMax(float arr[], int size);
float FindSumRecursive(float arr[], int size);
float FindMedian(float arr[], int size);
void SortArray(float arr[], int size);

#endif