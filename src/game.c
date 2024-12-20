#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "game.h"
#include <ctype.h>

void extract_column(Matrix *matrix, int col, int column[4]);
void place_column(Matrix *matrix, int col, int column[4]);
void place_column(Matrix *matrix, int col, int column[4]);
void slide_row_left(int row[4]);
void combine_row_left(int row[4], int *score);
void reverse_row(int row[4]);

int randomNumber(int number){
    srand(time(NULL));
    return rand()%number;
}


Matrix *randomGenerate(Matrix *matrix){
    int randX = randomNumber(4);
    int randY = randomNumber(4);
    while(getElement(matrix, randX, randY)!= 0){
        randX = randomNumber(4);
        randY = randomNumber(4);
    }
    //need random value for 2(60%) and 4(40%)
    int randValue_key = randomNumber(1000);
    int randValue = 0;
    if(randValue_key == 0){
        printf("error exit");
    }
    if(randValue_key > 600){
        randValue = 4;
    }else{
        randValue = 2;
    }
    setElement(matrix, randX, randY, randValue);
    return matrix;
}

// ************* use this function to move ************
void moveAction(Matrix *matrix, Direction direction){
    // Handle movement based on the direction
    switch (direction) {
        case LEFT:
            for (int i = 0; i < 4; i++) {
                int row[4];
                // Extract the row
                for (int j = 0; j < 4; j++) {
                    row[j] = getElement(matrix, i, j);
                }

                // Slide and combine
                slide_row_left(row);
                combine_row_left(row, matrix->score);
                slide_row_left(row);

                // Place the updated row back into the matrix
                for (int j = 0; j < 4; j++) {
                    setElement(matrix, i, j, row[j]);
                }
            }
            break;

        case RIGHT:
            for (int i = 0; i < 4; i++) {
                int row[4];
                // Extract the row
                for (int j = 0; j < 4; j++) {
                    row[j] = getElement(matrix, i, j);
                }

                // Reverse, slide, combine, and reverse back
                reverse_row(row);
                slide_row_left(row);
                combine_row_left(row, matrix->score);
                slide_row_left(row);
                reverse_row(row);

                // Place the updated row back into the matrix
                for (int j = 0; j < 4; j++) {
                    setElement(matrix, i, j, row[j]);
                }
            }
            break;

        case UP:
            for (int col = 0; col < 4; col++) {
                int column[4];
                // Extract the column
                for (int i = 0; i < 4; i++) {
                    column[i] = getElement(matrix, i, col);
                }

                // Slide and combine
                slide_row_left(column);
                combine_row_left(column, matrix->score);
                slide_row_left(column);

                // Place the updated column back into the matrix
                for (int i = 0; i < 4; i++) {
                    setElement(matrix, i, col, column[i]);
                }
            }
            break;

        case DOWN:
            for (int col = 0; col < 4; col++) {
                int column[4];
                // Extract the column
                for (int i = 0; i < 4; i++) {
                    column[i] = getElement(matrix, i, col);
                }

                // Reverse, slide, combine, and reverse back
                reverse_row(column);
                slide_row_left(column);
                combine_row_left(column, matrix->score);
                slide_row_left(column);
                reverse_row(column);

                // Place the updated column back into the matrix
                for (int i = 0; i < 4; i++) {
                    setElement(matrix, i, col, column[i]);
                }
            }
            break;
    }
}






// ___________________helper functions______________________
void extract_column(Matrix *matrix, int col, int column[4]) {
    for (int i = 0; i < 4; i++) {
        column[i] = matrix->data[i][col];
    }
}

void place_column(Matrix *matrix, int col, int column[4]) {
    for (int i = 0; i < 4; i++) {
        matrix->data[i][col] = column[i];
    }
}

void slide_row_left(int row[4]) {
    int temp[4] = {0};
    int index = 0;

    for (int i = 0; i < 4; i++) {
        if (row[i] != 0) {
            temp[index++] = row[i];
        }
    }

    for (int i = 0; i < 4; i++) {
        row[i] = temp[i];
    }
}

void combine_row_left(int row[4], int *score) {
    for (int i = 0; i < 3; i++) {
        if (row[i] != 0 && row[i] == row[i + 1]) {
            row[i] *= 2;
            *score += row[i]; // Update the score
            row[i + 1] = 0;
        }
    }
}

void reverse_row(int row[4]) {
    for (int i = 0; i < 2; i++) {
        int temp = row[i];
        row[i] = row[3 - i];
        row[3 - i] = temp;
    }
}