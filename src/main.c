#include <stdio.h>
#include "matrix.h"


int main() {
    printf("Welcome to 2048!\n");
    Matrix *game = createMatrix(8, 8);
    double x = getElement(game, 1, 1);
    printf("%f",x);
    return 0;
}