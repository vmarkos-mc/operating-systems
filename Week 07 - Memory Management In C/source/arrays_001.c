// source/arrays_001.c
#include <stdio.h>

int main() {
    int arr[3];
    arr[0] = 4;
    arr[1] = 6;
    arr[2] = -5;
    for (int i = 0; i < 3; i++) {
        printf("arr[%d] == %d\n", i, arr[i]);
    }
}

