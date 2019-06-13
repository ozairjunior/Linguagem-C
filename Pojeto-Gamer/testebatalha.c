#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

void exibe_tabuleiro(char **criptografada, int tamanho_linha, int tamanho_coluna)
{

    HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j;

    for(i = 0; i < tamanho_linha; i++)
    {
        printf("\t\t\t\t");
        printf("%d- ", i+1);
        for(j = 0; j < tamanho_coluna; j++)
        {
            if(criptografada[i][j] == '~') SetConsoleTextAttribute(cor, 3);
            else if(criptografada[i][j] == '<' || criptografada[i][j] == '=' || criptografada[i][j] == '>') SetConsoleTextAttribute(cor, 4);
            printf(" %c ", criptografada[i][j]);
            SetConsoleTextAttribute(cor, 15);
        }
        putchar('\n');
    }
    printf("\t\t\t\t    ");
    for (j = 1; j <= tamanho_coluna; j++){
        printf("%d  ", j);
    }
}

void movimenta(char **matriz, char **criptografada, int linha_jogada, int coluna_jogada)
{

    criptografada[linha_jogada][coluna_jogada] = matriz[linha_jogada][coluna_jogada];
}

int verifica(char **criptografada, int linha_jogada, int coluna_jogada, int linhas, int colunas)
{

    if((linha_jogada <= linhas && coluna_jogada <= colunas) && (linha_jogada >=0 && coluna_jogada >= 0))
    {
        if(criptografada[linha_jogada][coluna_jogada] == '*')
        {
            return 1;
        }
    }
    return 0;
}

void coordenadas(int *linha_jogada, int *coluna_jogada)
{

    printf("\n\t\t\t\tdigite uma linha: ");
    scanf("%d",linha_jogada);
    printf("\n\t\t\t\tdigite uma coluna: ");
    scanf("%d",coluna_jogada);

}

void opcao_matriz(int * linhas, int * colunas)
{

    int opcao;

    puts("\n\n\t\t\t\tInforme um nivel de dificuldade: ");
    puts("\n\n\t\t\t\t[1] FACIL - MATRIZ 5 X 5");
    puts("\t\t\t\t[2] INTERMEDIARIO - MATRIZ 7 X 7");
    puts("\t\t\t\t[3] DIFICIL - MATRIZ 10 X 10\n\t\t\t\t");
    printf("\t\t\t\tEscolha o modo que mais lhe agrada: ");

    while(1)
    {
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
        case 1:
            (*linhas) = 5, (*colunas) = 5;
            break;
        case 2:
            (*linhas) = 7, (*colunas) = 7;
            break;
        case 3:
            (*linhas) = 10, (*colunas) = 10;
            break;
        default:
            printf("\t\t\t\tOpcao invalida!\n\t\t\t\tEscolha uma opcao valida: ");

        }

        if(opcao == 1 || opcao == 2 || opcao == 3)
            break;
    }
}

void navios(char ** matriz, int tamanho_linha, int tamanho_coluna)
{

    int qnt_barcos = 5, qnt_jogada = 0, poslinha, poscoluna, barcos;

    srand(time(NULL));

    while(qnt_barcos > qnt_jogada)
    {

        poslinha = rand () % tamanho_linha;
        poscoluna = rand () % tamanho_coluna;

        barcos = rand () % 3;

        if(matriz[poslinha][poscoluna] == '~')
        {
            if(barcos == 0)
            {
                if(matriz[poslinha][poscoluna+1] == '~')
                {
                    matriz[poslinha][poscoluna] = '<';
                    matriz[poslinha][poscoluna+1] = '>';
                    qnt_jogada++;
                }
            }
            else if(barcos == 1)
            {
                if(matriz[poslinha][poscoluna+1] == '~' && matriz[poslinha][poscoluna+2] == '~')
                {
                    matriz[poslinha][poscoluna] = '<';
                    matriz[poslinha][poscoluna+1] = '=';
                    matriz[poslinha][poscoluna+2] = '>';
                    qnt_jogada++;
                }
            }
            else
            {
                if(matriz[poslinha][poscoluna+1] == '~' && matriz[poslinha][poscoluna+2] == '~' && matriz[poslinha][poscoluna+3] == '~')
                {
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

void criando_matriz(char ** matriz, char ** criptografada, int linhas, int colunas)
{
    int i, j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            matriz[i][j] = '~';
            criptografada[i][j] = '*';
        }
    }

    navios(matriz, linhas, colunas);
}

int pontuacao(char **criptografada, int linha_jogada, int coluna_jogada, int vez, int *pontos_jogador1, int *pontos_jogador2)
{

    if(criptografada[linha_jogada][coluna_jogada] == '<' || criptografada[linha_jogada][coluna_jogada] == '=' || criptografada[linha_jogada][coluna_jogada] == '>')
    {
        if(vez == 1)
        {
            (*pontos_jogador1)++;
        }
        else if(vez == 2)
        {
            (*pontos_jogador2)++;
        }
        return 1;
    }

    return 0;
}

int main(void)
{

    int tentativa = 0, jogadasmax, max_tentativa = 20, controle = 1, vez = 1;

    char ** matriz, ** criptografada;
    int i, j, linhas, colunas, linha_jogada, coluna_jogada, pontos_jogador1 = 0, pontos_jogador2 = 0;

    opcao_matriz(&linhas, &colunas);

    jogadasmax = linhas * colunas;

    matriz = (char **) malloc(linhas * sizeof(char *));
    criptografada = (char **) malloc(linhas * sizeof(char *));

    for(i = 0; i < linhas; i++)
    {
        matriz[i] = (char *) malloc(colunas * sizeof(char));
        criptografada[i] = (char *) malloc(colunas * sizeof(char));
    }

    criando_matriz(matriz, criptografada, linhas, colunas);

    system("cls");

    while(tentativa < jogadasmax)
    {

        while(controle)
        {

            printf("\n\t\t\tJogador 1: %d pontos --- Jogador 2: %d pontos\n", pontos_jogador1, pontos_jogador2);

            printf("\n\t\t\t\t   Vez do jogador %d\n\n", vez);

            exibe_tabuleiro(criptografada, linhas, colunas);

            coordenadas(&linha_jogada, &coluna_jogada);

            if(verifica(criptografada, linha_jogada-1, coluna_jogada-1, linhas, colunas))
            {
                movimenta(matriz, criptografada, linha_jogada-1, coluna_jogada-1);
                tentativa++;

                if(pontuacao(criptografada, linha_jogada-1, coluna_jogada-1, vez, &pontos_jogador1, &pontos_jogador2))
                {
                    controle = 1;
                }
                else
                {
                    controle = 0;
                }
            }

            system("cls");
        }

        vez = vez == 1 ? 2 : 1;

        controle = 1;
    }

    printf("\n\t\t\tO jogador %d ganhou por %d x %d\n\n", pontos_jogador1 > pontos_jogador2 ? 1 : 2);

    return 0;
}
