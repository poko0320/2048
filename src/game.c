#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

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