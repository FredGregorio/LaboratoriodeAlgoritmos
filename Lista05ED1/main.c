#include <stdio.h>
#include "algoritmosordenacao.h"



int main (){

   int tipoteste;

   printf("Como voce quer testar: \n");
   printf("1 - ARRAY 1.000 ELEMENTOS \n");
   printf("2 - ARRAY 100.000 ELEMENTOS \n");
   printf("3 - ARRAY 1.000.000 ELEMENTOS \n");
   printf("4 - ARRAY de CARACTERES \n");
   printf("Opcao: ");
   scanf ("%d", &tipoteste);

   switch (tipoteste) {

      case 1:

        printf("Teste Realizado com ARRAY 1.000 ELEMENTOS \n");
      
      break;
      
      case 2:

         printf("Teste Realizado com ARRAY 100.000 ELEMENTOS \n");
      
      break;

      case 3:
      
      printf("Teste Realizado com ARRAY de 1.000.000 ELEMENTOS \n");

      break;

      case 4:

      printf("Teste Realizado com ARRAY de CARACTERES \n");

      
      break;
   


   }






   return 0;

}