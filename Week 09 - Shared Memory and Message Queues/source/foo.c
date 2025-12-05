// source/foo.c
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int str_len(char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

char* strip_spaces(char* str) {
    int n = str_len(str);
    char* stripped = malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (*(str + i) != ' ') {
            *(stripped + j) = *(str + i);
            j++;
        }
    }
    printf("%s\n", stripped);
    return stripped;
}

char* copy_str(char* str) {
    int n = str_len(str);
    char* copy = malloc((n + 1)* sizeof(char));
    for (int i = 0; i < n; i++) {
        *(copy + i) = *(str + i);
    }
    // *(copy + n) = '\0';
    return copy;
}

char* permute(char* str) {
    // mutates the input string!
    int n = str_len(str);
    if (n < 2) {
        return str;
    }
    char* cp_str = copy_str(str);
    srand(time(NULL));
    char temp;
    for (int i = 0; i < n - 1; i++) {
        int j = i + (random() % (n - i));
        temp = *(cp_str + i);
        *(cp_str + i) = *(cp_str + j);
        *(cp_str + j) = temp;
    }
    return cp_str;
}

char* foo(char* str) {
    return permute(strip_spaces(str));
}