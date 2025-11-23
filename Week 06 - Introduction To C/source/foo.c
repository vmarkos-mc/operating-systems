// source/foo.c
#include <stdio.h>

int foo(int x) {
    return x + 5;
}

void foo(char x) {
    printf("%c\n", x);
}

int foo(double x) {
    return x + 5.06;
}

int main() {
    printf("%d\n", foo(6));
    foo('3');
    printf("%d\n", foo(5.8));
}
