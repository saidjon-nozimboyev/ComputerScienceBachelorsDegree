// #include <stdio.h>

// int main()
// {
//     // int n;
//     // printf("Please enter number: ");
//     // scanf("%d", &n);
//     // for (int i = 1; i<=10; i++)
//     // {
//     //     printf("%d * %d = %d\n", n, i, n*i);
//     // }

// }
#include <stdio.h>
int main(void)
{
    int i = 0;
    while (i < 2)
        switch (i)
        {
            i = 2;
        case 0:
            printf("Hi. This is case 0 \n");
            i++;
            break;
        case 1:
            printf("Hi. This is case 1 \n");
            i++;
            break;
        case 2:
            printf("Hi. This is case 2 \n");
            i++;
            break;
        default:
            printf("Hi. This is default \n");
            i++;
            break;
        }
}