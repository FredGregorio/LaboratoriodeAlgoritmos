#include <stdio.h>

struct jogador {

char nome [20];
int salario;
char posição [20];

};


int main () {


struct jogador pele = {"Pele", 30, "Atacante"};
struct jogador* ptr = &pele;

printf ("Nome: %s\n", ptr -> nome);
printf ("salario: %d\n", ptr -> salario);
printf ("Posição: %s\n", ptr -> posição);

return 0;


}