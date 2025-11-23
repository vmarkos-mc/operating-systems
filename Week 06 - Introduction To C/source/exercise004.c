// source/exercise004.c
#include <stdio.h>

int main() {
    double x = 1.0;
    int i = 0;
    while (x > 0) {
        x = x / 2;
        i++;
    }
    printf("%f, %d\n", x, i);
    return 0;
}
