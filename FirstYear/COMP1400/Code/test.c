#include <stdio.h>

int main()
{
    int a = 10;
    int b = 5;
    if (a = b){
        printf("Wokred\n");
    }
    printf("%d\n",++a);
    printf("%d",a++);
    int c = ++a - b--;
    printf("%d",c);

}