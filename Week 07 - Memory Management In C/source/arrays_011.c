// source/arrays_011.c
#include <stdio.h>

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("arr[%d] == %d\n", i, *(arr + i));
    }
}

int main() {
    int arr[] = {2, 6, 0, 1, 4};
    printArray(arr, 5);
}

