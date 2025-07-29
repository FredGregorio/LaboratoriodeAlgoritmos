#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para os dados dos ttitulos
typedef struct Titulo {
    char nome[100];
    int ano;
    char categoria[50];
    struct Titulo *proximo;
} Titulo;

// Estrutura da lista encadeada
typedef struct {
    Titulo *inicio;
} Lista;


void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
}


void adicionarTitulo(Lista *lista, const char *nome, int ano, const char *categoria) {
    Titulo *novo = (Titulo *)malloc(sizeof(Titulo));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->ano = ano;
    strcpy(novo->categoria, categoria);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}


void listarTitulosOrdenados(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Nenhum titulo no catalogo.\n");
        return;
    }


    int count = 0;
    Titulo *atual = lista->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    //array para ordenar os títulos
    Titulo **array = (Titulo **)malloc(count * sizeof(Titulo *));
    atual = lista->inicio;
    for (int i = 0; i < count; i++) {
        array[i] = atual;
        atual = atual->proximo;
    }

    // Bubble Sort para ordenar o array
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j]->ano > array[j + 1]->ano) {
                Titulo *temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Exibir os titulos
    printf("Titulos ordenados por ano de lancamento:\n");
    for (int i = 0; i < count; i++) {
        printf("Nome: %s, Ano: %d, Categoria: %s\n", array[i]->nome, array[i]->ano, array[i]->categoria);
    }

    free(array);
}

// Busca títulos por categoria
void buscarPorCategoria(Lista *lista, const char *categoria) {
    if (lista->inicio == NULL) {
        printf("Nenhum titulo no catalogo.\n");
        return;
    }

    int encontrado = 0;
    Titulo *atual = lista->inicio;
    printf("Titulos na categoria '%s':\n", categoria);
    while (atual != NULL) {
        if (strcmp(atual->categoria, categoria) == 0) {
            printf("Nome: %s, Ano: %d\n", atual->nome, atual->ano);
            encontrado = 1;
        }
        atual = atual->proximo;
    }

    if (!encontrado) {
        printf("Nenhum titulo encontrado na categoria '%s'.\n", categoria);
    }
}

int main() {
    Lista catalogo;
    inicializarLista(&catalogo);

    adicionarTitulo(&catalogo, "Breaking Bad", 2008, "Drama");
    adicionarTitulo(&catalogo, "Stranger Things", 2016, "Ficcao Cientifica");
    adicionarTitulo(&catalogo, "The Office", 2005, "Comedia");
    adicionarTitulo(&catalogo, "Game of Thrones", 2011, "Fantasia");

    printf("\n   Catalogo de Filmes e Series    \n");
    listarTitulosOrdenados(&catalogo);

    printf("\n--- Buscar por Categoria: Drama    \n");
    buscarPorCategoria(&catalogo, "Drama");

    printf("\n    Buscar por Categoria: Comedia    \n");
    buscarPorCategoria(&catalogo, "Comedia");

    printf("\n    Buscar por Categoria: Terror    \n");
    buscarPorCategoria(&catalogo, "Terror");

    return 0;
}