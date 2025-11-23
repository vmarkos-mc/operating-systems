// source/problem_001.c
#include <stdio.h>

double foo(int x) {
    double y = x / 2;
    return y;
}

int main() {
    printf("%f\n", foo("5"));
}
