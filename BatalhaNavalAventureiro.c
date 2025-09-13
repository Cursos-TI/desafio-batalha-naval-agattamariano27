#include <stdio.h>

int main() {
    int tabuleiro [10][10]; //representação do tabuleiro, feito com matriz 10x10
    int navioHorizontal[3] = {3, 3, 3}; //Cria o navio que será posicionado horizontal em tamanho 3
    int navioVertical[3] = {3, 3, 3}; //Cria o navio que será posicionado vertical em tamanho 3
    int navioDiagonalDireita[3] = {3, 3, 3}; //Cria o navio que será posicionado diagonal em tamanho 3, movimentando para direita 
    int navioDiagonalEsquerda[3] = {3, 3, 3}; //Cria o navio que será posicionado diagonal em tamanho 3, movimentando para esquerda 
    int linhaHorizontal = 2; //Tanto a linha horizontal, quanto a coluna irão definir a coordenadas iniciais (Coordenadas iniciais do navio horizontal)
    int colunaHorizontal = 4;
    int linhaVertical = 5; //Tanto a linha vertical, quanto a coluna irão definir a coordenadas iniciais (Coordenadas iniciais do navio vertical)
    int colunaVertical = 1;
    int linhaDiagonalDIreita = 0; //Linha e coluna irão aumentar (Coordenadas iniciais do navio diagonal direita)
    int colunaDiagonalDireita = 0;
    int linhaDiagonalEsquerda = 0; //Linha aumenta e coluna diminui (Coordenadas iniciais do navio diagonal esquerda)
    int colunaDiagonalEsquerda = 9;

    //Inicia o tabuleiro com 0, que representa água
    for (int t = 0; t < 10; t++) //linhas
    {
        for (int a = 0; a < 10; a++) //colunas
        {
           tabuleiro[t][a] = 0; //Preenchimento da água
        } 
    }

    //Posição do navio horizontal na água/tabuleiro
    for (int t = 0; t < 3; t++)
    {
        tabuleiro[linhaHorizontal][colunaHorizontal + t] = navioHorizontal[t];
    }

    //Posição do navio vertical na água/tabuleiro
    for (int t = 0; t < 3; t++)
    {
       tabuleiro[linhaVertical + t][colunaVertical] = navioVertical[t];
    }
    
    //Posição do navio diagonal direita no tabuleiro
    for (int t = 0; t < 3; t++)
    {
        tabuleiro[linhaDiagonalDIreita + t][colunaDiagonalDireita + t] = navioDiagonalDireita[t];
    }

    //Posição do navio diagonal esquerda no tabuleiro
    for (int t = 0; t < 3; t++)
    {
       tabuleiro[linhaDiagonalEsquerda + t][colunaDiagonalEsquerda - t] = navioDiagonalEsquerda[t];
    }
    
    //Tabuleiro
    printf("Tabuleiro: \n");
    for (int t = 0; t < 10; t++) //linhas
    {
       for (int a = 0; a < 10; a++) //colunas
       {
        printf("%d", tabuleiro[t][a]); //Sera imprimido cada posição das peças
       }
       printf("\n"); //quebra de linha
    }
    
    

    return 0;
}
