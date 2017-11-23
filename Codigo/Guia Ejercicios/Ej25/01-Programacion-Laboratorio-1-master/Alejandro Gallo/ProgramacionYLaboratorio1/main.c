#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Ej01.h"

float pi = 3.1415926535897932384626433832795;

int main(void)
{
    int ejercicio;
    printf("Seleccione un Nro de Ejercicio:\n");
    scanf("%d",&ejercicio);
   system("cls");
    switch(ejercicio)
    {
      case 1:
         Ej01();
         break;
      case 2:
         Ej02();
         break;
      case 3:
         Ej03();
         break;
      case 4:
         Ej04();
         break;
      case 5:
         Ej05();
         break;
      case 6:
         Ej06();
         break;
      case 7:
         Ej07();
         break;
      case 8:
         Ej08();
         break;
      case 9:
         Ej09();
         break;
      case 10: case 11: case 12: case 13:
         Ej10_11_12_13();
         break;
      case 14:
         Ej14();
         break;
      case 15:
         Ej15();
         break;

    }
   return 0;
}

void Ej01()
{

    int suma=0;
    float promedio=0;

    int nro;
    int i;
    for(i=0;i<2;i++)
    {
        printf("Ingrese el %d numero\n",i+1);
        scanf("%d",&nro);
        suma+=nro;
    }
    promedio = (float)suma/i;
    printf("El promedio de los nros es: %.2f",promedio);

}

void Ej02()
{
    int i;
    float nro=0;
    for(i=0;i<5;i++)
    {
        printf("Ingrese el %d Nro:",i);
        scanf("%f",&nro);
        nro += nro;
    }
    printf("La suma de los nros es: %f",nro);

}

void Ej03()
{
    int nro1, nro2;

    printf("Hello world!\n");
    system("cls");

    printf("Ingrese el 1er Nro: ");
    scanf("%d",&nro1);

    while(nro1 == 0)
    {
        printf("Ingrese el 1er Nro: ");
        scanf("%d",&nro1);
    }

    printf("Ingrese el 2do Nro: ");
    scanf("%d",&nro2);

    while(nro2 == 0)
    {
        printf("Ingrese el 2do Nro: ");
        scanf("%d",&nro1);
    }


    printf("El producto de los Nros es: %d \nY el cuadrado del primer nro es: %d",nro1*nro2,nro1*nro1);

}

/*Escribir un programa que realice las siguientes acciones:
Limpie la pantalla
Declare 2 variables y les asigne sendos valores
Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de
ser mayor que cero o "Resultado negativo" si es menor que cero*/
void Ej04()
{
    int nro1,
        nro2;

    system("cls");
    printf("Ingrese Nro1: ");
    scanf("%d",&nro1);

    printf("Ingrese Nro2: ");
    scanf("%d",&nro2);

    if (nro1 - nro2 >= 0)
      printf("Resultado Positivo");
    else
      printf("Resultado Negativo");

}


void Ej05()
{

  int nro;
  printf("Ingrese un nro:");
  scanf("%d",&nro);

  if (nro<0)
  {
   system("cls");
   printf("ERROR - El nro debe ser mayor a cero\n");
  }
  else
  {
     printf("El cuadrado del nro es: %d\n", nro * nro);
  }


}

/*
De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero
*/
void Ej06()
{
   int  menoresACero=0,
         nro,
         i;

   for(i=0;i<10;i++)
   {
      printf("Ingrese un nro(%d): ",i+1);
      scanf("%d",&nro);
      system("cls");

      if(nro<0)
         menoresACero++;
   }

   printf("Se ingresaron:\nNegativos: %d\nPositivos: %d\n", menoresACero, i-menoresACero);

}


void Ej07()
{//Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado.
   float radio;

   printf("Ingrese el Radio del Circulo: ");
   scanf("%f",&radio);

   printf("La longitud de la circunferencias es: %f\nY su area es: %f\n",(2*pi*radio),(pi*pow(radio,2)));
}

void Ej08()
{//Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y muestre el resultado.

   float base, altura;

   printf("Ingrese Base: ");
   scanf("%f",&base);

   printf("\nIngrese Altura: ");
   scanf("%f",&altura);

   printf("\nLa sup de triangule es %f\n", (base * altura)/2);



}
void Ej09()
{//Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas a se ingresaron, cuantas e, i, o, u
   int
   ca=0,
   ce=0,
   ci=0,
   co=0,
   cu=0,
   i;
   char caracter;

   for(i=0;i<20;i++)
   {
      system("cls");
      printf("Ingrese un Caracter(%d): ",i);
      scanf("%c",&caracter);

      switch(toupper(caracter))
      {
         case 'A': ca++; break;
         case 'E': ce++; break;
         case 'I' : ci++;  break;
         case 'O': co++; break;
         case 'U': cu++; break;
      }
   }

   printf("\nSe ingresaron:\n");
   printf("a: %d\ne: %d\ni: %d\no: %d\nu: %d\n",ca,ce,ci,co,cu);

}
/*
10. Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares hay
11. Hacer el programa que imprima los números pares entre el 1 y el 100
12. Hacer el programa que imprima los números del 1 al 100
13. Hacer el programa que imprima los números del 100 al 0 en orden decreciente
*/
void Ej10_11_12_13()
{

   int
   impares=0,
   pares=0,
   i;

   printf("Pares:\n\n");
   for(i=1;i<=100;i++)
   {
      if(i % 2 == 0)
      {
         pares++;
         printf("%d ", i);
      }
   }
   printf("\n\nImpares:\n\n");
   for(i=1;i<=100;i++)
   {
      if(i % 2 != 0)
      {
         impares++;
         printf("%d ", i);
      }
   }
    printf("\n\nDe 100 a 0:\n\n");
   for(i=100;i>=0;i--)
   {
     printf("%d ", i);
   }
   printf("\n\nNros entre 1 y 100\n* %d Pares\n* %d impares",pares,impares);
}


void Ej14()
{
   int serie=3,
   suma=0;

   printf("La serie de 3 es:\n");

   while(serie<100)
   {
      printf("%d ",serie);
      suma += serie;
      serie +=3;
   }
   printf("\n\nLa suma total da: %d", suma);
}

void Ej15()
{
   int serie=6;

   printf("Los multiplos de 6 son:\n");

   while(serie<100)
   {
      printf("%d ",serie);
      serie +=6;
   }
}






