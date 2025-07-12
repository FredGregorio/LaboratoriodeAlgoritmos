#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algoritmosordenacao.h"


void preencherVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

void copiarVetor(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Busca Sequencial
int buscaSequencial(int *vetor, int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == chave)
            return i;
    }
    return -1;
}

// Busca Binária (Vetor tem que ta ordenado)
int buscaBinaria(int *vetor, int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == chave)
            return meio;
        else if (vetor[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

// Busca Sequencial em texto
int buscaSequencialTexto(const char *texto, const char *palavra) {
    int tamTexto = strlen(texto);
    int tamPalavra = strlen(palavra);
    for (int i = 0; i <= tamTexto - tamPalavra; i++) {
        if (strncmp(&texto[i], palavra, tamPalavra) == 0)
            return i;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int opcao, tamanho, chave;
    char palavra[100];

    do {
        printf("\nComo voce quer testar:\n");
        printf("1 - Array com 1.000 elementos\n");
        printf("2 - Array com 100.000 elementos\n");
        printf("3 - Array com 1.000.000 elementos\n");
        printf("4 - Buscar palavra em texto\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                tamanho = 1000;
                int *vetor = malloc(tamanho * sizeof(int));
                int *vetorOrdenado = malloc(tamanho * sizeof(int));
                preencherVetor(vetor, tamanho);
                copiarVetor(vetor, vetorOrdenado, tamanho);

                printf("Digite o valor inteiro a ser buscado: ");
                getchar(); // Limpa o buffer antes de ler o valor
                scanf("%d", &chave);

                // Ordena para usar a busca binaria
                mergeSort(vetorOrdenado, tamanho);

                clock_t inicio, fim;
                double tempo;

                // Busca Sequencial
                inicio = clock();
                int posSeq = buscaSequencial(vetor, tamanho, chave);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Busca Sequencial: %f segundos. Posicao Sequencial: %d\n", tempo, posSeq);

                // Busca Binária
                inicio = clock();
                int posBin = buscaBinaria(vetorOrdenado, tamanho, chave);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Busca Binaria: %f segundos. Posicao Binaria: %d\n", tempo, posBin);

                free(vetor);
                free(vetorOrdenado);
                break;
            }
            case 2: {
                tamanho = 100000;
                int *vetor = malloc(tamanho * sizeof(int));
                int *vetorOrdenado = malloc(tamanho * sizeof(int));
                preencherVetor(vetor, tamanho);
                copiarVetor(vetor, vetorOrdenado, tamanho);

                printf("Digite o valor inteiro a ser buscado: ");
                getchar(); // Limpa o buffer antes de ler o valor
                scanf("%d", &chave);

                mergeSort(vetorOrdenado, tamanho);

                clock_t inicio, fim;
                double tempo;

                inicio = clock();
                int posSeq = buscaSequencial(vetor, tamanho, chave);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Busca Sequencial: %f segundos. Posicao Sequencial: %d\n", tempo, posSeq);

                inicio = clock();
                int posBin = buscaBinaria(vetorOrdenado, tamanho, chave);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Busca Binaria: %f segundos. Posicao Binaria: %d\n", tempo, posBin);

                free(vetor);
                free(vetorOrdenado);
                break;
            }
            case 3: {
               
            }
            case 4: {
                getchar();
                char texto[1000];
                printf("Digite algum texto com no maximo 999 caracteres:\n");
                fgets(texto, 1000, stdin);
                texto[strcspn(texto, "\n")] = 0; 

                printf("Digite a palavra a ser buscada:\n");
                fgets(palavra, 100, stdin);
                palavra[strcspn(palavra, "\n")] = 0;

                clock_t inicio = clock();
                int pos = buscaSequencialTexto(texto, palavra);
                clock_t fim = clock();
                double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                if (pos != -1)
                    printf("Palavra '%s' encontrada na posicao %d em %f segundos.\n", palavra, pos, tempo);
                else
                    printf("Palavra '%s' nao encontrada em %f segundos.\n", palavra, tempo);
                break;
            }
        }
    } while (opcao != 5);

    return 0;
}