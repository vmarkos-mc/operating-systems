// source/2d_arrays_006.c
#include <stdio.h>

int main() {
    // Uncomment exactly 1 of the following 3 lines
    int arr[][3] = { 2, 0, -3, 4, 6, 7 };
    // int arr[][2] = { 2, 0, -3, 4, 6, 7 };
    // int arr[][6] = { 2, 0, -3, 4, 6, 7 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

