/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)
    Para executar:
    > start programa.exe
    Autor: Jadiel Farias junior
    Data: 28/08/2019
*/

#include "tetris.h"
#include "display.h"

/*
    Parte principal do programa, responsável por iniciar e 
    chamar as funções auxiliares.
*/
int main(){
    char matrix[ROWS][COLUMS];
    int posI, posJ;

    //posicao inicial do personagem
    posI = ROWS/2;
    posJ = COLUMS/2;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    while(1){        
        gotoxy(0,0);

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posJ < COLUMS) posJ++;
    }

    system("pause");

    return 0;
}