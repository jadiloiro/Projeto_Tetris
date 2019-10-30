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


    
    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");



    //posicao inicial do personagem
    initBar(&tijolo);



    //inicializando matriz
    init(matrix);





    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("posicao = (%d, %d)\n", tijolo.i, tijolo.j);
            printf("dimencao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif 
        drawBar(matrix, tijolo, PIXEL);

        printMatrix(matrix);


        if(!collisionDetect(matrix, tijolo)){
            drawBar(matrix, tijolo, EMPTY);

            if(tijolo.j < (ROWS-1)) tijolo.i++;
        }else{
            initBar(tijolo);
        }
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
                rotate(&tijolo);
            break;       
        }

    }

    system("pause");

    return 0;
}