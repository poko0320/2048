#include <stdio.h>
#include "../include/matrix.h"
#include "../include/lobby.h"
#include "../include/game.h"


int main() {
    printOpening();
    Matrix *game = createMatrix(4, 4);
    randomGenerate(game);
    printMap(game);
    char action;
    while((!Is2048(game)) && IsMoveable(game)){
        if(action == 'q'){
            break;
        }
        printf("Input (w/a/s/d/r/q): ");
        scanf(" %c", &action);
        printf("\n");
        input(game, action);
        printMap(game);
        if(action != 'r'){
            randomGenerate(game);
        }
    }
    freeMatrix(game);
    printf("END");
    return 0;
}