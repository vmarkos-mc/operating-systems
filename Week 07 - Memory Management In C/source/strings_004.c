// source/strings_004.c
#include <stdio.h>
#include <string.h>

int main() {
  char fragment1[] = "I'm a s";
  char fragment2[] = "tring!";
  char fragment3[20];
  char finalString[20] = "";

  strcpy(fragment3, fragment1);
  strcat(finalString, fragment3);
  strcat(finalString, fragment2);
  printf("%s\n", finalString);
}

