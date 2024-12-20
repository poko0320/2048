#include <stdio.h>
#include "matrix.h"

//find the digit
int countDigits(int number) {
    int count = 0;
    do {
        count++;
        number /= 10;
    } while (number != 0);
    return count;
}

//print the row of ---- 
void printRowLine(){
    for(int i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");
}
void printLevelValue(Matrix *matrix,int level){
    printf("|");
    int value;
    for(int i = 0; i < 4; i++){
        value = getElement(matrix, level, i);
        int digit = countDigits(value);
        for(int j = 0;j< (4-digit); j++){
            printf(" ");
        }
        printf("%d",value);
        printf("|");
    }
    printf("\n");
}
void printMap(Matrix *matrix) {
    printRowLine();
    for(int i = 0; i<4;i++){
        printLevelValue(matrix,i);
        printRowLine();
    }
}

