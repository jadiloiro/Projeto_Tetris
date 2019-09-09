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
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMS; j++){
        printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}