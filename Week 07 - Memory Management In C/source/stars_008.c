// source/stars_008.c
#include <stdio.h>

int main() {
    int x, y;
    printf("Enter two ints: ");
    scanf("%d", &x);
    scanf("%d", &y);
    const int *p1 = &x;
    int * const p2 = &x;
    // Enter your code here...
}
