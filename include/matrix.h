#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

// Structure definition for Matrix
typedef struct {
    int nRows;
    int nCols;
    double **data; // Pointer-to-pointer for 2D array
} Matrix;

// Function declarations (prototypes)
Matrix *createMatrix(int nRows, int nCols);
void freeMatrix(Matrix *matrix);
void setElement(Matrix *matrix, int row, int col, double value);
double getElement(Matrix *matrix, int row, int col);

#endif // MATRIX_H