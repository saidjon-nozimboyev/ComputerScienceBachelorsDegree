#include <stdio.h>
#include <math.h>

int main()
{
    char input;
    int continueProgram = 1;

    while (continueProgram)
    {
        printf("Welcome to my Command-Line Calculator (CLC) \n");
        printf("Developer: Saidjon Nozimboev\n");
        printf("Version: 1\n");
        printf("Date: 2/28/2025\n");
        printf("\n");

        printf("Select one of the following items: \n");
        printf("B) Binary Mathematical Operations, such as addition and subtraction.\n");
        printf("U) Unary Mathematical Operations, such as square root, and log.\n");
        printf("A) Advances Mathematical Operations, using variables, arrays.\n");
        printf("V) Define variables and assign them values.\n");
        printf("E) Exit\n");

        printf("Please enter operation: ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'b':
        case 'B':
        {
            int num1, num2;
            char operation1;
            char continueBinary = 'y';

            while (continueBinary == 'y' || continueBinary == 'Y')
            {
                printf("Please enter the first number: ");
                scanf("%d", &num1);
                printf("Please enter the operation ( + , - , * , / ): ");
                scanf(" %c", &operation1);

                switch (operation1)
                {
                case '+':
                    printf("Please enter the second number: ");
                    scanf("%d", &num2);
                    printf("The result is: %d\n", num1 + num2);
                    break;
                case '-':
                    printf("Please enter the second number: ");
                    scanf("%d", &num2);
                    printf("The result is: %d\n", num1 - num2);
                    break;
                case '*':
                    printf("Please enter the second number: ");
                    scanf("%d", &num2);
                    printf("The result is: %d\n", num1 * num2);
                    break;
                case '/':
                    printf("Please enter the second number: ");
                    scanf("%d", &num2);
                    if (num2 == 0)
                        printf("Error: Division by zero\n");
                    else
                        printf("The result is: %.2f\n", (float)num1 / num2);
                    break;
                default:
                    printf("Invalid operation. Please try again.\n");
                    continue;
                }

                printf("Do you want to perform another binary operation? (y/n): ");
                scanf(" %c", &continueBinary);
            }
            break;
        }

        case 'u':
        case 'U':
        {
            int num;
            char operation2;
            char continueUnary = 'y'; 

            while (continueUnary == 'y' || continueUnary == 'Y')
            {
                printf("Please enter the number: ");
                scanf("%d", &num);
                printf("Please enter the operation (s - square root, l - log, c - ceiling, f - floor): ");
                scanf(" %c", &operation2);

                switch (operation2)
                {
                case 's':
                case 'S':
                    if (num < 0)
                        printf("Error: Square root of a negative number\n");
                    else
                        printf("The result is: %.2f\n", sqrt(num));
                    break;
                case 'l':
                case 'L':
                    if (num <= 0)
                        printf("Error: Logarithm of a non-positive number\n");
                    else
                        printf("The result is: %.2f\n", log(num));
                    break;
                case 'c':
                case 'C':
                    printf("The result is: %.2f\n", ceil(num));
                    break;
                case 'f':
                case 'F':
                    printf("The result is: %.2f\n", floor(num));
                    break;
                default:
                    printf("Invalid operation. Please try again.\n");
                    continue;
                }

                printf("Do you want to perform another unary operation? (y/n): ");
                scanf(" %c", &continueUnary);
            }
            break;
        }

        case 'v':
        case 'V':
        {
            int a = 0, b = 0, c = 0, d = 0, e = 0;
            char var;
            char continueVariable = 'y'; 

            while (continueVariable == 'y' || continueVariable == 'Y')
            {
                printf("Which variable would you like to define and assign a value to? (a, b, c, d, e): ");
                scanf(" %c", &var);
                switch (var)
                {
                case 'a':
                case 'A':
                    printf("Please enter the value for a: ");
                    scanf("%d", &a);
                    printf("The value of a is: %d\n", a);
                    break;
                case 'b':
                case 'B':
                    printf("Please enter the value for b: ");
                    scanf("%d", &b);
                    printf("The value of b is: %d\n", b);
                    break;
                case 'c':
                case 'C':
                    printf("Please enter the value for c: ");
                    scanf("%d", &c);
                    printf("The value of c is: %d\n", c);
                    break;
                case 'd':
                case 'D':
                    printf("Please enter the value for d: ");
                    scanf("%d", &d);
                    printf("The value of d is: %d\n", d);
                    break;
                case 'e':
                case 'E':
                    printf("Please enter the value for e: ");
                    scanf("%d", &e);
                    printf("The value of e is: %d\n", e);
                    break;
                default:
                    printf("Invalid variable. Please try again.\n");
                    continue;
                }

                printf("Do you want to define another variable? (y/n): ");
                scanf(" %c", &continueVariable);
            }
            break;
        }

        case 'a':
        case 'A':
        {
            char operation3;
            char continueAdvanced = 'y'; 

            while (continueAdvanced == 'y' || continueAdvanced == 'Y')
            {
                printf("Please enter the operation (B, U, E): ");
                scanf(" %c", &operation3);
                switch (operation3)
                {
                case 'b':
                case 'B':
                {
                    int num1, num2;
                    char operation4;
                    printf("Please enter the first number: ");
                    scanf("%d", &num1);
                    printf("Please enter the operation ( + , - , * , / ): ");
                    scanf(" %c", &operation4);

                    switch (operation4)
                    {
                    case '+':
                        printf("Please enter the second number: ");
                        scanf("%d", &num2);
                        printf("The result is: %d\n", num1 + num2);
                        break;
                    case '-':
                        printf("Please enter the second number: ");
                        scanf("%d", &num2);
                        printf("The result is: %d\n", num1 - num2);
                        break;
                    case '*':
                        printf("Please enter the second number: ");
                        scanf("%d", &num2);
                        printf("The result is: %d\n", num1 * num2);
                        break;
                    case '/':
                        printf("Please enter the second number: ");
                        scanf("%d", &num2);
                        if (num2 == 0)
                            printf("Error: Division by zero\n");
                        else
                            printf("The result is: %.2f\n", (float)num1 / num2);
                        break;
                    default:
                        printf("Invalid operation. Please try again.\n");
                        continue; 
                    }
                    break;
                }

                case 'u':
                case 'U':
                {
                    int num;
                    char operation5;
                    printf("Please enter the number: ");
                    scanf("%d", &num);
                    printf("Please enter the operation (s - square root, l - log, c - ceiling, f - floor): ");
                    scanf(" %c", &operation5);

                    switch (operation5)
                    {
                    case 's':
                    case 'S':
                        if (num < 0)
                            printf("Error: Square root of a negative number\n");
                        else
                            printf("The result is: %.2f\n", sqrt(num));
                        break;
                    case 'l':
                    case 'L':
                        if (num <= 0)
                            printf("Error: Logarithm of a non-positive number\n");
                        else
                            printf("The result is: %.2f\n", log(num));
                        break;
                    case 'c':
                    case 'C':
                        printf("The result is: %.2f\n", ceil(num));
                        break;
                    case 'f':
                    case 'F':
                        printf("The result is: %.2f\n", floor(num));
                        break;
                    default:
                        printf("Invalid operation. Please try again.\n");
                        continue; 
                    }
                    break;
                }

                case 'e':
                case 'E':
                    printf("Returning to the main menu.\n");
                    continueAdvanced = 'n'; 
                    break;

                default:
                    printf("Invalid operation. Please try again.\n");
                    continue; 
                }

                if (continueAdvanced == 'y' || continueAdvanced == 'Y')
                {
                    printf("Do you want to perform another advanced operation? (y/n): ");
                    scanf(" %c", &continueAdvanced);
                }
            }
            break;
        }

        case 'e':
        case 'E':
            printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");
            continueProgram = 0;
            break;

        default:
            printf("Invalid operation. Please try again.\n");
            break;
        }
    }

    return 0;
}