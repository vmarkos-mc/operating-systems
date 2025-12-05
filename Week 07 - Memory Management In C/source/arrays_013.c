// source/arrays_013.c
#include <stdio.h>

void foo(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        if (*(arr + i) == 0) {
            *(arr + i) = 4;
        }
    }
}

int main() {
    int arr[] = {2, 6, 0, 1, 4};
    printf("%d\n", arr[2]);
    foo(arr, 5);
    printf("%d\n", arr[2]);
}

