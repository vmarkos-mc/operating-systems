// source/whileLoop.c
#include <stdio.h>

int main() {
    const int GUESS = 4; // Constant value (immutable)
    int x; // Declare variable
    printf("Guess what I'm thinking (int): ");
    scanf("%d", &x);
    while (x != GUESS) { // Repeat while condition holds
        printf("No, try again: ");
        scanf("%d", &x);
    }
    printf("Congratulations! You guessed right!\n");
    return 0;
}
