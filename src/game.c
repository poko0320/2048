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
void combine_row_left(Matrix *matrix, int row[4]);
void reverse_row(int row[4]);

//=================================================
//                game feature
//=================================================


int randomNumber(int number){
    srand(time(NULL));
    return rand()%number;
}


void randomGenerate(Matrix *matrix){
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
}

bool Is2048(Matrix *matrix){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j  < 4; j++){
            if(getElement(matrix, i, j) == 2048){
                return true;
            }
           
        }
    }
    return false;
}
bool CheckSameMatrix(Matrix *m1, Matrix *m2){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j  < 4; j++){
            if(getElement(m1, i, j) != getElement(m2, i, j)){
                return false;
            }
        }
    }
    return true;
}

bool IsMoveable(Matrix *matrix){
    for(int i = 0; i < 4; i++){
        Matrix *tmp = cloneMatrix(matrix);
        switch (i) {
            case 0:
                moveAction(tmp, UP);
                break;
            case 1:
                moveAction(tmp, DOWN); 
                break;   
            case 2:
                moveAction(tmp, RIGHT);
                break;
            case 3:
                moveAction(tmp, LEFT);  
                break;
        }
        if (!CheckSameMatrix(tmp, matrix)) {
            freeMatrix(tmp); // Free the temporary matrix before returning
            return true; // Move is possible
        }

        // Free the temporary matrix
        freeMatrix(tmp);
    }
    return false;
}

// ************* use this function to move ************
// r is reverse
void input(Matrix *matrix, char action){
    switch (action) {
        case 'w':
            cloneDataToPrev(matrix);
            moveAction(matrix, UP);
            break;
        case 'a':
            cloneDataToPrev(matrix);
            moveAction(matrix, LEFT);
            break;
        case 's':
            cloneDataToPrev(matrix);
            moveAction(matrix, DOWN);
            break;
        case 'd':
            cloneDataToPrev(matrix);
            moveAction(matrix, RIGHT);
            break;
        case 'r':
            clonePrevToData(matrix);
            break;
    }
}






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
                combine_row_left(matrix, row);
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
                combine_row_left(matrix, row);
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
                combine_row_left(matrix, column);
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
                combine_row_left(matrix, column);
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

void incScore(int *score, int newscore) {
    *score += newscore;
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

void combine_row_left(Matrix *matrix, int row[4]) {
    for (int i = 0; i < 3; i++) {
        if (row[i] != 0 && row[i] == row[i + 1]) {
            row[i] *= 2;
            setScore(matrix, row[i]);
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
