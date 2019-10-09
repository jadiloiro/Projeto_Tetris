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
    int keypressed=0;

    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMS/2;
    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posJ < (ROWS-1)) posI++;

        keypressed = 0;
        if(kbhit()) keypressed = getch() ;
        if (keypressed == ARROWS) keypressed = getch() ;

        switch(keypressed){
            case (int) 'a':
            case (int) 'A':
            case LEFT:
                if (posJ > 0) posJ--; //vai para esquerda
            break;
            case TECLA_d:
            case TECLA_D:
            case RIGHT:
                if(posJ < (COLUMS-1)) posJ++; //vai para a direita
            break;
        }
    }

    system("pause");

    return 0;
}