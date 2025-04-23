#include <stdio.h>
using namespace std;

struct jogador {

char nome [20];
float salario;
unsigned gold;


};


int main () {


struct jogador pele = {"Pele, 300"};
struct jogador *ptr = &pele;

printf ("Nome: %\n", ptr -> nome);
printf ("Idade: %\n", ptr -> salario);
return 0;

}