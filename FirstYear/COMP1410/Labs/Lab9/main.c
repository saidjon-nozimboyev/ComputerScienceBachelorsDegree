#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie
{
    char *title;
    float rating;
    struct Movie *next;
} Movie;

void addMovie(Movie **head, char *title, float rating, int position);
void removeNext(Movie **head);
void deleteByTitle(Movie **head, char *title);
void printList(Movie *head);

void addMovie(Movie **head, char *title, float rating, int position)
{
    Movie *newMovie = (Movie *)malloc(sizeof(Movie));
    newMovie->title = (char *)malloc(strlen(title) + 1);
    strcpy(newMovie->title, title);
    newMovie->rating = rating;
    newMovie->next = NULL;

    if (position == 0)
    {
        newMovie->next = *head;
        *head = newMovie;
        return;
    }

    if (*head == NULL)
    {
        *head = newMovie;
        return;
    }

    Movie *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newMovie;
}

void removeNext(Movie **head)
{
    if (*head == NULL)
    {
        printf("Watchlist is empty. Nothing to remove.\n");
        return;
    }

    Movie *temp = *head;
    *head = (*head)->next;

    printf("Removed \"%s\" from the watchlist.\n", temp->title);

    free(temp->title);
    free(temp);
}

void deleteByTitle(Movie **head, char *title)
{
    if (*head == NULL)
    {
        printf("Watchlist is empty.\n");
        return;
    }

    Movie *temp = *head, *prev = NULL;

    if (strcmp(temp->title, title) == 0)
    {
        *head = temp->next;
        printf("\"%s\" deleted from the watchlist.\n", title);
        free(temp->title);
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->title, title) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Movie \"%s\" not found.\n", title);
        return;
    }

    prev->next = temp->next;
    printf("\"%s\" deleted from the watchlist.\n", title);
    free(temp->title);
    free(temp);
}

void printList(Movie *head)
{
    if (head == NULL)
    {
        printf("Watchlist is empty.\n");
        return;
    }

    Movie *temp = head;
    int index = 1;
    printf("Current Watchlist:\n");

    while (temp != NULL)
    {
        printf("%d. %s (Rating: %.1f)\n", index, temp->title, temp->rating);
        temp = temp->next;
        index++;
    }
}

int main()
{
    Movie *head = NULL;
    int choice;

    while (1)
    {
        printf("\nWatchlist Menu:\n");
        printf("1. Add a movie\n");
        printf("2. Remove the next movie to watch\n");
        printf("3. Delete a movie by title\n");
        printf("4. Show current watchlist\n");
        printf("5. Exit\n");
        printf("Please choose an option: ");

        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            char title[100];
            float rating;
            int pos;

            printf("Enter movie title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;

            printf("Enter rating (out of 10): ");
            scanf("%f", &rating);

            printf("Add at (0 = beginning, 1 = end): ");
            scanf("%d", &pos);
            getchar();

            addMovie(&head, title, rating, pos);
            printf("Movie added.\n");
        }
        else if (choice == 2)
        {
            removeNext(&head);
        }
        else if (choice == 3)
        {
            char title[100];
            printf("Enter movie title to delete: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;

            deleteByTitle(&head, title);
        }
        else if (choice == 4)
        {
            printList(head);
        }
        else if (choice == 5)
        {
            printf("Good bye!\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
