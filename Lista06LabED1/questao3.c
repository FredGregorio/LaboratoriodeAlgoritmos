#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




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


int precedencia(char operador) {


    if (operador == '+' || operador == '-') {

        return 1;

    } else if (operador == '*' || operador == '/') {

        return 2;

    } else if (operador == '^') {

        return 3;

    }
    return 0; 

     }


int ehOperador(char c) {


    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';


}


void infixaParaPosfixa(const char *expressao, char *resultado) {


    Pilha pilha;

    inicializarPilha(&pilha);

    int j = 0; 

    for (int i = 0; i < strlen(expressao); i++) {


        char atual = expressao[i];


    
        if (atual == ' ') {

            continue;
        }


        if (isalnum(atual)) {


            resultado[j++] = atual;


        }
        
        else if (atual == '(') {
            empilhar(&pilha, atual);
        }

  
        else if (atual == ')') {



            while (!pilhaVazia(&pilha) && topo(&pilha) != '(') {

                resultado[j++] = desempilhar(&pilha);

            }
            desempilhar(&pilha); 
        }

        else if (ehOperador(atual)) {


            while (!pilhaVazia(&pilha) && precedencia(topo(&pilha)) >= precedencia(atual)) {


                resultado[j++] = desempilhar(&pilha);


            }
            
            empilhar(&pilha, atual);
        }
    }

    while (!pilhaVazia(&pilha)) {
        resultado[j++] = desempilhar(&pilha);
    }

    resultado[j] = '\0'; 

}

int main(){


    char expressao[100];

    char resultado[100];
    

    printf("Digite a expressao infixa: ");
    fgets(expressao, 100, stdin);

    expressao[strcspn(expressao, "\n")] = 0; 

    infixaParaPosfixa(expressao, resultado);


    printf("Expressao pos-fixa: %s\n", resultado);

    return 0;






}