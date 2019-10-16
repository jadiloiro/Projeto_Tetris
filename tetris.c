//Projeto do jogo Tetris implementado em "C" para uso no terminal do console.


//Autor : Jadiel G. Farias Jr.
//Data : 28/08/2019.

#include "tetris.h"

//Inicializa a matriz principal com espaços vazios.
void init(char matrix[ROWS][COLUMS]){
    int i, j ;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMS; j++){
            matrix[i][j] = ' ';
        }
   }
}
//teste

//Mostra o conteudo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMS]){
        int i, j ;

        printf("\t\t\t");
        for(j=0; j<COLUMS+2; j++){
            printf("*");
        }

        printf("\n");


    for(i=0; i<ROWS; i++){
        printf("\t\t\t*");
        for(j=0; j<COLUMS; j++){
        printf("%c", matrix[i][j]);
        }
        printf("*\n");
    }

    printf("\t\t\t");

    for(j=0; j<COLUMS+2; j++){
        printf("*");
    }
    printf("\n");
}
    void drawBar(char matrix [ROWS][COLUMS], Bloco barra, int simbolo){
        switch(barra.orientacao){
            case ORIENTACAO_DOWN:
            case ORIENTACAO_UP:
                if(barra.i-3>=0) matrix[barra.i-3][barra.j] = simbolo;
                if(barra.i-2>=0) matrix[barra.i-2][barra.j] = simbolo;
                if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
                matrix[barra.i][barra.j] = simbolo;
                break;
            case ORIENTACAO_RIGHT:
            case ORIENTACAO_LEFT:
                if(barra.j-3>=0) matrix[barra.i][barra.j-3] = simbolo;
                if(barra.j-2>=0) matrix[barra.i][barra.j-2] = simbolo;
                if(barra.j-1>=0) matrix[barra.i][barra.j-1] = simbolo;
                matrix[barra.i][barra.j] = simbolo;
                break;
    }

}