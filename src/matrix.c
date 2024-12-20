#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Function to create a matrix
Matrix *createMatrix(int nRows, int nCols) {
    // Allocate memory for the matrix struct
    Matrix *matrix = malloc(sizeof(Matrix));
    if (matrix == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }

    // Store dimensions
    matrix->nRows = nRows;
    matrix->nCols = nCols;

    // Allocate memory for rows
    matrix->data = malloc(nRows * sizeof(int *));
    if (matrix->data == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        free(matrix);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for each row
    for (int i = 0; i < nRows; i++) {
        matrix->data[i] = malloc(nCols * sizeof(int));
        if (matrix->data[i] == NULL) {
            fprintf(stderr, "Error: Out of memory\n");
            for (int j = 0; j < i; j++) free(matrix->data[j]);
            free(matrix->data);
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }

    // Initialize all elements to 0
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            matrix->data[i][j] = 0;
        }
    }
    matrix->score = 0;

    return matrix;
}

// Function to free the memory used by a matrix
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->nRows; i++) {
        free(matrix->data[i]); // Free each row
    }
    free(matrix->data); // Free row pointers
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