// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     char input;
//     int continueProgram = 1;

//     while (continueProgram)
//     {
//         printf("Welcome to my Command-Line Calculator (CLC) \n");
//         printf("Developer: Saidjon Nozimboev\n");
//         printf("Version: 1\n");
//         printf("Date: 2/28/2025\n");
//         printf("\n");

//         printf("Select one of the following items: \n");
//         printf("B) Binary Mathematical Operations, such as addition and subtraction.\n");
//         printf("U) Unary Mathematical Operations, such as square root, and log.\n");
//         printf("A) Advances Mathematical Operations, using variables, arrays.\n");
//         printf("V) Define variables and assign them values.\n");
//         printf("E) Exit\n");

//         printf("Please enter operation: ");
//         scanf(" %c", &input);

//         switch (input)
//         {
//         case 'b':
//         case 'B':
//         {
//             int num1, num2;
//             char operation1;
//             char continueBinary = 'y';

//             while (continueBinary == 'y' || continueBinary == 'Y')
//             {
//                 printf("Please enter the first number: ");
//                 scanf("%d", &num1);
//                 printf("Please enter the operation ( + , - , * , / ): ");
//                 scanf(" %c", &operation1);

//                 switch (operation1)
//                 {
//                 case '+':
//                     printf("Please enter the second number: ");
//                     scanf("%d", &num2);
//                     printf("The result is: %d\n", num1 + num2);
//                     break;
//                 case '-':
//                     printf("Please enter the second number: ");
//                     scanf("%d", &num2);
//                     printf("The result is: %d\n", num1 - num2);
//                     break;
//                 case '*':
//                     printf("Please enter the second number: ");
//                     scanf("%d", &num2);
//                     printf("The result is: %d\n", num1 * num2);
//                     break;
//                 case '/':
//                     printf("Please enter the second number: ");
//                     scanf("%d", &num2);
//                     if (num2 == 0)
//                         printf("Error: Division by zero\n");
//                     else
//                         printf("The result is: %.2f\n", (float)num1 / num2);
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }

//                 printf("Do you want to perform another binary operation? (y/n): ");
//                 scanf(" %c", &continueBinary);
//             }
//             break;
//         }

//         case 'u':
//         case 'U':
//         {
//             int num;
//             char operation2;
//             char continueUnary = 'y';

//             while (continueUnary == 'y' || continueUnary == 'Y')
//             {
//                 printf("Please enter the number: ");
//                 scanf("%d", &num);
//                 printf("Please enter the operation (s - square root, l - log, c - ceiling, f - floor): ");
//                 scanf(" %c", &operation2);

//                 switch (operation2)
//                 {
//                 case 's':
//                 case 'S':
//                     if (num < 0)
//                         printf("Error: Square root of a negative number\n");
//                     else
//                         printf("The result is: %.2f\n", sqrt(num));
//                     break;
//                 case 'l':
//                 case 'L':
//                     if (num <= 0)
//                         printf("Error: Logarithm of a non-positive number\n");
//                     else
//                         printf("The result is: %.2f\n", log(num));
//                     break;
//                 case 'c':
//                 case 'C':
//                     printf("The result is: %.2f\n", ceil(num));
//                     break;
//                 case 'f':
//                 case 'F':
//                     printf("The result is: %.2f\n", floor(num));
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }

//                 printf("Do you want to perform another unary operation? (y/n): ");
//                 scanf(" %c", &continueUnary);
//             }
//             break;
//         }

//         case 'v':
//         case 'V':
//         {
//             int a = 0, b = 0, c = 0, d = 0, e = 0;
//             char var;
//             char continueVariable = 'y';

//             while (continueVariable == 'y' || continueVariable == 'Y')
//             {
//                 printf("Which variable would you like to define and assign a value to? (a, b, c, d, e): ");
//                 scanf(" %c", &var);
//                 switch (var)
//                 {
//                 case 'a':
//                 case 'A':
//                     printf("Please enter the value for a: ");
//                     scanf("%d", &a);
//                     printf("The value of a is: %d\n", a);
//                     break;
//                 case 'b':
//                 case 'B':
//                     printf("Please enter the value for b: ");
//                     scanf("%d", &b);
//                     printf("The value of b is: %d\n", b);
//                     break;
//                 case 'c':
//                 case 'C':
//                     printf("Please enter the value for c: ");
//                     scanf("%d", &c);
//                     printf("The value of c is: %d\n", c);
//                     break;
//                 case 'd':
//                 case 'D':
//                     printf("Please enter the value for d: ");
//                     scanf("%d", &d);
//                     printf("The value of d is: %d\n", d);
//                     break;
//                 case 'e':
//                 case 'E':
//                     printf("Please enter the value for e: ");
//                     scanf("%d", &e);
//                     printf("The value of e is: %d\n", e);
//                     break;
//                 default:
//                     printf("Invalid variable. Please try again.\n");
//                     continue;
//                 }

