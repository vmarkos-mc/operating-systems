// source/stars_006c.
#include <stdio.h>

int main() {
    int x, y;
    printf("Enter two ints: ");
    scanf("%d", &x);
    scanf("%d", &y);
    int *ptrx = &x;
    int *ptry = &y;
    ptry = ptrx;
    (*ptrx)--;
    ptry = &y;
	printf("%d, %d\n", x, y);
}
