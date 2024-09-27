#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pt = malloc(sizeof(int));
    *pt = 100;
    printf("%d\n", *pt);
    
    return 0;
}