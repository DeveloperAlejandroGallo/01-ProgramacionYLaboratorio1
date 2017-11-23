#include <stdio.h>
#include <stdlib.h>
/*Diseñar el programa necesario para que habiéndose leído el valor de 2 variables NUM1 y NUM2 se
intercambien los valores de las variables, es decir que el valor que tenía NUM1 ahora lo contenga NUM2 y
viceversa*/

int main()
{
   int num1, num2, aux;

   printf("Ingrese el 1er Nro: ");
   scanf("%d",&num1);

   printf("Ingrese el 2do Nro: ");
   scanf("%d",&num2);

   aux = num1;
   num1=num2;
   num2=aux;

   printf("Los nros intercambiados son %d y %d", num1, num2);
}
