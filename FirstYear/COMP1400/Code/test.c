#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LETTER_HEIGHT 5
#define LETTER_WIDTH  5
#define GAP 1

// ANSI color codes for red and reset (to default)
#define RED "\033[31m"
#define RESET "\033[0m"

// Structure to hold a letter and its 5x5 pattern
typedef struct {
    char letter;
    int pattern[LETTER_HEIGHT][LETTER_WIDTH];
} Letter;

// Define patterns for A-Z (all in uppercase)
// A simple 5x5 representation for each letter.
Letter letters[] = {
    { 'A', { {0,1,1,1,0},
             {1,0,0,0,1},
             {1,1,1,1,1},
             {1,0,0,0,1},
             {1,0,0,0,1} } },
    { 'B', { {1,1,1,1,0},
             {1,0,0,0,1},
             {1,1,1,1,0},
             {1,0,0,0,1},
             {1,1,1,1,0} } },
    { 'C', { {0,1,1,1,1},
             {1,0,0,0,0},
             {1,0,0,0,0},
             {1,0,0,0,0},
             {0,1,1,1,1} } },
    { 'D', { {1,1,1,0,0},
             {1,0,0,1,0},
             {1,0,0,0,1},
             {1,0,0,1,0},
             {1,1,1,0,0} } },
    { 'E', { {1,1,1,1,1},
             {1,0,0,0,0},
             {1,1,1,1,0},
             {1,0,0,0,0},
             {1,1,1,1,1} } },
    { 'F', { {1,1,1,1,1},
             {1,0,0,0,0},
             {1,1,1,1,0},
             {1,0,0,0,0},
             {1,0,0,0,0} } },
    { 'G', { {0,1,1,1,1},
             {1,0,0,0,0},
             {1,0,1,1,1},
             {1,0,0,0,1},
             {0,1,1,1,1} } },
    { 'H', { {1,0,0,0,1},
             {1,0,0,0,1},
             {1,1,1,1,1},
             {1,0,0,0,1},
             {1,0,0,0,1} } },
    { 'I', { {1,1,1,1,1},
             {0,0,1,0,0},
             {0,0,1,0,0},
             {0,0,1,0,0},
             {1,1,1,1,1} } },
    { 'J', { {0,0,0,1,1},
             {0,0,0,0,1},
             {0,0,0,0,1},
             {1,0,0,0,1},
             {0,1,1,1,0} } },
    { 'K', { {1,0,0,0,1},
             {1,0,0,1,0},
             {1,1,1,0,0},
             {1,0,0,1,0},
             {1,0,0,0,1} } },
    { 'L', { {1,0,0,0,0},
             {1,0,0,0,0},
             {1,0,0,0,0},
             {1,0,0,0,0},
             {1,1,1,1,1} } },
    { 'M', { {1,0,0,0,1},
             {1,1,0,1,1},
             {1,0,1,0,1},
             {1,0,0,0,1},
             {1,0,0,0,1} } },
    { 'N', { {1,0,0,0,1},
             {1,1,0,0,1},
             {1,0,1,0,1},
             {1,0,0,1,1},
             {1,0,0,0,1} } },
    { 'O', { {0,1,1,1,0},
             {1,0,0,0,1},
             {1,0,0,0,1},
             {1,0,0,0,1},
             {0,1,1,1,0} } },
    { 'P', { {1,1,1,1,0},
             {1,0,0,0,1},
             {1,1,1,1,0},
             {1,0,0,0,0},
             {1,0,0,0,0} } },
    { 'Q', { {0,1,1,1,0},
             {1,0,0,0,1},
             {1,0,0,0,1},
             {1,0,1,0,1},
             {0,1,1,1,1} } },
    { 'R', { {1,1,1,1,0},
             {1,0,0,0,1},
             {1,1,1,1,0},
             {1,0,1,0,0},
             {1,0,0,1,0} } },
    { 'S', { {0,1,1,1,1},
             {1,0,0,0,0},
             {0,1,1,1,0},
             {0,0,0,0,1},
             {1,1,1,1,0} } },
    { 'T', { {1,1,1,1,1},
             {0,0,1,0,0},
             {0,0,1,0,0},
             {0,0,1,0,0},
             {0,0,1,0,0} } },
    { 'U', { {1,0,0,0,1},
             {1,0,0,0,1},
             {1,0,0,0,1},
             {1,0,0,0,1},
             {0,1,1,1,0} } },
    { 'V', { {1,0,0,0,1},
             {1,0,0,0,1},
             {1,0,0,0,1},
             {0,1,0,1,0},
             {0,0,1,0,0} } },
    { 'W', { {1,0,0,0,1},
             {1,0,0,0,1},
             {1,0,1,0,1},
             {1,1,0,1,1},
             {1,0,0,0,1} } },
    { 'X', { {1,0,0,0,1},
             {0,1,0,1,0},
             {0,0,1,0,0},
             {0,1,0,1,0},
             {1,0,0,0,1} } },
    { 'Y', { {1,0,0,0,1},
             {0,1,0,1,0},
             {0,0,1,0,0},
             {0,0,1,0,0},
             {0,0,1,0,0} } },
    { 'Z', { {1,1,1,1,1},
             {0,0,0,1,0},
             {0,0,1,0,0},
             {0,1,0,0,0},
             {1,1,1,1,1} } }
};

