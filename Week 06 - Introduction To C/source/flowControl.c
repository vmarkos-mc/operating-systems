// source/flowControl.c
#include <stdio.h>

int main() { // Main signature (it returns an integer)
    char knowsCpp; // Declaring a char variable
    printf("Do you use C? (y/n)\n");
    scanf(" %c", &knowsCpp); // Read single character from user.
    if (knowsCpp == 'y') { // Base case
        printf("Congrats! You already know C!\n");
    } else if (knowsCpp == 'n') { // If the above fails
        printf("Dont't worry, you can attend this course!\n");
    } else { // In case all of the above have failed
        printf("Please, enter 'y' or 'n'.\n");
    }
    return 0;
}
