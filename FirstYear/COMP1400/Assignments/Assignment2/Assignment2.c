#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Basic math operations
float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mult(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }
float mod(float a, float b) { return fmodf(a, b); }
float power(float a, float b) { return powf(a, b); }
float findMax(float a, float b) { return fmaxf(a, b); }
float findMin(float a, float b) { return fminf(a, b); }

// Unary operations
float squareRoot(float a) { return sqrtf(a); }
float logarithm(float a) { return logf(a); }
float exponent(float a) { return expf(a); }
float ceiling(float a) { return ceilf(a); }
float floorVal(float a) { return floorf(a); }

float getValidNumber()
{
    char input[100];
    int i = 0, foundDigit = 0;
    float num;

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        for (i = 0; input[i] != '\0'; i++)
        {
            if (isdigit(input[i]) || input[i] == '.' || input[i] == '-')
            {
                if (sscanf(&input[i], "%f", &num) == 1)
                {
                    foundDigit = 1;
                    break;
                }
            }
        }
        if (foundDigit)
            return num;
        else
            printf("Invalid input. Please enter a valid number: ");
    }
}

float getNumberOrVariable(float a, float b, float c, float d, float e)
{
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character
    input[strcspn(input, "\n")] = 0;
    
    if (strlen(input) == 1 && input[0] >= 'a' && input[0] <= 'e')
    {
        switch(input[0])
        {
            case 'a': return a;
            case 'b': return b;
            case 'c': return c;
            case 'd': return d;
            case 'e': return e;
        }
    }
    
    float num;
    if (sscanf(input, "%f", &num) == 1)
        return num;
        
    printf("Invalid input. Please enter a valid number or variable (a-e): ");
    return getNumberOrVariable(a, b, c, d, e);
}

void performBinaryOperation(float num1, float num2, char operation)
{
    switch (operation)
    {
    case '+':
        printf("The result is: %.2f\n", add(num1, num2));
        break;
    case '-':
        printf("The result is: %.2f\n", sub(num1, num2));
        break;
    case '*':
        printf("The result is: %.2f\n", mult(num1, num2));
        break;
    case '/':
        if (num2 == 0)
            printf("Error: Division by zero\n");
        else
            printf("The result is: %.2f\n", divide(num1, num2));
        break;
    case '%':
        if (num2 == 0)
            printf("Error: Division by zero\n");
        else
            printf("The result is: %.2f\n", mod(num1, num2));
        break;
    case 'p':
    case 'P':
        printf("The result is: %.2f\n", power(num1, num2));
        break;
    case 'x':
    case 'X':
        printf("The result is: %.2f\n", findMax(num1, num2));
        break;
    case 'i':
    case 'I':
        printf("The result is: %.2f\n", findMin(num1, num2));
        break;
    default:
        printf("Invalid operation. Please try again.\n");
    }
}

void performUnaryOperation(float num, char operation)
{
    switch (operation)
    {
    case 's':
    case 'S':
        if (num < 0)
            printf("Error: Square root of a negative number\n");
        else
            printf("The result is: %.2f\n", squareRoot(num));
        break;
    case 'l':
    case 'L':
        if (num <= 0)
            printf("Error: Logarithm of a non-positive number\n");
        else
            printf("The result is: %.2f\n", logarithm(num));
        break;
    case 'e':
    case 'E':
        printf("The result is: %.2f\n", exponent(num));
        break;
    case 'c':
    case 'C':
        printf("The result is: %.2f\n", ceiling(num));
        break;
    case 'f':
    case 'F':
        printf("The result is: %.2f\n", floorVal(num));
        break;
    default:
        printf("Invalid operation. Please try again.\n");
    }
}

void defineVariable(float *var)
{
    printf("Please enter the value: ");
    *var = getValidNumber();
    printf("The value is: %.2f\n", *var);
}

void handleBinaryOperations(float a, float b, float c, float d, float e)
{
    float num1, num2;
    char operation;
    char input[100];

    printf("Please enter the first number or variable (a-e): ");
    num1 = getNumberOrVariable(a, b, c, d, e);

    printf("Please enter the operation ( + , - , * , / , %% , P , X , I ): ");
    fgets(input, sizeof(input), stdin);
    operation = input[0];

    printf("Please enter the second number or variable (a-e): ");
    num2 = getNumberOrVariable(a, b, c, d, e);

    performBinaryOperation(num1, num2, operation);
}

