/*Diseñar en un programa que permita ingresar 10 números, ninguno de ellos igual a cero. Se pide sumar los
positivos, obtener el producto de los negativos y luego mostrar ambos resultados*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int
   nro,
   suma=0,
   prod=1,
   i;

   for (i=0;i<10;i++)
   {
      printf("Ingrese un Nro(%d): ",i+1);
      scanf("%d",&nro);

      while(nro==0)
      {
         printf("Ingrese un Nro(%d): ",i+1);
         scanf("%d",&nro);

      }
       if(nro >0)
         suma += nro;

       if(nro<0)
         prod *= nro;
   }
   printf("La suma de los positivos es: %d\nY el producto de los negativos es: %d\n\n", suma, prod);

   return 0;
}
