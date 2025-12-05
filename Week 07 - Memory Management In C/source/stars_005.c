// source/stars_005.c
#include <stdio.h>

int main() {
    int x;
    printf("Enter an int: ");
    scanf("%d", &x);
    int *ptrx = &x;
    (*ptrx)++;
    printf("%d\n", x);
}
