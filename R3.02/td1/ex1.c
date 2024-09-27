#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int y = 30;
    int *ptr1;
    int *ptr2;

    ptr1 = &x;
            
    y = *ptr1;

    *ptr1 = 50;

    ptr2 = ptr1;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
    printf("*ptr2 = %d\n", *ptr2);
}
