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

}



void quickSort(int *vetor, int tamanho){

    
}
