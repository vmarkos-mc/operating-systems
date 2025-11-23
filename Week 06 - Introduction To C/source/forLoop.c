// source/forLoop.c
#include <stdio.h>

int main() {
    int x; // Declare variable
    int sum = 0; // Initialise variable
    for (int i = 0; i < 5; i++) {
    // for (index, terminating condition; step)
        printf("Please, enter an integer: ");
        scanf("%d", &x);
        sum = sum + x;
    }
    printf("Sum: %d.\n", x);
    return 0;
}
