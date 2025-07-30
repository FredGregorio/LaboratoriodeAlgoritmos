#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {


    char itens[100];
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

void empilhar(Pilha *p, char elemento) {


    if (!pilhaCheia(p)) {


        p->itens[++p->topo] = elemento;


    }
}

char desempilhar(Pilha *p) {


    if (!pilhaVazia(p)) {


        return p->itens[p->topo--];
    }


    return '\0';


}


void inverterString(const char *entrada, char *saida) {


    Pilha p;


    inicializarPilha(&p);

 
    for (int i = 0; i < strlen(entrada); i++) {


        empilhar(&p, entrada[i]);


    }


    int i = 0;

    while (!pilhaVazia(&p)) {

        saida[i++] = desempilhar(&p);

    }
    saida[i] = '\0'; 


}

int main() {


    char entrada[100];
    char saida[100];


    printf("Digite uma palavra ou frase: ");
    fgets(entrada, 100, stdin);
    entrada[strcspn(entrada, "\n")] = 0; 

    inverterString(entrada, saida);

    
    printf("Texto invertido: %s\n", saida);

    return 0;
}