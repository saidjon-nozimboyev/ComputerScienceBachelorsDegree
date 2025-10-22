#include <stdio.h>
#include <string.h>

void reverseWord(char word[]) // 2 pointer approach
{
    int i = 0, j = strlen(word) - 1;
    while (i < j)
    {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
}

int isPalindrome(const char word[])
{
    for (int i = 0, j = strlen(word) - 1; i < j; i++, j--)
    {
        if (word[i] != word[j])
            return 0;
    }
    return 1;
}

int main()
{
    char name[20];
    printf("Enter a name: ");
    scanf("%[^\n]", name); // [^\n] gets untill the end
    printf("Name is: %s\n", name);
    reverseWord(name);
    printf("Reversed: %s\n", name);
    int polin = isPalindrome(name);
    if (polin)
        printf("Word is palindrome: %s\n", name);
    else
        printf("Word is not palindrome: %s\n", name);
    // puts(name); alternative way to print
}