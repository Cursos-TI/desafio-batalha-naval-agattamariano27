#include <stdio.h>

int main() {
    int tabuleiro [10][10]; //representação do tabuleiro, feito com matriz 10x10
    int navioHorizontal[3] = {3, 3, 3}; //Cria o navio que será posicionado horizontal em tamanho 3
    int navioVertical[3] = {3, 3, 3}; //Cria o navio que será posicionado vertical em tamanho 3
    int linhaHorizontal = 2; //Tanto a linha horizontal, quanto a coluna irão definir a coordenadas iniciais
    int colunaHorizontal = 4;
    int linhaVertical = 5; //Tanto a linha vertical, quanto a coluna irão definir a coordenadas iniciais
    int colunaVertical = 1;

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
