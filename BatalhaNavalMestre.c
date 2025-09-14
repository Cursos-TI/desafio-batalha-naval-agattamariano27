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
    int cone[5][5]; //habilidade do cone, em 5x5 matriz
    int cruz[5][5]; //habilidade da cruz
    int octaedro[5][5]; //habilidade do octaedro
    int ConeLinha = 0, ConeColuna = 2; //Pontos de origem no tabuleiro
    int CruzLinha = 5, CruzColuna = 2;
    int OctaedroLinha = 2, OctaedroColuna = 7;
  
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

    //Cone
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if((i == 0 && j == 2) ||      // topo
            (i == 1 && j >= 1 && j <= 3) ||  //segunda linha
            (i == 2 && j >= 0 && j <= 4) ||  // terceira linha
            (i == 3 && j >= 0 && j <= 4) ||  //quarta linha
            (i == 4 && j >= 0 && j <= 4))    //última linha
            {
               cone[i][j] = 1; 
            } else {
                cone[i][j] = 0; 
            }
        }
    }
    
    //Cruz
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2 ) //coluna e linha central
            {
               cruz[i][j] = 1; //posições afetadas
            } else {
               cruz[i][j] = 0; //posições não afetadas
            }
        }
    }
    
    //Octaedro
     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == 0 && j >= 2 && j <= 2) ||  // topo
            (i == 1 && j >= 1 && j <= 3) ||  // segunda linha
            (i == 2 && j >= 0 && j <= 4) ||  // linha do meio
            (i == 3 && j >= 1 && j <= 3) ||  // quarta linha
            (i == 4 && j >= 2 && j <= 2))    //última linha
            {
               octaedro[i][j] = 1;
            } else {
               octaedro[i][j] = 0; 
            }
        }
    }
    
    //Sobreposição do cone
    for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        int linhaTabuleiro = ConeLinha + i;
        int colunaTabuleiro = ConeColuna - 2 + j; // centraliza a matriz de 5x5
        if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
            if (cone[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // marca a área afetada sem sobrescrever navios
            }
          }
       }
   }
    
   //Sobreposição da cruz
   for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        int linhaTabuleiro = CruzLinha - 2 + i;  // centraliza a matriz 5x5 no ponto de origem
        int colunaTabuleiro = CruzColuna - 2 + j;
        if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
            if (cruz[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
         }
      }
   }

   //Sobreposição do octaedro
   for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        int linhaTabuleiro = OctaedroLinha - 2 + i;  // centraliza a matriz 5x5
        int colunaTabuleiro = OctaedroColuna - 2 + j;
        if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10) {
            if (octaedro[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
         }
      }
   }
    
    //Tabuleiro
    printf("Tabuleiro: \n");
    for (int t = 0; t < 10; t++) //linhas
    {
       for (int a = 0; a < 10; a++) //colunas
       {
       if (tabuleiro[t][a] == 0)
            printf("0 "); // água
        else if (tabuleiro[t][a] == 3)
            printf("3 "); // navio
        else if (tabuleiro[t][a] == 5)
            printf("5 "); // área de efeito da habilidade
       }
       printf("\n"); //quebra de linha
    }
    
    

    return 0;
}
