#include <stdio.h>
#include <ctype.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int tamanhoTabuleiro = 10;
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];
    int linha;
    char coluna;
    int colunConvertida;
    int numJogadas = 2;
    int colunas;
    char colunasLentras[tamanhoTabuleiro];

    // LINHA: I coluna: J
    for (int il = 0; il < tamanhoTabuleiro; il++) {
        for (int ic = 0; ic < tamanhoTabuleiro; ic++) {
            tabuleiro[il][ic] = 0;   
        }   
    }
    
    printf("BEM VINDO AO JOGO BATALHA NAVAL: \n");
    printf("  ");
    for(int i = 0; i < tamanhoTabuleiro; i++){
        colunasLentras[i] = 'a'  + i;
    printf(" %c", colunasLentras[i]);
    }
    printf("\n");
    for (int il = 0; il < tamanhoTabuleiro; il++) {
        printf("%2d ", il + 1);

        for (int ic = 0; ic < tamanhoTabuleiro; ic++) {
        
            printf("%d ", tabuleiro[il][ic]);
        }
        printf("\n");
    }

    for (int i = 0; i < numJogadas; i++){
        int validarDoWhile = 0;
        do{
            printf("escolha a linha\n");
            int validarTipo = scanf(" %d", &linha);

            int validar1 = 0;
            while(validar1 == 0){
                if (linha > tamanhoTabuleiro || linha < 1 || validarTipo != 1){
                    printf("Entrada inválida! Digite um número entre 1 e %d.\n", tamanhoTabuleiro);
                    while(getchar() != '\n');
                    printf("escolha a linha\n");
                    validarTipo = scanf(" %d", &linha);
                }else {
                    validar1 = 1;
                }
            }

            printf("escolha a coluna\n");
            scanf(" %c", &coluna);
            int validar = 0;
            for(int i = 0; i < tamanhoTabuleiro; i++){
                if(coluna == colunasLentras[i]){
                    validar = 1;
                }
            }
            while(validar == 0){
                printf("tem que escolher o valor da coluna\n");
                for(int i = 0; i < tamanhoTabuleiro; i++){
                    printf(" %c ",colunasLentras[i]);
                }
                printf("\nescolha a coluna\n");
                scanf(" %c", &coluna);
                
                for(int i = 0; i < tamanhoTabuleiro; i++){
                    if(coluna == colunasLentras[i]){
                        validar = 1;
                    }
                }
            }
            
            colunConvertida = tolower(coluna) - 'a';

            if(tabuleiro[linha - 1][colunConvertida] == 0){
                tabuleiro[linha - 1][colunConvertida] = 3;
                validarDoWhile = 1;
            }else {
                printf("Você tem que escolher um espaço onde nao foi ocupado ainda\n");
            }
        }while(validarDoWhile == 0);
    }

    printf("NAVIO COLOCADOS \n");
    printf("  ");
    for(int i = 0; i < tamanhoTabuleiro; i++){
        colunasLentras[i] = 'a'  + i;
    printf(" %c", colunasLentras[i]);
    }
    printf("\n");
    for (int il = 0; il < tamanhoTabuleiro; il++) {
        printf("%2d ", il + 1);
        for (int ic = 0; ic < tamanhoTabuleiro; ic++) {
            printf("%d ", tabuleiro[il][ic]);
        }
        printf("\n");
    }

    return 0;
}