//                 printf("Do you want to define another variable? (y/n): ");
//                 scanf(" %c", &continueVariable);
//             }
//             break;
//         }

//         case 'a':
//         case 'A':
//         {
//             char operation3;
//             char continueAdvanced = 'y';

//             while (continueAdvanced == 'y' || continueAdvanced == 'Y')
//             {
//                 printf("Please enter the operation (B, U, E): ");
//                 scanf(" %c", &operation3);
//                 switch (operation3)
//                 {
//                 case 'b':
//                 case 'B':
//                 {
//                     int num1, num2;
//                     char operation4;
//                     printf("Please enter the first number: ");
//                     scanf("%d", &num1);
//                     printf("Please enter the operation ( + , - , * , / ): ");
//                     scanf(" %c", &operation4);

//                     switch (operation4)
//                     {
//                     case '+':
//                         printf("Please enter the second number: ");
//                         scanf("%d", &num2);
//                         printf("The result is: %d\n", num1 + num2);
//                         break;
//                     case '-':
//                         printf("Please enter the second number: ");
//                         scanf("%d", &num2);
//                         printf("The result is: %d\n", num1 - num2);
//                         break;
//                     case '*':
//                         printf("Please enter the second number: ");
//                         scanf("%d", &num2);
//                         printf("The result is: %d\n", num1 * num2);
//                         break;
//                     case '/':
//                         printf("Please enter the second number: ");
//                         scanf("%d", &num2);
//                         if (num2 == 0)
//                             printf("Error: Division by zero\n");
//                         else
//                             printf("The result is: %.2f\n", (float)num1 / num2);
//                         break;
//                     default:
//                         printf("Invalid operation. Please try again.\n");
//                         continue;
//                     }
//                     break;
//                 }

//                 case 'u':
//                 case 'U':
//                 {
//                     int num;
//                     char operation5;
//                     printf("Please enter the number: ");
//                     scanf("%d", &num);
//                     printf("Please enter the operation (s - square root, l - log, c - ceiling, f - floor): ");
//                     scanf(" %c", &operation5);

//                     switch (operation5)
//                     {
//                     case 's':
//                     case 'S':
//                         if (num < 0)
//                             printf("Error: Square root of a negative number\n");
//                         else
//                             printf("The result is: %.2f\n", sqrt(num));
//                         break;
//                     case 'l':
//                     case 'L':
//                         if (num <= 0)
//                             printf("Error: Logarithm of a non-positive number\n");
//                         else
//                             printf("The result is: %.2f\n", log(num));
//                         break;
//                     case 'c':
//                     case 'C':
//                         printf("The result is: %.2f\n", ceil(num));
//                         break;
//                     case 'f':
//                     case 'F':
//                         printf("The result is: %.2f\n", floor(num));
//                         break;
//                     default:
//                         printf("Invalid operation. Please try again.\n");
//                         continue;
//                     }
//                     break;
//                 }

//                 case 'e':
//                 case 'E':
//                     printf("Returning to the main menu.\n");
//                     continueAdvanced = 'n';
//                     break;

//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }

//                 if (continueAdvanced == 'y' || continueAdvanced == 'Y')
//                 {
//                     printf("Do you want to perform another advanced operation? (y/n): ");
//                     scanf(" %c", &continueAdvanced);
//                 }
//             }
//             break;
//         }

//         case 'e':
//         case 'E':
//             printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");
//             continueProgram = 0;
//             break;

//         default:
//             printf("Invalid operation. Please try again.\n");
//             break;
//         }
//     }

//     return 0;
// }
/**/
// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     char input;
//     int continueProgram = 1;
//     float a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;

