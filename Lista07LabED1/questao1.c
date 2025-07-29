#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct No {


    int valor;
    struct No *proximo;


} No;

// Estrutura da lista encadeada
typedef struct {

    No *inicio;

} Lista;


void inicializarLista(Lista *lista) {


    lista->inicio = NULL;

}

void inserir_no_inicio(Lista *lista, int valor) {


    No *novo = (No *)malloc(sizeof(No));


    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;

}


void inserir_no_fim(Lista *lista, int valor) {


    No *novo = (No *)malloc(sizeof(No));
    


    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {

        lista->inicio = novo;

    } else {

        No *atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;

        }

        atual->proximo = novo;
    }
}


void remover(Lista *lista, int valor) {


    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;

    }


    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {


        anterior = atual;
        atual = atual->proximo;

    }

    if (atual == NULL) {

        printf("Valor %d nao encontrado na lista.\n", valor);
        return;

    }

    if (anterior == NULL) {

        lista->inicio = atual->proximo; 


    } else {


        anterior->proximo = atual->proximo;

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