void handleUnaryOperations(float a, float b, float c, float d, float e)
{
    float num;
    char operation;
    char input[100];

    printf("Please enter the number or variable (a-e): ");
    num = getNumberOrVariable(a, b, c, d, e);

    printf("Please enter the operation (s - square root, l - log, e - exp, c - ceiling, f - floor): ");
    fgets(input, sizeof(input), stdin);
    operation = input[0];

    performUnaryOperation(num, operation);
}

void displayMenu()
{
    printf("\nWelcome to my Command-Line Calculator (CLC) \n");
    printf("Developer: Saidjon Nozimboev\n");
    printf("Version: 1\n");
    printf("Date: 2/28/2025\n");
    printf("\n");

    printf("Select one of the following items: \n");
    printf("B) Binary Mathematical Operations, such as addition and subtraction.\n");
    printf("U) Unary Mathematical Operations, such as square root, and log.\n");
    printf("A) Advanced Mathematical Operations, using variables, arrays.\n");
    printf("V) Define variables and assign them values.\n");
    printf("E) Exit\n");

    printf("Please enter operation: ");
}

int main()
{
    char input;
    int continueProgram = 1;
    float a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;

    while (continueProgram)
    {
        displayMenu();
        scanf(" %c", &input);
        while (getchar() != '\n')
            ;

        switch (input)
        {
        case 'b':
        case 'B':
        {
            float num1, num2;
            char operation;
            char continueBinary = 'y';

            while (continueBinary == 'y' || continueBinary == 'Y')
            {
                printf("Please enter the first number: ");
                num1 = getValidNumber();

                printf("Please enter the operation ( + , - , * , / , %% , P , X , I ): ");
                scanf(" %c", &operation);
                while (getchar() != '\n')
                    ;

                printf("Please enter the second number: ");
                num2 = getValidNumber();

                performBinaryOperation(num1, num2, operation);

                printf("Do you want to perform another binary operation? (y/n): ");
                scanf(" %c", &continueBinary);
                while (getchar() != '\n')
                    ;
            }
            break;
        }

        case 'u':
        case 'U':
        {
            float num;
            char operation;
            char continueUnary = 'y';

            while (continueUnary == 'y' || continueUnary == 'Y')
            {
                printf("Please enter the number: ");
                num = getValidNumber();

                printf("Please enter the operation (s - square root, l - log, e - exp, c - ceiling, f - floor): ");
                scanf(" %c", &operation);
                while (getchar() != '\n')
                    ;

                performUnaryOperation(num, operation);

                printf("Do you want to perform another unary operation? (y/n): ");
                scanf(" %c", &continueUnary);
                while (getchar() != '\n')
                    ;
            }
            break;
        }

        case 'v':
        case 'V':
        {
            char var;
            char continueVariable = 'y';

            while (continueVariable == 'y' || continueVariable == 'Y')
            {
                printf("Which variable would you like to define and assign a value to? (a, b, c, d, e): ");
                scanf(" %c", &var);
                while (getchar() != '\n')
                    ;

                switch (var)
                {
                case 'a':
                case 'A':
                    defineVariable(&a);
                    break;
                case 'b':
                case 'B':
                    defineVariable(&b);
                    break;
                case 'c':
                case 'C':
                    defineVariable(&c);
                    break;
                case 'd':
                case 'D':
                    defineVariable(&d);
                    break;
                case 'e':
                case 'E':
                    defineVariable(&e);
                    break;
                default:
                    printf("Invalid variable. Please try again.\n");
                    continue;
                }

                printf("Do you want to define another variable? (y/n): ");
                scanf(" %c", &continueVariable);
                while (getchar() != '\n')
                    ;
            }
            break;
        }

        case 'a':
        case 'A':
        {
            char operation;
            char continueAdvanced = 'y';

            while (continueAdvanced == 'y' || continueAdvanced == 'Y')
            {
                printf("Please enter the operation (B, U, E): ");
                scanf(" %c", &operation);
                while (getchar() != '\n')
                    ;

                switch (operation)
                {
                case 'b':
                case 'B':
                    handleBinaryOperations(a, b, c, d, e);
                    break;
                case 'u':
                case 'U':
                    handleUnaryOperations(a, b, c, d, e);
                    break;
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
                    while (getchar() != '\n')
                        ;
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