// source/stars_004.c
#include <stdio.h>

int main() {
    int x;
    printf("Enter an int: ");
    scanf("%d", &x);
    int *y = &x;
	printf("%d\n", y);
}
