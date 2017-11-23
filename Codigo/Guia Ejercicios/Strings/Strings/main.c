#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#include "GalloAlejandro.h"

int main()
{
    char cadena[30];
    char caracter;

    fflush(stdin);
    puts("Ingrese su nombre:");
    gets(cadena);
    puts("Ingrese el caracter a buscar: ");
    caracter = getche();

    printf("\n\n%s\n\n", cadena);
    printf("Cantidad de caracteres: %d\n\n", length(cadena));

    printf("Cantidad de apariciones de %c: %d\n\n", caracter, cuentaCaracter(cadena,caracter));

    printf("La cadena en mayuscula: %s \n\n",strupr(cadena));

    printf("La cadena en min: %s \n\n",strlwr(cadena));

    printf("Cuando la diferencia entre juan y juon da: %d\n", strcmp("juan", "juon"));

    printf("Cuando la diferencia entre juon y juan da: %d\n", strcmp("juon", "juan"));

    printf("Cuando la diferencia entre juan y juan da: %d\n", strcmp("juan", "juan"));

    char auxCadena [30];
    char cadenaFinal [5000];
    strcpy(auxCadena, cadena);

    printf("AuxCadena: %s\n", auxCadena);

    printf("StrCat: %s", strcat(strcat(cadena," "),auxCadena) );

    return 0;
}
