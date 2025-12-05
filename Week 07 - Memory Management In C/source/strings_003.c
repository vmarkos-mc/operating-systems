// source/strings_003.c
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "t6H0I9s6.iS.999a9.STRING";
    char c = str[0];
    for(int i = 0; c != '\0'; c = str[++i]) {
        if(isalpha(c))
            printf("%c", (char)(isupper(c) ? tolower(c) : c));
        else if(ispunct(c))
            printf(" ");
    }
    printf("\n");
}

