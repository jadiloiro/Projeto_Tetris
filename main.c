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
#define DEBUG 1



int main(){
    char matrix[ROWS][COLUMS];
    Bloco tijolo;
    int keypressed=0;

    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_LEFT;
    tijolo.width = 1;
    tijolo.height = 5;



    //inicializando matriz
    init(matrix);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("posicao = (%d, %d)\n", tijolo.i, tijolo.j);
            printf("dimencao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif 
        drawBar(matrix, tijolo, PIXEL);

        printMatrix(matrix);
        
        drawBar(matrix, tijolo, EMPTY);


            //faço a posição da @ ir para a direita
        if(tijolo.i < (ROWS-1)) tijolo.i++;

        //lendo teclas
        keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case (int)'a':
            case (int)'A':
            case LEFT: 
                if(tijolo.j - (tijolo.width/2) > 0) tijolo.j--; //vai para esquerda
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if(tijolo.j + (tijolo.width/2) < (COLUMS-1)) tijolo.j++; //vai para a direita 
            break;
            case TECLA_ESPACO:
                if(tijolo.orientacao==ORIENTACAO_RIGHT)
                    tijolo.orientacao = ORIENTACAO_UP;
                else
                    tijolo.orientacao++;

                //inverte as dimençoes do tijolo
                int aux = tijolo.width;
                tijolo.width = tijolo.height;
                tijolo.height = aux;

                if(tijolo.j < tijolo.width/2)
                    tijolo.j = tijolo.width/2;
                else if(tijolo.j > COLUMS - (tijolo.width/2) -1)
                    tijolo.j = COLUMS - (tijolo.width/2) -1;

                        
                
        }

    }

    system("pause");

    return 0;
}