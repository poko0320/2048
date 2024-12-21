#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

// Structure definition for Matrix
typedef struct {
    int nRows;
    int nCols;
    int **data; // Pointer-to-pointer for 2D array
    int **prev_data;
    int score;
} Matrix;

// Function declarations (prototypes)
Matrix *createMatrix(int nRows, int nCols);
void freeMatrix(Matrix *matrix);
void setElement(Matrix *matrix, int row, int col, int value);
int getElement(Matrix *matrix, int row, int col);
void setScore(Matrix *matrix, int value);
int getScore(Matrix *matrix);
Matrix *cloneMatrix(Matrix *matrix);
void cloneDataToPrev(Matrix* matrix);
void clonePrevToData(Matrix* matrix);

#endif 