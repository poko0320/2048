#include <stdio.h>
#include "matrix.h"


int main() {
    printf("Welcome to 2048!\n");
    Matrix *game = createMatrix(4, 4);
    return 0;
}