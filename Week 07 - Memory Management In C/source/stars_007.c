// source/stars_007.c
#include <stdio.h>

int main() {
    int x, *y;
    printf("Enter an int: ");
    scanf("%d", &x);
    y = &x;
    (*y)++;
	printf("%d\n", x);
}
