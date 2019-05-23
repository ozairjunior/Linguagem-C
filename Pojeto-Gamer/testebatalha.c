#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void exibe_tabuleiro(char **criptografada, int tamanho_linha, int tamanho_coluna){

    int i, j;

    for(i = 0; i < tamanho_linha; i++){
        printf("\t\t\t\t");
        for(j = 0; j < tamanho_coluna; j++){
            printf(" %c ", criptografada[i][j]);
        }
        putchar('\n');
    }
}

void movimenta(char **matriz, char **criptografada, int linha_jogada, int coluna_jogada){

    criptografada[linha_jogada][coluna_jogada] = matriz[linha_jogada][coluna_jogada];
}

int verifica(char **criptografada, int linha_jogada, int coluna_jogada, int linhas, int colunas){

    if((linha_jogada <= linhas && coluna_jogada <= colunas) && (linha_jogada >=0 && coluna_jogada >= 0)){
        if(criptografada[linha_jogada][coluna_jogada] == '*'){
            return 1;
        }
    }
    return 0;
}

void coordenadas(int *linha_jogada, int *coluna_jogada){

    printf("\n\t\t\t\tdigite uma linha: ");
    scanf("%d",linha_jogada);
    printf("\n\t\t\t\tdigite uma coluna: ");
    scanf("%d",coluna_jogada);

}

void opcao_matriz(int * linhas, int * colunas){

    int opcao;

    puts("\n\n\t\t\t\tInforme um nivel de dificuldade: ");
    puts("\n\n\t\t\t\t[1] FACIL - MATRIZ 5 X 5");
    puts("\t\t\t\t[2] INTERMEDIARIO - MATRIZ 7 X 7");
    puts("\t\t\t\t[3] DIFICIL - MATRIZ 10 X 10\n\t\t\t\t");
    printf("\t\t\t\tEscolha o modo que mais lhe agrada: ");
    scanf("%d", &opcao);
    printf("\n");

    switch(opcao){
    case 1:
        (*linhas) = 5, (*colunas) = 5;
        break;
    case 2:
        (*linhas) = 7, (*colunas) = 7;
        break;
    case 3:
        (*linhas) = 10, (*colunas) = 10;
        break;
    }
}

void navios(char ** matriz, int tamanho_linha, int tamanho_coluna){

    int qnt_barcos = 5, qnt_jogada = 0, poslinha, poscoluna, barcos;

    srand(time(NULL));

    while(qnt_barcos > qnt_jogada){

        poslinha = rand () % tamanho_linha;
        poscoluna = rand () % tamanho_coluna;

        barcos = rand () % 3;

        if(matriz[poslinha][poscoluna] == '~'){
            if(barcos == 0){
                if(matriz[poslinha][poscoluna+1] == '~'){
                    matriz[poslinha][poscoluna] = '<';
                    matriz[poslinha][poscoluna+1] = '>';
                    qnt_jogada++;
                }
            }
            else if(barcos == 1){
                if(matriz[poslinha][poscoluna+1] == '~' && matriz[poslinha][poscoluna+2] == '~'){
                    matriz[poslinha][poscoluna] = '<';
                    matriz[poslinha][poscoluna+1] = '=';
                    matriz[poslinha][poscoluna+2] = '>';
                    qnt_jogada++;
                }
            }
            else{
                if(matriz[poslinha][poscoluna+1] == '~' && matriz[poslinha][poscoluna+2] == '~' && matriz[poslinha][poscoluna+3] == '~'){
                    matriz[poslinha][poscoluna] = '<';
                    matriz[poslinha][poscoluna+1] = '=';
                    matriz[poslinha][poscoluna+2] = '=';
                    matriz[poslinha][poscoluna+3] = '>';
                    qnt_jogada++;
                }
            }
        }
    }
}

void criando_matriz(char ** matriz, char ** criptografada, int linhas, int colunas){
    int i, j;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            matriz[i][j] = '~';
            criptografada[i][j] = '*';
        }
    }

    navios(matriz, linhas, colunas);
}

int main(void){

    char ** matriz, ** criptografada;
    int linhas, colunas, linha_jogada, coluna_jogada;
    int i, j;

    opcao_matriz(&linhas, &colunas);

    matriz = (char **) malloc(linhas * sizeof(char *));
    criptografada = (char **) malloc(linhas * sizeof(char *));

    for(i = 0; i < linhas; i++){
        matriz[i] = (char *) malloc(colunas * sizeof(char));
        criptografada[i] = (char *) malloc(colunas * sizeof(char));
    }

    criando_matriz(matriz, criptografada, linhas, colunas);

    exibe_tabuleiro(criptografada, linhas, colunas);

    coordenadas(&linha_jogada, &coluna_jogada);

    if(verifica(criptografada, linha_jogada, coluna_jogada, linhas, colunas)){
            movimenta(matriz, criptografada, linha_jogada, coluna_jogada);
    }

    exibe_tabuleiro(criptografada, linhas, colunas);

  return 0;
}
