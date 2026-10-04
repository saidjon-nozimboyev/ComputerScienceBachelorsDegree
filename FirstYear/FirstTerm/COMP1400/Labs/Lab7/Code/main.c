#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    srand(time(0));
    int random_number = (rand() % 50) + 1;

    int number;
    short attemps = 10;
    short inputs = 0;
    bool isGame = true;

    printf("Computer has picked a random number\n");

    while (isGame)
    {
        printf("\n");
        printf("You have %d attemps left\n", attemps);
        printf("Please enter number: ");
        scanf("%d", &number);

        if (number > random_number)
        {
            printf("Entered number is too high\n");
        }
        if (number < random_number)
        {
            printf("Entered number is too low\n");
        }
        if (number == random_number)
        {
            printf("Correct, number was: %d", random_number);
            isGame = false;
        }
        attemps--;
        inputs++;

        if (inputs == 10)
        {
            printf("Game over, the number was: %d\n", random_number);
            isGame = false;
        }
    }
}
