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

int main (){
    int tamanho;
    int tipoteste;

    srand(time(NULL)); // Chame apenas uma vez

    do {
        printf("Como voce quer testar: \n");
        printf("1 - ARRAY 1.000 ELEMENTOS \n");
        printf("2 - ARRAY 100.000 ELEMENTOS \n");
        printf("3 - ARRAY 1.000.000 ELEMENTOS \n");
        printf("4 - ARRAY de CARACTERES \n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf ("%d", &tipoteste);

        switch (tipoteste) {

            case 1: {
                tamanho = 1000;
                int *vetor_original = (int *)malloc(tamanho * sizeof(int));
                int *vetor = (int *)malloc(tamanho * sizeof(int));
                preencherVetor(vetor_original, tamanho);

                clock_t inicio, fim;
                double tempo_gasto;

                // Bubble Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                bubbleSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo_gasto);

                // Insertion Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                insertionSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo_gasto);

                // Merge Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                mergeSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo_gasto);

                // Quick Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                quickSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo_gasto);

                printf("\nTeste Realizado com ARRAY 1.000 ELEMENTOS\n");
                printf("TESTE FINALIZADO\n");

                free(vetor_original);
                free(vetor);
              
                break;
            }

            case 2: {
                // ARRAY DE 100.000 ELEMENTOS
                tamanho = 100000;
                int *vetor_original = (int *)malloc(tamanho * sizeof(int));
                int *vetor = (int *)malloc(tamanho * sizeof(int));
                preencherVetor(vetor_original, tamanho);

                clock_t inicio, fim;
                double tempo_gasto;

                // Bubble Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                bubbleSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo_gasto);

                // Insertion Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                insertionSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo_gasto);

                // MergeSort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                mergeSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo_gasto);

                // QuickSort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                quickSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo_gasto);

                printf("Teste Realizado com ARRAY 100.000 ELEMENTOS \n");
                printf("TESTE FINALIZADO\n");

                free(vetor_original);
                free(vetor);
            
                break;
            }

            case 3: {
                // ARRAY DE 1.000.000 ELEMENTOS
                tamanho = 1000000;
                int *vetor_original = (int *)malloc(tamanho * sizeof(int));
                int *vetor = (int *)malloc(tamanho * sizeof(int));
                preencherVetor(vetor_original, tamanho);

                clock_t inicio, fim;
                double tempo_gasto;

                // Bubble Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                bubbleSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo_gasto);

                // Insertion Sort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                insertionSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo_gasto);

                // MergeSort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                mergeSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo_gasto);

                // QuickSort
                copiarVetor(vetor_original, vetor, tamanho);
                inicio = clock();
                quickSort(vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo_gasto);

                printf("Teste Realizado com ARRAY de 1.000.000 ELEMENTOS \n");
                printf("TESTE FINALIZADO\n");

                free(vetor_original);
                free(vetor);
            
                break;
            }

            case 4: {
                tamanho = 10000; // Alterado para 10.000 elementos
                char *vetor_original = (char *)malloc(tamanho * sizeof(char));
                char *vetor = (char *)malloc(tamanho * sizeof(char));

                // Preenche com caracteres aleatórios (A-Z)
                for (int i = 0; i < tamanho; i++) {
                    vetor_original[i] = 'A' + (rand() % 26);
                }

                clock_t inicio, fim;
                double tempo_gasto;

                // Bubble Sort
                memcpy(vetor, vetor_original, tamanho * sizeof(char));
                inicio = clock();
                bubbleSort((int*)vetor, tamanho); // cast para reutilizar a função
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nBubble Sort: %f segundos \n", tempo_gasto);

                // Insertion Sort
                memcpy(vetor, vetor_original, tamanho * sizeof(char));
                inicio = clock();
                insertionSort((int*)vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nInsertionSort: %f segundos \n", tempo_gasto);

                // Merge Sort
                memcpy(vetor, vetor_original, tamanho * sizeof(char));
                inicio = clock();
                mergeSort((int*)vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nmergeSort: %f segundos \n", tempo_gasto);

                // Quick Sort
                memcpy(vetor, vetor_original, tamanho * sizeof(char));
                inicio = clock();
                quickSort((int*)vetor, tamanho);
                fim = clock();
                tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nQuickSort: %f segundos \n", tempo_gasto);

                printf("Teste Realizado com ARRAY de CARACTERES (10.000 elementos)\n");
                printf("TESTE FINALIZADO\n");

                free(vetor_original);
                free(vetor);
             
                break;
            }
        }
    } while (tipoteste != 5);

    return 0;
}