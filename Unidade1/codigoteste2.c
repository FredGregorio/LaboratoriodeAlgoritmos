#include <stdio.h>

int main()
{

FILE *arquivo;
char c;

arquivo = fopen("arquivo_texto.txt", "r");

printf("Conteudo do arquivo: \n");



while ((c = fgetc(arquivo)) != EOF) {

putchar(c);    
    
}

printf("\n");

	return 0;
}