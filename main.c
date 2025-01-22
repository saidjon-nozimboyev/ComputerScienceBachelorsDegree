#include <stdio.h>

void SayHello(void);

int main()
{
    SayHello();
    int a,b;
    printf("Ali please enter number: ");
    scanf("%i", &a);
    printf("Your number is %i", a);
    return 0;
}

void SayHello(void)
{
    printf("Hello Ali\n");
    printf("You are in function call\n");
}

// this is commenr
// fk 

/*


this is also a comment
*/