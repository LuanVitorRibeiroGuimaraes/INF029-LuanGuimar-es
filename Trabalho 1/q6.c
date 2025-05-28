#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q6(int numerobase, int numerobusca)
{
   int qtdOcorrencias;

   int calc = numerobase; 
   int calcBusca = numerobusca;
   int sizeBusca = 1;
   int baseDecimal = 1;
   int number = 1;

   do
   {
      calcBusca /= 10;
      if (calcBusca > 0) sizeBusca++;
   } while (calcBusca != 0);

   for (int i = 0; i < sizeBusca; i++)
   {
      baseDecimal *= 10;
   }

   qtdOcorrencias = 0;

   // printf("\nprev calc = %d\n", calc);

   for (int i = 0; calc != 0; i++)
   {
      number = (calc % baseDecimal);
      calc /= baseDecimal;
      // printf("\nnumber = %d\n", number);
      // printf("\ncalc = %d\n", calc);
      if (number == numerobusca) qtdOcorrencias++;
   }

   // printf("\nocorrencias: %d\n", qtdOcorrencias);

   return qtdOcorrencias;
}

int main()
{
   printf("%d\n",q6(34567368, 3) == 2);
   printf("%d\n",q6(34567368, 4576) == 0);
   printf("%d\n",q6(3539343, 3) == 4);
   printf("%d\n",q6(3539343, 39) == 1);
   printf("%d\n",q6(5444, 44) == 1);//erro
   printf("%d\n",q6(54444, 44) == 2);//erro
   printf("%d\n",q6(1234562354, 23) == 2);
   printf("%d\n",q6(1234, 13) == 0);
   printf("%d\n",q6(544444, 4) == 5);
   printf("%d\n",q6(1234562354, 32) == 0);

}