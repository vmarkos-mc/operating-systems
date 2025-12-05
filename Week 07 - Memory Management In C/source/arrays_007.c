// source/arrays_007.c
#include <stdio.h>

int main() {
    int arr[] = {2, 6, 0, 0, 4};
    double* ptr = (double*) arr;
    ptr++;
    printf("%f\n", *ptr);
}

