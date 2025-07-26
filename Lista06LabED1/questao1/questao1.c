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

char topo(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[p->topo];
    }
    return '\0'; 
}


int verificarBalanceamento(const char *sequencia) {
    Pilha p;
    inicializarPilha(&p);

    for (int i = 0; i < strlen(sequencia); i++) {
        char atual = sequencia[i];

// pilha dos  símbolos de abertura
        if (atual == '(' || atual == '{' || atual == '[') {
            empilhar(&p, atual);
        } 
// pilha dos  símbolos de fechamento
        else if (atual == ')' || atual == '}' || atual == ']') {
            if (pilhaVazia(&p)) {
                return 0;
            }

            char topoPilha = desempilhar(&p);

// Verifica se o símbolo de fechamento corresponde ao de abertura
            if ((atual == ')' && topoPilha != '(') ||
                (atual == '}' && topoPilha != '{') ||
                (atual == ']' && topoPilha != '[')) {
                return 0; // Não balanceado
            }
        }
    }

// Se a pilha estiver vazia no final, está balanceado
    return pilhaVazia(&p);
}

int main() {
    char sequencia[100];

    printf("Digite a sequencia de parenteses: ");
    scanf("%s", sequencia);

    if (verificarBalanceamento(sequencia)) {
        printf("Entrada Balanceada\n");
    } else {
        printf("Entrada nao Balanceada\n");
    }

    return 0;
}