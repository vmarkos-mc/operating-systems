// source/exercise005
#include <stdio.h>
#include <stdbool.h>

int main() {
    double x = 1.0;
    while (x / 2 > 0) {
        x = x / 2;
    }
    double y = 1.4 * x;
    bool b = x == y;
    printf("%d\n", b);
    return 0;
}
