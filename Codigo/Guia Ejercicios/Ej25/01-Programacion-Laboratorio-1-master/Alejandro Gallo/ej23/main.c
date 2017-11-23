#include <stdio.h>
#include <stdlib.h>
//De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor
int main()
{
   int nro1, nro2, nro3, mayor;

   printf("Ingrese el 1er nro: ");
   scanf("%d",&nro1);
   system("cls");

   printf("Ingrese el 2do nro: ");
   scanf("%d",&nro2);
   system("cls");

   printf("Ingrese el 3er nro: ");
   scanf("%d",&nro3);
   system("cls");

   if(nro1>nro2)
   {
      if(nro1>=nro3)
         mayor=nro1;
      else
         mayor=nro3;
   }
   else if(nro2>=nro3)
        mayor=nro2;
   else
        mayor=nro3;

   printf("El mayor nro ingresado fue: %d",mayor);

   return 0;
}
