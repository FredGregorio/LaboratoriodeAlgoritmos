#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



typedef struct {


    int itens[100]; 
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

void empilhar(Pilha *p, int elemento) {


    if (!pilhaCheia(p)) {


        p->itens[++p->topo] = elemento;

    }

}

int desempilhar(Pilha *p) {


    if (!pilhaVazia(p)) {

        return p->itens[p->topo--];


    }
    return 0; 
}


int avaliarPosfixa(const char *expressao) {


    Pilha pilha;

    inicializarPilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {


        char atual = expressao[i];

      
        if (atual == ' ') {
            continue;
        }

      
        if (isdigit(atual)) {


            empilhar(&pilha, atual - '0'); 


        }

    
        else {


            int b = desempilhar(&pilha);
            int a = desempilhar(&pilha);

            switch (atual) {


                case '+':
                    empilhar(&pilha, a + b);
                    break;
                case '-':
                    empilhar(&pilha, a - b);
                    break;
                case '*':
                    empilhar(&pilha, a * b);
                    break;
                case '/':
                    empilhar(&pilha, a / b);
                    break;


            }
        }
    }

  


    return desempilhar(&pilha);
}

int main() {


    char expressao[100]; 



    printf("Digite a expressao pos-fixa: ");

    fgets(expressao, 100, stdin);


    expressao[strcspn(expressao, "\n")] = 0; 



    int resultado = avaliarPosfixa(expressao);


    printf("Resultado: %d\n", resultado);


    return 0;


    
}