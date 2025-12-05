// source/stars_001.c
#include <stdio.h>

int main() {
    double x;
    printf("Enter a double: ");
    scanf("%f", &x);
    double *y = &x;
	printf("%d\n", (*y == x));
}
