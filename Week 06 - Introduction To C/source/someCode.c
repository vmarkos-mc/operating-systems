// source/someCode.c
#include <stdio.h>

int main() {
    int n;
    printf("Please, enter a positive integer: ");
    scanf("%d", &n);
    int i = n;
    int f = 1;
    while (i > 0) {
        f *= i;
        i--;
    }
	printf("%d! == %d\n", n, f);
}
