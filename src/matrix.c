#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Function to create a matrix
Matrix* createMatrix(int nRows, int nCols) {
    // Allocate memory for the Matrix structure
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (!matrix) {
        fprintf(stderr, "Memory allocation failed for Matrix struct\n");
        return NULL;
    }

    // Initialize the nRows and nCols
    matrix->nRows = nRows;
    matrix->nCols = nCols;

    // Allocate memory for the 2D array 'data'
    matrix->data = (int**)malloc(nRows * sizeof(int*));
    if (!matrix->data) {
        fprintf(stderr, "Memory allocation failed for data\n");
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < nRows; i++) {
        matrix->data[i] = (int*)malloc(nCols * sizeof(int));
        if (!matrix->data[i]) {
            fprintf(stderr, "Memory allocation failed for data[%d]\n", i);
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    // Allocate memory for the 2D array 'prev_data'
    matrix->prev_data = (int**)malloc(nRows * sizeof(int*));
    if (!matrix->prev_data) {
        fprintf(stderr, "Memory allocation failed for prev_data\n");
        for (int i = 0; i < nRows; i++) {
            free(matrix->data[i]);
        }
        free(matrix->data);
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < nRows; i++) {
        matrix->prev_data[i] = (int*)malloc(nCols * sizeof(int));
        if (!matrix->prev_data[i]) {
            fprintf(stderr, "Memory allocation failed for prev_data[%d]\n", i);
            for (int j = 0; j < i; j++) {
                free(matrix->prev_data[j]);
            }
            free(matrix->prev_data);
            for (int j = 0; j < nRows; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    // Initialize score
    matrix->score = 0;
    matrix->prev_score = 0;
    

    // Optionally initialize the arrays to zero
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            matrix->data[i][j] = 0;
            matrix->prev_data[i][j] = 0;
        }
    }

    return matrix;
}

// Function to free the memory used by a matrix
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->nRows; i++) {
        free(matrix->data[i]); // Free each row
    }
    free(matrix->data); // Free row pointers
    free(matrix->prev_data);
    free(matrix);       // Free the matrix struct
}

// Function to set an element in the matrix
void setElement(Matrix *matrix, int row, int col, int value) {
    if (row >= matrix->nRows || col >= matrix->nCols || row < 0 || col < 0) {
        fprintf(stderr, "Error: Index out of bounds\n");
        return;
    }
    matrix->data[row][col] = value;
}

// Function to get an element from the matrix
int getElement(Matrix *matrix, int row, int col) {
    if (row >= matrix->nRows || col >= matrix->nCols || row < 0 || col < 0) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE); // Exit on invalid access
    }
    return matrix->data[row][col];
}

// Function to set the score
void setScore(Matrix *matrix, int value){
    matrix->score = matrix->score + value;
}

// Function to get the score
int getScore(Matrix *matrix){
    return matrix->score;
}

void setPrevScore(Matrix *matrix, int value){
    matrix->prev_score = value;
}

// Function to get the score
int getPrevScore(Matrix *matrix){
    return matrix->prev_score;
}

// clone matrix
Matrix *cloneMatrix(Matrix *matrix) {
    Matrix *newMatrix = createMatrix(4,4); // Create a new matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            setElement(newMatrix, i, j, getElement(matrix, i, j)); // Copy elements
        }
    }
    return newMatrix;
}

// Function to clone data to prev_data
void cloneDataToPrev(Matrix* matrix) {
    if (!matrix || !matrix->data || !matrix->prev_data) {
        fprintf(stderr, "Invalid Matrix or uninitialized arrays\n");
        return;
    }

    for (int i = 0; i < matrix->nRows; i++) {
        for (int j = 0; j < matrix->nCols; j++) {
            matrix->prev_data[i][j] = matrix->data[i][j];
        }
    }
}

void clonePrevToData(Matrix* matrix) {
    if (!matrix || !matrix->data || !matrix->prev_data) {
        fprintf(stderr, "Invalid Matrix or uninitialized arrays\n");
        return;
    }

    for (int i = 0; i < matrix->nRows; i++) {
        for (int j = 0; j < matrix->nCols; j++) {
            matrix->data[i][j] = matrix->prev_data[i][j];
        }
    }
}

int areMatricesEqual(Matrix *matrix) {
    for (int i = 0; i < matrix->nRows; i++) {
        for (int j = 0; j < matrix->nCols; j++) {
            if (matrix->data[i][j] != matrix->prev_data[i][j]) {
                return 0; // Not equal
            }
        }
    }
    return 1; // Equal
}