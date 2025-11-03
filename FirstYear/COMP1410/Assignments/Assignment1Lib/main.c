#include <stdio.h>
#include "gradecalc.h" // include library

int main()
{
    int numComponents;
    printf("Enter number of components: ");
    scanf("%d", &numComponents);

    float earned[numComponents], max[numComponents], weights[numComponents];

    for (int i = 0; i < numComponents; i++)
    {
        printf("Component %d weight (%%): ", i + 1);
        scanf("%f", &weights[i]);
        printf("Max marks: ");
        scanf("%f", &max[i]);
        printf("Earned marks: ");
        scanf("%f", &earned[i]);
    }

    float final = CalculateFinalGrade(earned, max, weights, numComponents);
    const char* letter = CalculateLetterGrade(final);

    printf("\nFinal Weighted Grade: %.2f%%\n", final);
    printf("Letter Grade: %s\n", letter);

    return 0;
}