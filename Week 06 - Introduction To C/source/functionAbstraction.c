// source/functionAbstraction.c
#include <stdio.h>

int factorial(int n) {
    int i = n;
    int f = 1;
    while (i > 0) {
        f *= i;
        i--;
    }
    return f;
}

int main() {
    int n;
    int f;
    for (int j = 0; j < 5; j++) {
        printf("Please, enter a positive integer: ");
        scanf("%d", &n);
        f = factorial(n);
		printf("%d! == %d\n", n, f);
    }
}
