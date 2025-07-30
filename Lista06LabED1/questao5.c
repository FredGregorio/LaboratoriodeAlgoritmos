#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {


    char itens[100][100]; 
    int topo;


} Pilha;


void inicializarPilha(Pilha *p) {


    p->topo = -1;


}

int pilhaVazia(Pilha *p) {


    return p->topo == -1;


}

int pilhaCheia(Pilha *p) {


    return p->topo == 100 - 1;


}

void empilhar(Pilha *p, const char *comando) {


    if (!pilhaCheia(p)) {


        strcpy(p->itens[++p->topo], comando);


    }


}

char *desempilhar(Pilha *p) {


    if (!pilhaVazia(p)) {


        return p->itens[p->topo--];


    }


    return NULL; 


}

char *topo(Pilha *p) {


    if (!pilhaVazia(p)) {


        return p->itens[p->topo];


    }
    return NULL;

}


int main() {


    Pilha pilhaPrincipal, pilhaDesfazer;


    inicializarPilha(&pilhaPrincipal);


    inicializarPilha(&pilhaDesfazer);



    char comando[100];


    while (1) {

        printf("\nDigite um comando (ou 'desfazer', 'refazer', 'sair'): ");

        fgets(comando, 100, stdin);


        comando[strcspn(comando, "\n")] = 0; 

        if (strcmp(comando, "sair") == 0) {


            break;


        } else if (strcmp(comando, "desfazer") == 0) {


            if (pilhaVazia(&pilhaPrincipal)) {


                printf("Nada para desfazer.\n");


            } else {


                char *ultimoComando = desempilhar(&pilhaPrincipal);

                empilhar(&pilhaDesfazer, ultimoComando);

                printf("Acao desfeita: \"%s\"\n", ultimoComando);
                


            }

        } else if (strcmp(comando, "refazer") == 0) {


            if (pilhaVazia(&pilhaDesfazer)) {


                printf("Nada para refazer.\n");


            } else {


                char *ultimoDesfeito = desempilhar(&pilhaDesfazer);

                empilhar(&pilhaPrincipal, ultimoDesfeito);

                printf("Acao refeita: \"%s\"\n", ultimoDesfeito);


            }


        } else {


            empilhar(&pilhaPrincipal, comando);
            inicializarPilha(&pilhaDesfazer);


            printf("Comando %s armazenado.\n", comando);


        }
    }

    printf("\nComandos armazenados:\n");

    while (!pilhaVazia(&pilhaPrincipal)) {


        printf("- %s\n", desempilhar(&pilhaPrincipal));


    }

    return 0;



}