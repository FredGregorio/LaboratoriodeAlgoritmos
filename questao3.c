#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No *proximo;
} No;


typedef struct {
    No *inicio;
} Lista;


void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
}


void inserir_no_inicio(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    novo->valor = valor;

    if (lista->inicio == NULL) {
    
        novo->proximo = novo;
        lista->inicio = novo;
    } else {
   
        No *atual = lista->inicio;
        while (atual->proximo != lista->inicio) {
            atual = atual->proximo;
        }
     
        novo->proximo = lista->inicio;
        atual->proximo = novo;
        lista->inicio = novo;
    }
}


void inserir_no_fim(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    novo->valor = valor;

    if (lista->inicio == NULL) {
        
        novo->proximo = novo;
        lista->inicio = novo;
    } else {
  
        No *atual = lista->inicio;
        while (atual->proximo != lista->inicio) {
            atual = atual->proximo;
        }
     
        atual->proximo = novo;
        novo->proximo = lista->inicio;
    }
}


void remover(Lista *lista, int valor) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    No *anterior = NULL;

    do {
        if (atual->valor == valor) {
            if (anterior == NULL) {
             
                No *ultimo = lista->inicio;
                while (ultimo->proximo != lista->inicio) {
                    ultimo = ultimo->proximo;
                }
                if (atual->proximo == lista->inicio) {
                    
                    lista->inicio = NULL;
                } else {
                    lista->inicio = atual->proximo;
                    ultimo->proximo = lista->inicio;
                }
            } else {
                
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Valor %d removido da lista.\n", valor);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->inicio);

    printf("Valor %d nao encontrado na lista.\n", valor);
}


int buscar(Lista *lista, int valor) {
    if (lista->inicio == NULL) {
        return 0; 
    }

    No *atual = lista->inicio;
    do {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    } while (atual != lista->inicio);

    return 0; 
}


void exibir(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    printf("Elementos da lista: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != lista->inicio);
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