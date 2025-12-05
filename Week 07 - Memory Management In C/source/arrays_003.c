// source/arrays_003.c
#include <stdio.h>

int main() {
    char arr[3];
    for (int i = 0; i < 3; i++) {
        printf("Please, enter a character: ");
        scanf(" %c", &arr[i]);
    }
    printf("%c%c%c\n", arr[0], arr[1], arr[2]);
}

