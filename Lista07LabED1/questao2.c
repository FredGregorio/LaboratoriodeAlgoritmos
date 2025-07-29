#include <stdio.h>
#include <stdlib.h>


typedef struct No {


    int valor;
    struct No *proximo;
    struct No *anterior;


} No;



typedef struct {


    No *inicio;
    No *fim;


} Lista;


void inicializarLista(Lista *lista) {


    lista->inicio = NULL;
    lista->fim = NULL;


}


void inserir_no_inicio(Lista *lista, int valor) {


    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo;


    } else {


        lista->fim = novo; 

    }

    lista->inicio = novo;

}


void inserir_no_fim(Lista *lista, int valor) {


    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;

    if (lista->fim != NULL) {

        lista->fim->proximo = novo;

    } else {

        lista->inicio = novo; 

    }

    lista->fim = novo;
}


void remover(Lista *lista, int valor) {


    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;


    }

    No *atual = lista->inicio;

    while (atual != NULL && atual->valor != valor) {

        atual = atual->proximo;

    }

    if (atual == NULL) {


        printf("Valor %d nao encontrado na lista.\n", valor);
        return;
        
    }

    if (atual->anterior != NULL) {


        atual->anterior->proximo = atual->proximo;


    } else {


        lista->inicio = atual->proximo; 
    }

    if (atual->proximo != NULL) {

        atual->proximo->anterior = atual->anterior;

    } else {


        lista->fim = atual->anterior; 

    }

    free(atual);
    printf("Valor %d removido da lista.\n", valor);


}


int buscar(Lista *lista, int valor) {


    No *atual = lista->inicio;
    while (atual != NULL) {


        if (atual->valor == valor) {
            return 1; 

        }

        atual = atual->proximo;
    }

    
    return 0; 


}


void exibir(Lista *lista) {


    No *atual = lista->inicio;


    if (atual == NULL) {
        printf("Lista vazia.\n");
        return;


    }

    printf("Elementos da lista: ");


    while (atual != NULL) {


        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");


}



int main() {


    Lista lista;


    inicializarLista(&lista);


    inserir_no_inicio(&lista, 10);
    inserir_no_inicio(&lista, 20);
    inserir_no_fim(&lista, 30);
    inserir_no_fim(&lista, 40);



    exibir(&lista);
   



    remover(&lista, 20);
    exibir(&lista);

    remover(&lista, 40);

    exibir(&lista);


    return 0;


}