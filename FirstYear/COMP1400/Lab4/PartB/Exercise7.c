#include <stdio.h>

int main(void)
{
    printf("My name is Saidjon\n");
    printf("StudentID: 110186060\n");
    float num1;
    float num2;
    double sum;

    printf("Enter first number: \n");
    scanf("%f", &num1);
    printf("Enter second number: \n");
    scanf("%f", &num2);
    sum = num1 + num2;
    // printf("Sum of the entered numbers: %.2f\n", sum);
    // printf("Subtraction of entered numbers: %.2f\n",num1-num2);
    // printf("Multiplication of entered numbers: %.2f\n", num1*num2);
    // if (num2 != 0)
    //     printf("Division of entered numbers: %.2f\n", num1/num2);
    // else
    //     printf("Dividing by zero is undefined\n");
    printf("------------------------------------------------------------\n");
    printf("|                                                           |\n");
    printf("|            %f  +  %f =   %.3f                             |\n", num1,num2, sum);
    printf("|                                                           |\n");
    printf("------------------------------------------------------------\n");
    
    printf("------------------------------------------------------------\n");
    printf("|                                                           |\n");
    printf("|            %f  -   %f =   %.3f                            |\n", num1,num2, num1-num2);
    printf("|                                                           |\n");
    printf("------------------------------------------------------------\n");
    printf("------------------------------------------------------------\n");
    printf("|                                                           |\n");
    printf("|            %f  *   %f =   %.3f                            |\n", num1,num2, num1*num2);
    printf("|                                                           |\n");
    printf("------------------------------------------------------------\n");

    if (num2!=0)
    {
        printf("------------------------------------------------------------\n");
        printf("|                                                           |\n");
        printf("|            %f  -   %f =   %.3f                            |\n", num1,num2, num1-num2);
        printf("|                                                           |\n");
        printf("------------------------------------------------------------\n");
    }
    else
    {
        printf("Dividing by zero is undefined\n");    
    }
    return 0;
}