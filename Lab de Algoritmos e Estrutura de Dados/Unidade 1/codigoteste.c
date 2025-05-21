#include <stdio.h>

int main()
{

FILE *arquivo;


arquivo = fopen("arquivo_texto.txt", "w");


fprintf(arquivo, "Este eh uma linha de exemplo. \n");
fprintf(arquivo, "Este eh outra linha de exemplo. \n");
fclose(arquivo);

	return 0;
}