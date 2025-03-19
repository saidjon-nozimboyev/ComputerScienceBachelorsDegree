#include <stdio.h>

float findArea(float radius);

int main()
{
    float radius;
    printf("Please enter radius: ");
    scanf("%f", &radius);
    printf("Area is %.3f", findArea(radius));
}

float findArea(float radius)
{
    return 3.14 * radius * radius;
}