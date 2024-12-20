#include <stdio.h>
#include "matrix.h"


int main() {
    Matrix *game = createMatrix(4, 4);
    int x = getElement(game, 1, 1);
    printf("%d",x);
    return 0;
}