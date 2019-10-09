//Projeto do jogo Tetris implementado em "C" para uso no terminal do console.


//Autor : Jadiel G. Farias Jr.
//Data : 28/08/2019.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimenções da matriz principal do jogo.
#define COLUMS 60
#define ROWS 25

//TECLAS
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68


//Inicializa a matriz principal com espaços vazios.
void init(char matrix[ROWS][COLUMS]);

//Mostra o conteudo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMS]);