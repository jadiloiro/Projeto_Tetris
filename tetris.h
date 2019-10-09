#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <display.h>

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

//Orientacoes para as peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_DOWN 2
#define ORIENTACAO_LEFT 3
#define ORIENTACAO_RIGHT 4

//Tipos de peças
#define TIPO_L 1
#define TIPO_L_R 2 //L REVERSO
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 //Z REVERSO
#define TIPO_O 6 //QUADRADO
#define TIPO_I 7

//Configurações de layout
#define PIXEL 219
#define EMPTY 32

//ESTRUTURA PADRAO DE COMPONENTES
typedef struct{
    int i; //Posição nas linhas da matiz
    int j; //Posição nas colunas da matriz
    int orientacao; // orientação da peça
    int tipo; // tipo da peça
    int width; 
    int height

}Bloco;


//Inicializa a matriz principal com espaços vazios.
void init(char matrix[ROWS][COLUMS]);

//Mostra o conteudo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMS]);