#include <stdio.h>
#include "../include/matrix.h"
#include "../include/lobby.h"
#include "../include/game.h"


int main() {
    printOpening();
    Matrix *game = createMatrix(4, 4);
    randomGenerate(game);
    printMap(game);
    input(game);
    
    while((!Is2048(game)) && IsMoveable(game)){
        randomGenerate(game);
        printMap(game);
        input(game);
    }
    freeMatrix(game);
    printf("END");
    return 0;
}