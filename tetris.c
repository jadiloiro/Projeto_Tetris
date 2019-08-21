#include <stdio.h>
#include <stdlib.h>
#define COLUMS 60
#define ROWS 25

void init(char matrix[ROWS][COLUMS]){
    int i, j ;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMS; j++){
            matrix[i][j] = ' ';
        }
    }
}


void printMatrix(char matrix[ROWS][COLUMS]){
        int i, j ;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMS; j++){
        printf("%c", matrix[i][j]);
        }

        printf("\n");
    }

}

int main () {

    char matrix[ROWS][COLUMS];
    int posI, posJ;

    posI = ROWS/2;
    posJ = COLUMS/2;

    system("cls");

    init(matrix);

    while(1){
        system("cls");
        matrix[posI][posJ] = '@';

        printMatrix(matrix);
        matrix[posI][posJ] = ' ';
        if(posJ < COLUMS) posJ++;

    }

    system("pause");

    return 0;
}