//     while (continueProgram)
//     {
//         printf("Welcome to my Command-Line Calculator (CLC) \n");
//         printf("Developer: Saidjon Nozimboev\n");
//         printf("Version: 1\n");
//         printf("Date: 2/28/2025\n");
//         printf("\n");

//         printf("Select one of the following items: \n");
//         printf("B) Binary Mathematical Operations, such as addition and subtraction.\n");
//         printf("U) Unary Mathematical Operations, such as square root, and log.\n");
//         printf("A) Advanced Mathematical Operations, using variables, arrays.\n");
//         printf("V) Define variables and assign them values.\n");
//         printf("E) Exit\n");

//         printf("Please enter operation: ");
//         scanf(" %c", &input);

//         switch (input)
//         {
//         case 'b':
//         case 'B':
//         {
//             float num1, num2;
//             char operation1;
//             char continueBinary = 'y';

//             while (continueBinary == 'y' || continueBinary == 'Y')
//             {
//                 printf("Please enter the first number: ");
//                 scanf("%f", &num1);
//                 printf("Please enter the operation ( + , - , * , / , %% , P , X , I ): ");
//                 scanf(" %c", &operation1);

//                 switch (operation1)
//                 {
//                 case '+':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     printf("The result is: %.2f\n", num1 + num2);
//                     break;
//                 case '-':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     printf("The result is: %.2f\n", num1 - num2);
//                     break;
//                 case '*':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     printf("The result is: %.2f\n", num1 * num2);
//                     break;
//                 case '/':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     if (num2 == 0)
//                         printf("Error: Division by zero\n");
//                     else
//                         printf("The result is: %.2f\n", num1 / num2);
//                     break;
//                 case '%':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     if (num2 == 0)
//                         printf("Error: Division by zero\n");
//                     else
//                         printf("The result is: %.2f\n", fmodf(num1, num2));
//                     break;
//                 case 'p':
//                 case 'P':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     printf("The result is: %.2f\n", powf(num1, num2));
//                     break;
//                 case 'x':
//                 case 'X':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     printf("The result is: %.2f\n", fmaxf(num1, num2));
//                     break;
//                 case 'i':
//                 case 'I':
//                     printf("Please enter the second number: ");
//                     scanf("%f", &num2);
//                     printf("The result is: %.2f\n", fminf(num1, num2));
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }

//                 printf("Do you want to perform another binary operation? (y/n): ");
//                 scanf(" %c", &continueBinary);
//             }
//             break;
//         }

//         case 'u':
//         case 'U':
//         {
//             float num;
//             char operation2;
//             char continueUnary = 'y';

//             while (continueUnary == 'y' || continueUnary == 'Y')
//             {
//                 printf("Please enter the number: ");
//                 scanf("%f", &num);
//                 printf("Please enter the operation (s - square root, l - log, e - exp, c - ceiling, f - floor): ");
//                 scanf(" %c", &operation2);

//                 switch (operation2)
//                 {
//                 case 's':
//                 case 'S':
//                     if (num < 0)
//                         printf("Error: Square root of a negative number\n");
//                     else
//                         printf("The result is: %.2f\n", sqrtf(num));
//                     break;
//                 case 'l':
//                 case 'L':
//                     if (num <= 0)
//                         printf("Error: Logarithm of a non-positive number\n");
//                     else
//                         printf("The result is: %.2f\n", logf(num));
//                     break;
//                 case 'e':
//                 case 'E':
//                     printf("The result is: %.2f\n", expf(num));
//                     break;
//                 case 'c':
//                 case 'C':
//                     printf("The result is: %.2f\n", ceilf(num));
//                     break;
//                 case 'f':
//                 case 'F':
//                     printf("The result is: %.2f\n", floorf(num));
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }

//                 printf("Do you want to perform another unary operation? (y/n): ");
//                 scanf(" %c", &continueUnary);
//             }
//             break;
//         }

//         case 'v':
//         case 'V':
//         {
//             char var;
//             char continueVariable = 'y';

