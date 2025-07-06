#include <stdio.h>
#include "algoritmosordenacao.h"
#include <stdlib.h>
#include <time.h>

void preencherVetor (int *vetor, int tamanho) {
   int i;
   srand(time(NULL));
   for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;

}

}

void copiarVetor(int *origem, int *destino, int tamanho) {
   int i;
   for (i = 0; i < tamanho; i++) {
      destino[i] = origem[i];
   }
}

void imprimirVetor(int *vetor, int tamanho) {
   int i;
   for (i = 0; i < tamanho; i++) {
      printf( "%d", vetor[i]);
   }
   printf("\n");
}


int main (){
   int tamanho;
   int tipoteste;


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
      
      case 2:
      // ARRAY DE 100.000 ELEMENTOS
      tamanho = 100000;

      
         clock_t inicio, fim;
         double tempo_gasto;

      int *vetor_original = (int *)malloc(tamanho *sizeof(int));
      int *vetor = (int *)malloc(tamanho * sizeof(int));

      preencherVetor (vetor_original, tamanho);

      //Bubble Sort
      copiarVetor(vetor_original, vetor, tamanho);
      inicio = clock();
      bubbleSort(vetor,tamanho);
      fim = clock();
      tempo_gasto = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
      printf("\nBubble Sort: %f segundos \n", tempo_gasto);

      // insertionSort
      inicio = clock();
      insertionSort(vetor,tamanho);
      fim = clock();
      tempo_gasto = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
      printf("\nInsertionSort: %f segundos \n", tempo_gasto);

      // MergeSort
      inicio = clock();
      mergeSort(vetor,tamanho);
      fim = clock();
      tempo_gasto = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
      printf("\nmergeSort: %f segundos \n", tempo_gasto);

      // QuickSort
      inicio = clock();
      quickSort(vetor,tamanho);
      fim = clock();
      tempo_gasto = ((double)(fim - inicio))/ CLOCKS_PER_SEC;
      printf("\nQuickSort: %f segundos \n", tempo_gasto);

      printf("Teste Realizado com ARRAY 100.000 ELEMENTOS \n");
      printf("TESTE FINALIZADO\n");
      
      break;

      case 3: {
         // ARRAY DE 1.000.000 ELEMENTOS
         tamanho = 1000000;
         int *vetor_original = (int *)malloc(tamanho * sizeof(int));
         int *vetor = (int *)malloc(tamanho * sizeof(int));
         preencherVetor(vetor_original, tamanho);

         clock_t inicio, fim;
         double tempo_gasto;

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

      case 4:
      //ARRAY DE CARACTERES










      printf("Teste Realizado com ARRAY de CARACTERES \n");
      printf("TESTE FINALIZADO\n");
      
      break;
   


   }
} while (tipoteste != 5);





   return 0;

}