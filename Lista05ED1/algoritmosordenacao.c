#include <stdio.h>
#include "algoritmosordenacao.h"


void insertionSort(int *vetor, int tamanho){
    int pivo, j;
    for (int i = 1; i<tamanho; i++)
    {
        pivo = vetor[i];
        j = i - 1;

        while(j>= 0 && vetor[j] > pivo){
            vetor[j+1] = vetor[j];
            j--; 
        }
        vetor[j+1] = pivo;
    }
}


void bubbleSort(int *vetor, int tamanho){
    int aux;
    for (int i = 0; i<tamanho;i++){
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}


void mergeSort(int *vetor, int tamanho){
    int meio, i, j, k;
    if (tamanho > 1) {
        meio = tamanho / 2;

        int esquerda[meio];
        int direita[tamanho - meio];

        for (i = 0; i < meio; i++)
            esquerda[i] = vetor[i];
        for (i = meio; i < tamanho; i++)
            direita[i - meio] = vetor[i];

        mergeSort(esquerda, meio);
        mergeSort(direita, tamanho - meio);

        i = 0; j = 0; k = 0;
        while (i < meio && j < (tamanho - meio)) {
            if (esquerda[i] <= direita[j]) {
                vetor[k++] = esquerda[i++];
            } else {
                vetor[k++] = direita[j++];
            }
        }
        while (i < meio) {
            vetor[k++] = esquerda[i++];
        }
        while (j < (tamanho - meio)) {
            vetor[k++] = direita[j++];
        }
    }
}


void quickSort(int *vetor, int tamanho){
    if (tamanho > 1) {
        int pivo = vetor[tamanho - 1];
        int i = -1, aux;

        for (int j = 0; j < tamanho - 1; j++) {
            if (vetor[j] < pivo) {
                i++;
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
        aux = vetor[i + 1];
        vetor[i + 1] = vetor[tamanho - 1];
        vetor[tamanho - 1] = aux;

        quickSort(vetor, i + 1);
        quickSort(vetor + i + 2, tamanho - i - 2);
    }
}