//             while (continueVariable == 'y' || continueVariable == 'Y')
//             {
//                 printf("Which variable would you like to define and assign a value to? (a, b, c, d, e): ");
//                 scanf(" %c", &var);
//                 switch (var)
//                 {
//                 case 'a':
//                 case 'A':
//                     printf("Please enter the value for a: ");
//                     scanf("%f", &a);
//                     printf("The value of a is: %.2f\n", a);
//                     break;
//                 case 'b':
//                 case 'B':
//                     printf("Please enter the value for b: ");
//                     scanf("%f", &b);
//                     printf("The value of b is: %.2f\n", b);
//                     break;
//                 case 'c':
//                 case 'C':
//                     printf("Please enter the value for c: ");
//                     scanf("%f", &c);
//                     printf("The value of c is: %.2f\n", c);
//                     break;
//                 case 'd':
//                 case 'D':
//                     printf("Please enter the value for d: ");
//                     scanf("%f", &d);
//                     printf("The value of d is: %.2f\n", d);
//                     break;
//                 case 'e':
//                 case 'E':
//                     printf("Please enter the value for e: ");
//                     scanf("%f", &e);
//                     printf("The value of e is: %.2f\n", e);
//                     break;
//                 default:
//                     printf("Invalid variable. Please try again.\n");
//                     continue;
//                 }

//                 printf("Do you want to define another variable? (y/n): ");
//                 scanf(" %c", &continueVariable);
//             }
//             break;
//         }

//         case 'a':
//         case 'A':
//         {
//             char operation3;
//             char continueAdvanced = 'y';

//             while (continueAdvanced == 'y' || continueAdvanced == 'Y')
//             {
//                 printf("Please enter the operation (B, U, E): ");
//                 scanf(" %c", &operation3);
//                 switch (operation3)
//                 {
//                 case 'b':
//                 case 'B':
//                 {
//                     float num1, num2;
//                     char operation4;
//                     char input1[2], input2[2];

//                     printf("Please enter the first number or variable (a-e): ");
//                     scanf("%s", input1);
//                     if (input1[0] >= 'a' && input1[0] <= 'e')
//                         num1 = (input1[0] == 'a') ? a : (input1[0] == 'b') ? b
//                                                       : (input1[0] == 'c')   ? c
//                                                       : (input1[0] == 'd')   ? d
//                                                                            : e;
//                     else
//                         sscanf(input1, "%f", &num1);

//                     printf("Please enter the operation ( + , - , * , / , %% , P , X , I ): ");
//                     scanf(" %c", &operation4);

//                     printf("Please enter the second number or variable (a-e): ");
//                     scanf("%s", input2);
//                     if (input2[0] >= 'a' && input2[0] <= 'e')
//                         num2 = (input2[0] == 'a') ? a : (input2[0] == 'b') ? b
//                                                     : (input2[0] == 'c')   ? c
//                                                     : (input2[0] == 'd')   ? d
//                                                                            : e;
//                     else
//                         sscanf(input2, "%f", &num2);

//                     switch (operation4)
//                     {
//                     case '+':
//                         printf("The result is: %.2f\n", num1 + num2);
//                         break;
//                     case '-':
//                         printf("The result is: %.2f\n", num1 - num2);
//                         break;
//                     case '*':
//                         printf("The result is: %.2f\n", num1 * num2);
//                         break;
//                     case '/':
//                         if (num2 == 0)
//                             printf("Error: Division by zero\n");
//                         else
//                             printf("The result is: %.2f\n", num1 / num2);
//                         break;
//                     case '%':
//                         if (num2 == 0)
//                             printf("Error: Division by zero\n");
//                         else
//                             printf("The result is: %.2f\n", fmodf(num1, num2));
//                         break;
//                     case 'P':
//                         printf("The result is: %.2f\n", powf(num1, num2));
//                         break;
//                     case 'X':
//                         printf("The result is: %.2f\n", fmaxf(num1, num2));
//                         break;
//                     case 'I':
//                         printf("The result is: %.2f\n", fminf(num1, num2));
//                         break;
//                     default:
//                         printf("Invalid operation. Please try again.\n");
//                         continue;
//                     }
//                     break;
//                 }

//                 case 'u':
//                 case 'U':
//                 {
//                     float num;
//                     char operation5;
//                     char input[2];

//                     printf("Please enter the number or variable (a-e): ");
//                     scanf("%s", input);
//                     if (input[0] >= 'a' && input[0] <= 'e')
//                         num = (input[0] == 'a') ? a : (input[0] == 'b') ? b
//                                                   : (input[0] == 'c')   ? c
//                                                   : (input[0] == 'd')   ? d
//                                                                         : e;
//                     else
//                         sscanf(input, "%f", &num);

