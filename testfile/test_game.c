#include <stdio.h>
#include "../include/matrix.h"
#include "../include/lobby.h"
#include "../include/game.h"


int main() {
    Matrix *game = createMatrix(4, 4);
    setElement(game, 0, 0, 2);
    setElement(game, 0, 1, 2);
    moveAction(game, LEFT);
    printMap(game);
    return 0;
}