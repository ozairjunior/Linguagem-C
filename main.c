#include <stdio.h>

int Fatorial();
int menu();
int primo();
int quant_primos();
int Potencia();
int raiz();
int Ano_Bissexto();
int media();
int media_ponderada();
int nome_matr();

int main()
{
    int chave;

    chave = menu(chave);

    while(chave != 0){
        switch(chave){

        case 1:
        Fatorial();
        chave = menu(chave);
        break;

        case 2:
        quant_primos();
        chave = menu(chave);
        break;

        case 3:
        quant_primos();
        chave = menu(chave);
        break;

        case 4:
        Potencia();
        chave = menu(chave);
        break;

        case 5:
        raiz();
        chave = menu(chave);
        break;

        case 6:
        Ano_Bissexto();
        chave = menu(chave);
        break;

        case 7:
        media();
        chave = menu(chave);
        break;

        case 8:
        media_ponderada();
        chave = menu(chave);
        break;

        case 9:
        nome_matr();
        chave = menu(chave);
        break;

        default:
        printf("\nDigite um numero valido !!!\n");
        chave = menu(chave);
        break;

        }
    }

    return 0;
}

int menu(int chave){

    printf("\n###################################\n");
    printf(" *    1-Fatorial de um Numero         \n");
    printf(" *    2-Verificar numeros Primo       \n");
    printf(" *    3-Vrificar a Quantidade Primos  \n");
    printf(" *    4-Calcular a Potencia           \n");
    printf(" *    5-Calcular a Raiz               \n");
    printf(" *    6-Verificar se e Bissexto       \n");
    printf(" *    7-Calcular a Media              \n");
    printf(" *    8-Calcular a Media Ponderada    \n");
    printf(" *    9-Nome e matricula              \n");
    printf(" *        Aprete 0 para Sair          \n");
    printf("#####################################\n");

    printf("\nEscolha uma opcao: \n");
    scanf("%i", &chave);

return(chave);
}

int Fatorial(){
     //numero 1 na lista do menu
    int c, n, fat;

    printf("\n Insira um numero para calcular seu fatorial: ");
    scanf("%i", &n);

    fat = 1;

    for(c=1; c<=n; c++)
        {
            fat *= c;
        }
    printf("\nO fatorial do numero %i e: %i\n",n, fat);

    return 0 ;
}

int primo(){
    //numero 2 na lista do menu
    int i,num;

    printf("informe um numeor: ");
    scanf("%i",&num);

    if (num > 0 ){
        if (num == 1 ) {
            printf ( "\n 1 e primo.\ n ");
    }

    for(i = (num-1); i >= 1 ; i--){
      if (num %i == 0 && i != 1 || i == 1){
          printf ( "\n%i nao e primo.\n", num);
          break ;
      }
      else{
        if (i == 2){
          printf ( "\n%i e primo.\n", num);
          break;
        }
      }
    }
  }
  else
  {
    printf(" \nNumero invalido.\n");
  }

  return  0 ;
}

int quant_primos(){
     //numero 3 na lista do menu
    int n, i, total;

    printf("informe quantos numero deseja verificar: ");
    scanf("%d", &total);

    if(total > 0){
        for(i = 1;i <= total; i++){
            printf("numero %d: ", i);
            scanf("%d", &n);
            primo(n);
        }
    }
    else{
        printf("invalido");
    }


    return 0;
}

int Potencia(){
     //numero 4 na lista do menu
    float a, cont;
    int b;

    printf("\nInforme um numero de ponto flutuante\n");
    scanf("%f", &a);
    printf("\nInforme um numero inteiro\n");
    scanf("%d", &b);

    cont = pow(a,b);

    printf("\nSua potencia e: %.4e\n", cont);

    return 0;
}

int raiz(){
    //numero 5 na lista do menu.
    float a, result;
    int b;

    printf("\nInforme um numero de ponto flutuante\n");
    scanf("%f", &a);

    printf("\nInforme um numero inteiro\n");
    scanf("%d", &b);

    result = (float)1/b;

    printf("\nSua raiz e: %.4e\n", pow(a,result));

    return 0;
}

int Ano_Bissexto(){
    //numero 6 na lista do menu.
    int ano;

    printf("\nQual o ano voce deseja consultar\n");
    scanf("%d", &ano);

    if(ano > 0){
        if((ano%4) == 0){
            printf("\n%i e bissexto\n", ano);
        }else{
            printf("\n%i nao e bissexto\n", ano);
        }
    }else{
        printf("numero invalido\n");
    }
    return 0;
}

int media(){
    //numero 7 na lista do menu.
    float n1, n2, nF;

    printf("\nInforme sua primeira nota:\n");
    scanf("%f", &n1);

    printf("\nInforme sua segunda nota:\n");
    scanf("%f", &n2);

    if((n1 >= 0 && n1 <= 10) && (n2 >= 0 && n2 <= 10)){
        nF = (n1 + n2)/2;
        printf("\nA media final e %.2f\n", nF);
    }else{
        printf("\nAS notas sao invalidas\n");
    }

    return 0;
}


int media_ponderada (){
    //numero 8 na lista do menu.
    float n1, n2, n3, media;

    printf("\nInforme sua primeira nota:\n");
    scanf("%f", &n1);

    printf("\nInfome sua segunda nota:\n");
    scanf("%f", &n2);

    printf("\nInforme sua terceira nota:\n");
    scanf("%f", &n3);

    media = (n1 + n2 +(n3*2))/4;

    if(media >= 60){
        printf("\n\nAprovado com media %.2f\n", media);
    }else{
        printf("\n\nReprovado com media %.2f\n",media);
    }

    return 0;
}

int nome_matr(){
    //numero 9 na lista do menu.
    printf("########################\n");
    printf("      Nome: Ozair Barsosa   \n");
    printf("      Matricula: 1810022047 \n");
    printf("########################\n");

    return 0;
}