//                     printf("Please enter the operation (s - square root, l - log, e - exp, c - ceiling, f - floor): ");
//                     scanf(" %c", &operation5);

//                     switch (operation5)
//                     {
//                     case 's':
//                     case 'S':
//                         if (num < 0)
//                             printf("Error: Square root of a negative number\n");
//                         else
//                             printf("The result is: %.2f\n", sqrtf(num));
//                         break;
//                     case 'l':
//                     case 'L':
//                         if (num <= 0)
//                             printf("Error: Logarithm of a non-positive number\n");
//                         else
//                             printf("The result is: %.2f\n", logf(num));
//                         break;
//                     case 'e':
//                     case 'E':
//                         printf("The result is: %.2f\n", expf(num));
//                         break;
//                     case 'c':
//                     case 'C':
//                         printf("The result is: %.2f\n", ceilf(num));
//                         break;
//                     case 'f':
//                     case 'F':
//                         printf("The result is: %.2f\n", floorf(num));
//                         break;
//                     default:
//                         printf("Invalid operation. Please try again.\n");
//                         continue;
//                     }
//                     break;
//                 }

//                 case 'e':
//                 case 'E':
//                     printf("Returning to the main menu.\n");
//                     continueAdvanced = 'n';
//                     break;

//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }

//                 if (continueAdvanced == 'y' || continueAdvanced == 'Y')
//                 {
//                     printf("Do you want to perform another advanced operation? (y/n): ");
//                     scanf(" %c", &continueAdvanced);
//                 }
//             }
//             break;
//         }

//         case 'e':
//         case 'E':
//             printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");
//             continueProgram = 0;
//             break;

//         default:
//             printf("Invalid operation. Please try again.\n");
//             break;
//         }
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// #include <ctype.h>

// // Function to extract a valid number from input
// float getValidNumber()
// {
//     char input[100];
//     int i = 0, foundDigit = 0;
//     float num;
    
//     while (1)
//     {
//         fgets(input, sizeof(input), stdin); // Get input as a string
        
//         // Extract first valid number
//         for (i = 0; input[i] != '\0'; i++)
//         {
//             if (isdigit(input[i]) || input[i] == '.' || input[i] == '-')
//             {
//                 if (sscanf(&input[i], "%f", &num) == 1)
//                 {
//                     foundDigit = 1;
//                     break;
//                 }
//             }
//         }
        
//         if (foundDigit)
//             return num;
//         else
//             printf("Invalid input. Please enter a valid number: ");
//     }
// }

// int main()
// {
//     char input;
//     int continueProgram = 1;

//     while (continueProgram)
//     {
//         printf("Welcome to my Command-Line Calculator (CLC) \n");
//         printf("Developer: Saidjon Nozimboev\n");
//         printf("Version: 1\n");
//         printf("Date: 2/28/2025\n\n");

//         printf("Select one of the following items: \n");
//         printf("B) Binary Mathematical Operations, such as addition and subtraction.\n");
//         printf("E) Exit\n");

//         printf("Please enter operation: ");
//         scanf(" %c", &input);
//         while (getchar() != '\n'); // Clear input buffer

//         switch (input)
//         {
//         case 'b':
//         case 'B':
//         {
//             float num1, num2;
//             char operation1;
//             char continueBinary = 'y';

//             while (continueBinary == 'y' || continueBinary == 'Y')
//             {
//                 printf("Please enter the first number: ");
//                 num1 = getValidNumber();
                
//                 printf("Please enter the operation ( + , - , * , / ): ");
//                 scanf(" %c", &operation1);
//                 while (getchar() != '\n'); // Clear input buffer
                
//                 printf("Please enter the second number: ");
//                 num2 = getValidNumber();
                
//                 switch (operation1)
//                 {
//                 case '+':
//                     printf("The result is: %.2f\n", num1 + num2);
//                     break;
//                 case '-':
//                     printf("The result is: %.2f\n", num1 - num2);
//                     break;
//                 case '*':
//                     printf("The result is: %.2f\n", num1 * num2);
//                     break;
//                 case '/':
//                     if (num2 == 0)
//                         printf("Error: Division by zero\n");
//                     else
//                         printf("The result is: %.2f\n", num1 / num2);
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }
                
//                 printf("Do you want to perform another binary operation? (y/n): ");
//                 scanf(" %c", &continueBinary);
//                 while (getchar() != '\n'); // Clear input buffer
//             }
//             break;
//         }
        
