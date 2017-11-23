#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[50];
    char x;
    int cant, cantEscritos;
    //FILE
    FILE* archivo;
    //Recibe 2 punteros a char Path (si esta en el mismo directorio solo el nombre) y tipo de apertura


    archivo = fopen("Prueba3.txt", "r");
    if(archivo == NULL)
    {
        printf("El archivo no pudo ser creado");
        exit(1);
    }
/*
    while(x!=EOF)
    {
        x = fgetc(archivo);
        printf("%c",x);
    }

    printf("\n*************************************************\n");
*/
    while(!feof(archivo))
    {
        fgets(cadena,50,archivo); //Leo de a 50 caracteres
        printf("%s",cadena);
    }

    fclose(archivo);

    return 0;
}