#define NUM_LETTERS (sizeof(letters) / sizeof(letters[0]))

// Return pointer to pattern corresponding to character ch.
// For space or unsupported characters, return a blank 5x5 pattern.
int (*getPattern(char ch))[LETTER_WIDTH] {
    static int blank[LETTER_HEIGHT][LETTER_WIDTH] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    ch = toupper(ch);
    if(ch == ' ') {
        return blank;
    }
    for (int i = 0; i < NUM_LETTERS; i++) {
        if(letters[i].letter == ch)
            return letters[i].pattern;
    }
    // For unsupported characters, return blank.
    return blank;
}

int main() {
    int n;
    char word[256];

    // Ask user for the matrix dimension (n)
    printf("Enter matrix dimension (n): ");
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid matrix dimension.\n");
        return 1;
    }

    // Clear newline left by scanf
    getchar();

    // Ask user for a word
    printf("Enter a word: ");
    if(fgets(word, sizeof(word), stdin) == NULL) {
        printf("Error reading word.\n");
        return 1;
    }
    // Remove trailing newline if present
    word[strcspn(word, "\n")] = '\0';

    int len = strlen(word);

    // Calculate total width required to draw the word.
    int total_width = len * LETTER_WIDTH + (len - 1) * GAP;
    if(total_width > n || LETTER_HEIGHT > n) {
        printf("Error: the matrix of size %d x %d is too small for the word \"%s\".\n", n, n, word);
        return 1;
    }

    // Dynamically allocate an n x n matrix initialized to 0.
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }

    // Center the drawn word in the matrix.
    int start_row = (n - LETTER_HEIGHT) / 2;
    int start_col = (n - total_width) / 2;

    // For each character in the word, copy its 5x5 pattern into the matrix.
    for (int i = 0; i < len; i++) {
        int (*pattern)[LETTER_WIDTH] = getPattern(word[i]);
        int col_offset = start_col + i * (LETTER_WIDTH + GAP);
        for (int r = 0; r < LETTER_HEIGHT; r++) {
            for (int c = 0; c < LETTER_WIDTH; c++) {
                if (pattern[r][c] == 1)
                    matrix[start_row + r][col_offset + c] = 1;
            }
        }
    }

    // Print the resulting matrix.
    // Cells with a 1 will be printed in red.
    printf("\nResulting matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == 1)
                printf(RED "1 " RESET);
            else
                printf("0 ");
        }
        printf("\n");
    }

    // Free allocated memory.
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
