#include <stdio.h>
#include "algoritmosordenacao.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void preencherVetor (int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

void copiarVetor(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void imprimirVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void copiarVetorChar(char *origem, char *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main (){
    int tamanho;
    int opcao;

    srand(time(NULL)); 

    do {
        printf("Como voce quer testar: \n");
        printf("1 - ARRAY 1.000 ELEMENTOS \n");
        printf("2 - ARRAY 100.000 ELEMENTOS \n");
        printf("3 - ARRAY 1.000.000 ELEMENTOS \n");
        printf("4 - ARRAY de CARACTERES \n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf ("%d", &opcao);

        switch (opcao) {

            case 1: {
                tamanho = 1000;
                int *vetorOriginal = (int *)malloc(tamanho * sizeof(int));
                int *vetor = (int *)malloc(tamanho * sizeof(int));
                preencherVetor(vetorOriginal, tamanho);

                clock_t inicio, fim;
                double tempo;

                // Bubble Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                bubbleSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo);

                // Insertion Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                insertionSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo);

                // Merge Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                mergeSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo);

                // Quick Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                quickSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo);

                printf("\nTeste Realizado com ARRAY 1.000 ELEMENTOS\n");
                printf("TESTE FINALIZADO\n");

                free(vetorOriginal);
                free(vetor);
              
                break;
            }

            case 2: {
                // ARRAY DE 100.000 ELEMENTOS
                tamanho = 100000;
                int *vetorOriginal = (int *)malloc(tamanho * sizeof(int));
                int *vetor = (int *)malloc(tamanho * sizeof(int));
                preencherVetor(vetorOriginal, tamanho);

                clock_t inicio, fim;
                double tempo;

                // Bubble Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                bubbleSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo);

                // Insertion Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                insertionSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo);

                // MergeSort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                mergeSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo);

                // QuickSort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                quickSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo);

                printf("Teste Realizado com ARRAY 100.000 ELEMENTOS \n");
                printf("TESTE FINALIZADO\n");

                free(vetorOriginal);
                free(vetor);
            
                break;
            }

            case 3: {
                // ARRAY DE 1.000.000 ELEMENTOS
                tamanho = 1000000;
                int *vetorOriginal = (int *)malloc(tamanho * sizeof(int));
                int *vetor = (int *)malloc(tamanho * sizeof(int));
                preencherVetor(vetorOriginal, tamanho);

                clock_t inicio, fim;
                double tempo;

                // Bubble Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                bubbleSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo);

                // Insertion Sort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                insertionSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo);

                // MergeSort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                mergeSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo);

                // QuickSort
                copiarVetor(vetorOriginal, vetor, tamanho);
                inicio = clock();
                quickSort(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo);

                printf("Teste Realizado com ARRAY de 1.000.000 ELEMENTOS \n");
                printf("TESTE FINALIZADO\n");

                free(vetorOriginal);
                free(vetor);
            
                break;
            }

            case 4: {
                tamanho = 10000; // 10.000 elementos
                char *vetorOriginal = (char *)malloc(tamanho * sizeof(char));
                char *vetor = (char *)malloc(tamanho * sizeof(char));

                // Preenche com caracteres aleatórios (A-Z)
                for (int i = 0; i < tamanho; i++) {
                    vetorOriginal[i] = 'A' + (rand() % 26);
                }

                clock_t inicio, fim;
                double tempo;

                // Bubble Sort
                copiarVetorChar(vetorOriginal, vetor, tamanho);
                inicio = clock();
                bubbleSortChar(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo);

                // Insertion Sort
                copiarVetorChar(vetorOriginal, vetor, tamanho);
                inicio = clock();
                insertionSortChar(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo);

                // Merge Sort
                copiarVetorChar(vetorOriginal, vetor, tamanho);
                inicio = clock();
                mergeSortChar(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo);

                // Quick Sort
                copiarVetorChar(vetorOriginal, vetor, tamanho);
                inicio = clock();
                quickSortChar(vetor, tamanho);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo);

                printf("Teste Realizado com ARRAY de CARACTERES (10.000 elementos)\n");
                printf("TESTE FINALIZADO\n");

                free(vetorOriginal);
                free(vetor);

                break;
            }
        }
        
    } while (opcao != 5);

    return 0;
}