//         case 'e':
//         case 'E':
//             printf("Thanks for using my Simple Calculator. Goodbye!\n");
//             continueProgram = 0;
//             break;
        
//         default:
//             printf("Invalid operation. Please try again.\n");
//             break;
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// #include <ctype.h>

// // Function to extract a valid number from input
// float getValidNumber()
// {
//     char input[100];
//     int i = 0, foundDigit = 0;
//     float num;
    
//     while (1)
//     {
//         fgets(input, sizeof(input), stdin);
//         for (i = 0; input[i] != '\0'; i++)
//         {
//             if (isdigit(input[i]) || input[i] == '.' || input[i] == '-')
//             {
//                 if (sscanf(&input[i], "%f", &num) == 1)
//                 {
//                     foundDigit = 1;
//                     break;
//                 }
//             }
//         }
//         if (foundDigit)
//             return num;
//         else
//             printf("Invalid input. Please enter a valid number: ");
//     }
// }

// int main()
// {
//     char input;
//     int continueProgram = 1;

//     while (continueProgram)
//     {
//         printf("Welcome to my Command-Line Calculator (CLC) \n");
//         printf("Developer: Saidjon Nozimboev\n");
//         printf("Version: 1\n");
//         printf("Date: 2/28/2025\n\n");

//         printf("Select one of the following items: \n");
//         printf("B) Binary Mathematical Operations, such as addition and subtraction.\n");
//         printf("U) Unary Mathematical Operations, such as square root, and log.\n");
//         printf("E) Exit\n");

//         printf("Please enter operation: ");
//         scanf(" %c", &input);
//         while (getchar() != '\n');

//         switch (input)
//         {
//         case 'b':
//         case 'B':
//         {
//             float num1, num2;
//             char operation1;
//             char continueBinary = 'y';

//             while (continueBinary == 'y' || continueBinary == 'Y')
//             {
//                 printf("Please enter the first number: ");
//                 num1 = getValidNumber();
                
//                 printf("Please enter the operation ( + , - , * , / ): ");
//                 scanf(" %c", &operation1);
//                 while (getchar() != '\n');
                
//                 printf("Please enter the second number: ");
//                 num2 = getValidNumber();
                
//                 switch (operation1)
//                 {
//                 case '+':
//                     printf("The result is: %.2f\n", num1 + num2);
//                     break;
//                 case '-':
//                     printf("The result is: %.2f\n", num1 - num2);
//                     break;
//                 case '*':
//                     printf("The result is: %.2f\n", num1 * num2);
//                     break;
//                 case '/':
//                     if (num2 == 0)
//                         printf("Error: Division by zero\n");
//                     else
//                         printf("The result is: %.2f\n", num1 / num2);
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }
                
//                 printf("Do you want to perform another binary operation? (y/n): ");
//                 scanf(" %c", &continueBinary);
//                 while (getchar() != '\n');
//             }
//             break;
//         }
        
//         case 'u':
//         case 'U':
//         {
//             float num;
//             char operation2;
//             char continueUnary = 'y';

//             while (continueUnary == 'y' || continueUnary == 'Y')
//             {
//                 printf("Please enter the number: ");
//                 num = getValidNumber();
                
//                 printf("Please enter the operation (s - square root, l - log, e - exp): ");
//                 scanf(" %c", &operation2);
//                 while (getchar() != '\n');

//                 switch (operation2)
//                 {
//                 case 's':
//                 case 'S':
//                     if (num < 0)
//                         printf("Error: Square root of a negative number\n");
//                     else
//                         printf("The result is: %.2f\n", sqrtf(num));
//                     break;
//                 case 'l':
//                 case 'L':
//                     if (num <= 0)
//                         printf("Error: Logarithm of a non-positive number\n");
//                     else
//                         printf("The result is: %.2f\n", logf(num));
//                     break;
//                 case 'e':
//                 case 'E':
//                     printf("The result is: %.2f\n", expf(num));
//                     break;
//                 default:
//                     printf("Invalid operation. Please try again.\n");
//                     continue;
//                 }
                
//                 printf("Do you want to perform another unary operation? (y/n): ");
//                 scanf(" %c", &continueUnary);
//                 while (getchar() != '\n');
//             }
//             break;
//         }
        
