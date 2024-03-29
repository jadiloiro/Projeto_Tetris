#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimenções da matriz principal do jogo.
#define COLUMS 30
#define ROWS 60

//TECLAS
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68
#define TECLA_ESPACO 32

//Orientacoes para as peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
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

//ESTRUTURA PADRÃO DE COMPONENTES
typedef struct{
    int i; //Posição nas linhas da matiz
    int j; //Posição nas colunas da matriz
    int orientacao; // orientação da peça
    int tipo; // tipo da peça
    int width; 
    int height;

}Bloco;


//Inicializa a matriz principal com espaços vazios.
void init(char matrix[ROWS][COLUMS]);

//Mostra o conteudo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMS]);

void drawBar(char matrix [ROWS][COLUMS], Bloco barra, int simbolo);


//Inicializa a peça do tipo : BARRA

void initBar(Bloco *barra);

//Rotação blocos do jogo

void rotate(Bloco *bloco);

//Verifica colisao de blocos

int collisionDetect(char matrix[ROWS][COLUMS], Bloco barra);
