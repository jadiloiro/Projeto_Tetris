//Projeto do jogo Tetris implementado em "C" para uso no terminal do console
//Para executar 
//No cmd : start programa.exe
//Autor : Jadiel G. Farias Jr.
//Data : 28/08/2019


#include "tetris.h"
//Parte do programa responsavel por iniciar as funções
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