//         case 'e':
//         case 'E':
//             printf("Thanks for using my Simple Calculator. Goodbye!\n");
//             continueProgram = 0;
//             break;
        
//         default:
//             printf("Invalid operation. Please try again.\n");
//             break;
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Function to extract a valid number from input
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

int main()
{
    char input;
    int continueProgram = 1;
    float a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0;

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
        printf("A) Advanced Mathematical Operations, using variables, arrays.\n");
        printf("V) Define variables and assign them values.\n");
        printf("E) Exit\n");

        printf("Please enter operation: ");
        scanf(" %c", &input);
        while (getchar() != '\n');  // Clear input buffer

        switch (input)
        {
        case 'b':
        case 'B':
        {
            float num1, num2;
            char operation1;
            char continueBinary = 'y';

            while (continueBinary == 'y' || continueBinary == 'Y')
            {
                printf("Please enter the first number: ");
                num1 = getValidNumber();
                
                printf("Please enter the operation ( + , - , * , / , %% , P , X , I ): ");
                scanf(" %c", &operation1);
                while (getchar() != '\n');

                printf("Please enter the second number: ");
                num2 = getValidNumber();

                switch (operation1)
                {
                case '+':
                    printf("The result is: %.2f\n", num1 + num2);
                    break;
                case '-':
                    printf("The result is: %.2f\n", num1 - num2);
                    break;
                case '*':
                    printf("The result is: %.2f\n", num1 * num2);
                    break;
                case '/':
                    if (num2 == 0)
                        printf("Error: Division by zero\n");
                    else
                        printf("The result is: %.2f\n", num1 / num2);
                    break;
                case '%':
                    if (num2 == 0)
                        printf("Error: Division by zero\n");
                    else
                        printf("The result is: %.2f\n", fmodf(num1, num2));
                    break;
                case 'p':
                case 'P':
                    printf("The result is: %.2f\n", powf(num1, num2));
                    break;
                case 'x':
                case 'X':
                    printf("The result is: %.2f\n", fmaxf(num1, num2));
                    break;
                case 'i':
                case 'I':
                    printf("The result is: %.2f\n", fminf(num1, num2));
                    break;
                default:
                    printf("Invalid operation. Please try again.\n");
                    continue;
                }

                printf("Do you want to perform another binary operation? (y/n): ");
                scanf(" %c", &continueBinary);
                while (getchar() != '\n');
            }
            break;
        }

        case 'u':
        case 'U':
        {
            float num;
            char operation2;
            char continueUnary = 'y';

            while (continueUnary == 'y' || continueUnary == 'Y')
            {
                printf("Please enter the number: ");
                num = getValidNumber();
                
                printf("Please enter the operation (s - square root, l - log, e - exp, c - ceiling, f - floor): ");
                scanf(" %c", &operation2);
                while (getchar() != '\n');

                switch (operation2)
                {
                case 's':
                case 'S':
                    if (num < 0)
                        printf("Error: Square root of a negative number\n");
                    else
                        printf("The result is: %.2f\n", sqrtf(num));
                    break;
                case 'l':
                case 'L':
                    if (num <= 0)
                        printf("Error: Logarithm of a non-positive number\n");
                    else
                        printf("The result is: %.2f\n", logf(num));
                    break;
                case 'e':
                case 'E':
                    printf("The result is: %.2f\n", expf(num));
                    break;
                case 'c':
                case 'C':
                    printf("The result is: %.2f\n", ceilf(num));
                    break;
                case 'f':
                case 'F':
                    printf("The result is: %.2f\n", floorf(num));
                    break;
                default:
                    printf("Invalid operation. Please try again.\n");
                    continue;
                }

                printf("Do you want to perform another unary operation? (y/n): ");
                scanf(" %c", &continueUnary);
                while (getchar() != '\n');
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
                while (getchar() != '\n');

                switch (var)
                {
                case 'a':
                case 'A':
                    printf("Please enter the value for a: ");
                    a = getValidNumber();
                    printf("The value of a is: %.2f\n", a);
                    break;
                case 'b':
                case 'B':
                    printf("Please enter the value for b: ");
                    b = getValidNumber();
                    printf("The value of b is: %.2f\n", b);
                    break;
                case 'c':
                case 'C':
                    printf("Please enter the value for c: ");
                    c = getValidNumber();
                    printf("The value of c is: %.2f\n", c);
                    break;
                case 'd':
                case 'D':
                    printf("Please enter the value for d: ");
                    d = getValidNumber();
                    printf("The value of d is: %.2f\n", d);
                    break;
                case 'e':
                case 'E':
                    printf("Please enter the value for e: ");
                    e = getValidNumber();
                    printf("The value of e is: %.2f\n", e);
                    break;
                default:
                    printf("Invalid variable. Please try again.\n");
                    continue;
                }

                printf("Do you want to define another variable? (y/n): ");
                scanf(" %c", &continueVariable);
                while (getchar() != '\n');
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
                while (getchar() != '\n');

                switch (operation3)
                {
                case 'b':
                case 'B':
                {
                    float num1, num2;
                    char operation4;
                    char input1[2], input2[2];

                    printf("Please enter the first number or variable (a-e): ");
                    scanf("%s", input1);
                    while (getchar() != '\n');
                    if (input1[0] >= 'a' && input1[0] <= 'e')
                        num1 = (input1[0] == 'a') ? a : (input1[0] == 'b') ? b
                                                      : (input1[0] == 'c')   ? c
                                                      : (input1[0] == 'd')   ? d
                                                                           : e;
                    else
                        num1 = getValidNumber();

                    printf("Please enter the operation ( + , - , * , / , %% , P , X , I ): ");
                    scanf(" %c", &operation4);
                    while (getchar() != '\n');

                    printf("Please enter the second number or variable (a-e): ");
                    scanf("%s", input2);
                    while (getchar() != '\n');
                    if (input2[0] >= 'a' && input2[0] <= 'e')
                        num2 = (input2[0] == 'a') ? a : (input2[0] == 'b') ? b
                                                    : (input2[0] == 'c')   ? c
                                                    : (input2[0] == 'd')   ? d
                                                                           : e;
                    else
                        num2 = getValidNumber();

                    switch (operation4)
                    {
                    case '+':
                        printf("The result is: %.2f\n", num1 + num2);
                        break;
                    case '-':
                        printf("The result is: %.2f\n", num1 - num2);
                        break;
                    case '*':
                        printf("The result is: %.2f\n", num1 * num2);
                        break;
                    case '/':
                        if (num2 == 0)
                            printf("Error: Division by zero\n");
                        else
                            printf("The result is: %.2f\n", num1 / num2);
                        break;
                    case '%':
                        if (num2 == 0)
                            printf("Error: Division by zero\n");
                        else
                            printf("The result is: %.2f\n", fmodf(num1, num2));
                        break;
                    case 'P':
                        printf("The result is: %.2f\n", powf(num1, num2));
                        break;
                    case 'X':
                        printf("The result is: %.2f\n", fmaxf(num1, num2));
                        break;
                    case 'I':
                        printf("The result is: %.2f\n", fminf(num1, num2));
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
                    float num;
                    char operation5;
                    char input[2];

                    printf("Please enter the number or variable (a-e): ");
                    scanf("%s", input);
                    while (getchar() != '\n');
                    if (input[0] >= 'a' && input[0] <= 'e')
                        num = (input[0] == 'a') ? a : (input[0] == 'b') ? b
                                                  : (input[0] == 'c')   ? c
                                                  : (input[0] == 'd')   ? d
                                                                        : e;
                    else
                        num = getValidNumber();

                    printf("Please enter the operation (s - square root, l - log, e - exp, c - ceiling, f - floor): ");
                    scanf(" %c", &operation5);
                    while (getchar() != '\n');

                    switch (operation5)
                    {
                    case 's':
                    case 'S':
                        if (num < 0)
                            printf("Error: Square root of a negative number\n");
                        else
                            printf("The result is: %.2f\n", sqrtf(num));
                        break;
                    case 'l':
                    case 'L':
                        if (num <= 0)
                            printf("Error: Logarithm of a non-positive number\n");
                        else
                            printf("The result is: %.2f\n", logf(num));
                        break;
                    case 'e':
                    case 'E':
                        printf("The result is: %.2f\n", expf(num));
                        break;
                    case 'c':
                    case 'C':
                        printf("The result is: %.2f\n", ceilf(num));
                        break;
                    case 'f':
                    case 'F':
                        printf("The result is: %.2f\n", floorf(num));
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
                    while (getchar() != '\n');
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