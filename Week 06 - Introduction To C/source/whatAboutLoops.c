// source/whatAboutLoops.c
#include <stdio.h>

int main() {
    int n;
    int i;
    int f;
    for (int j = 0; j < 5; j++) {
        printf("Please, enter a positive integer: ");
        scanf("%d", &n);
        i = n;
        f = 1;
        while (i > 0) {
            f *= i;
            i--;
        }
		printf("%d! == %d\n", n, f);
    }
}
