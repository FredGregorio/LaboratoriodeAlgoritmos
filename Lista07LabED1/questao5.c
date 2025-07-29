#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma música
typedef struct Musica {
    char titulo[100];
    char artista[100];
    int duracao; 
    struct Musica *proximo;
    struct Musica *anterior;
} Musica;


typedef struct {
    Musica *inicio;
} Playlist;


void inicializarPlaylist(Playlist *playlist) {
    playlist->inicio = NULL;
}


void adicionarMusica(Playlist *playlist, const char *titulo, const char *artista, int duracao) {
    Musica *nova = (Musica *)malloc(sizeof(Musica));
    if (nova == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    strcpy(nova->titulo, titulo);
    strcpy(nova->artista, artista);
    nova->duracao = duracao;

    if (playlist->inicio == NULL) {
    
        nova->proximo = nova;
        nova->anterior = nova;
        playlist->inicio = nova;
    } else {
 
        Musica *ultima = playlist->inicio->anterior;
        ultima->proximo = nova;
        nova->anterior = ultima;
        nova->proximo = playlist->inicio;
        playlist->inicio->anterior = nova;
    }
}


void removerMusica(Playlist *playlist, const char *titulo) {
    if (playlist->inicio == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    Musica *atual = playlist->inicio;

    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (atual->proximo == atual) {
             
                playlist->inicio = NULL;
            } else {
            
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == playlist->inicio) {
                    playlist->inicio = atual->proximo;
                }
            }
            free(atual);
            printf("Musica '%s' removida da playlist.\n", titulo);
            return;
        }
        atual = atual->proximo;
    } while (atual != playlist->inicio);

    printf("Musica '%s' nao encontrada na playlist.\n", titulo);
}

void exibirPlaylist(Playlist *playlist) {
    if (playlist->inicio == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    Musica *atual = playlist->inicio;
    printf("Playlist:\n");
    do {
        printf("Titulo: %s, Artista: %s, Duracao: %d segundos\n", atual->titulo, atual->artista, atual->duracao);
        atual = atual->proximo;
    } while (atual != playlist->inicio);
}


void moverParaInicio(Playlist *playlist, const char *titulo) {
    if (playlist->inicio == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    Musica *atual = playlist->inicio;

    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (atual == playlist->inicio) {
                printf("Musica '%s' ja esta no inicio.\n", titulo);
                return;
            }

           
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;

         
            Musica *ultima = playlist->inicio->anterior;
            atual->proximo = playlist->inicio;
            atual->anterior = ultima;
            ultima->proximo = atual;
            playlist->inicio->anterior = atual;
            playlist->inicio = atual;

            printf("Musica '%s' movida para o inicio da playlist.\n", titulo);
            return;
        }
        atual = atual->proximo;
    } while (atual != playlist->inicio);

    printf("Musica '%s' nao encontrada na playlist.\n", titulo);
}


int main() {
    Playlist playlist;
    inicializarPlaylist(&playlist);

    adicionarMusica(&playlist, "Bohemian Rhapsody", "Queen", 354);
    adicionarMusica(&playlist, "Imagine", "John Lennon", 183);
    adicionarMusica(&playlist, "Smells Like Teen Spirit", "Nirvana", 278);
    adicionarMusica(&playlist, "Hotel California", "Eagles", 391);

    printf("\nPlaylist Atual\n");
    exibirPlaylist(&playlist);

    printf("\nRemovendo 'Imagine'\n");
    removerMusica(&playlist, "Imagine");
    exibirPlaylist(&playlist);

    printf("\nMovendo 'Hotel California' para o inicio\n");
    moverParaInicio(&playlist, "Hotel California");
    exibirPlaylist(&playlist);

    printf("\nMovendo 'Bohemian Rhapsody' para o inicio\n");
    moverParaInicio(&playlist, "Bohemian Rhapsody");
    exibirPlaylist(&playlist);

    return 0;
}