#include <stdio.h>

void main()
{
    int cycle;
    printf("Please enter the amount of cycles: ");
    scanf("%d", &cycle);
    for (int i = 1; i <= cycle; i++)
        printf("%d ", i);
}