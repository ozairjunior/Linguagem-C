#include <stdio.h>
#include "string.c"
#include <string.h>

int main(){
    char primeira[50] = {"olar"};
    char segunda[50] = {"mundo"};

    //faz uma c�pia do conte�do de uma vari�vel para outra.
	str_cpy(primeira, segunda);
	printf("\n%s", primeira);

    //Compara o conte�do das strings;
	printf("\n%d", str_cmp(primeira, segunda));

    //mostra o tamanho da string.
	printf("\n%d", str_len(primeira));

    //faz uma concatena��o do conte�do de uma vari�vel a outra.
	str_cat(primeira, segunda);
	printf("\n%s\n", primeira);

	return 0;
}
