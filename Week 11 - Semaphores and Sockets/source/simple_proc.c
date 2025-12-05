// source/simple_proc.c
#include <stdio.h>
#include <stdlib.h>
#include "foo.h"

int main() {
    char* s = "This contains spaces";
    printf("%s\n", foo(s));
    return 0;
}