// source/2d_arrays_002.c
#include <stdio.h>

int main() {
    // Declare array at initialisation.
    int arr[2][3] = { { 2, 0, -3 }, { 4, 6, 7 } };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

