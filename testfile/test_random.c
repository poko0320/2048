#include <stdio.h>
#include "../include/matrix.h"
#include "../include/lobby.h"
#include "../include/game.h"

int main() {
    printf("Welcome to 2048!\n");
    Matrix *game = createMatrix(4, 4);
    setElement(game, 3, 3, 1);
    Matrix *new= randomGenerate(game);
    printMap(new);
    new= randomGenerate(game);
    printMap(new);
    return 0;
}