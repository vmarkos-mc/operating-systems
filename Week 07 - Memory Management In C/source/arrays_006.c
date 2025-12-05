// source/arrays_006.c
#include <stdio.h>

int main() {
    int arr[] = {2, 6, 5, 1};
    float* ptr = (float*) arr;
    ptr++;
    printf("%f\n", *ptr);
}

