#include <stdio.h>
#include "../include/matrix.h"
#include "../include/lobby.h"


int main() {
    Matrix *game = createMatrix(4, 4);
    printMap(game);
    return 0;
}