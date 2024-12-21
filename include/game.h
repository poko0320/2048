#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    LEFT, 
    RIGHT,
    UP, 
    DOWN
} Direction;

Matrix *randomGenerate(Matrix *matrix);
void moveAction(Matrix *matrix, Direction direction);
void input(Matrix *matrix, char action);

#endif 