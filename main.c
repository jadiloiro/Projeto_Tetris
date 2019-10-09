/*
    Jogo interativo Tetris implementado em linguagem C para uso 
    no console (terminal de comandos)
    Para executar:
    > start main.exe
    Autor: Jadiel Farias junior
    Data: 28/08/2019
*/

#include "tetris.h"
#include "display.h"



int main(){
    char matrix[ROWS][COLUMS];
    Bloco tijolo;
    int keypressed=0;

    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;



    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("PIXEL = (%d, %d)\n", tijolo.i, tijolo.j);
        #endif 

        switch(tijolo.orientacao)
            case ORIENTACAO_UP:
                if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j] = PIXEL;
                if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j] = PIXEL;
                if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;
                break;
            case ORIENTACAO_DOWN:
                if(tijolo.j-3>=0) matrix[tijolo.i][tijolo.j-3] = PIXEL;
                if(tijolo.j-2>=0) matrix[tijolo.i][tijolo.j-2] = PIXEL;
                if(tijolo.j-1>=0) matrix[tijolo.i][tijolo.j-1] = PIXEL;
                matrix[tijolo.i][tijolo.j] = PIXEL;
            break;

        printMatrix(matrix);


        matrix[tijolo.i-3][tijolo.j] = EMPTY;
        matrix[tijolo.i-2][tijolo.j] = EMPTY;
        matrix[tijolo.i-1][tijolo.j] = EMPTY;
        matrix[tijolo.i][tijolo.j] = EMPTY;
        
        if(tijolo.i < (ROWS-1)) tijolo.i++;

        keypressed = 0;
        if(kbhit()) keypressed = getch() ;
        if (keypressed == ARROWS) keypressed = getch() ;

        switch(keypressed){
            case (int) 'a':
            case (int) 'A':
            case LEFT:
                if (tijolo.j > 0) tijolo.j--; 
            break;
            case TECLA_d:
            case TECLA_D:
            case RIGHT:
                if(tijolo.j < (COLUMS-1)) tijolo.j++; 
            break;
        }
    }

    system("pause");

    return 0;
}