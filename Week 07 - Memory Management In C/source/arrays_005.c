// source/arrays_005.c
#include <stdio.h>

int main() {
    int arr[] = {2, 6, 5, 1};
    int* ptr = arr;
    ptr++;
    printf("%d\n", *ptr);
}

