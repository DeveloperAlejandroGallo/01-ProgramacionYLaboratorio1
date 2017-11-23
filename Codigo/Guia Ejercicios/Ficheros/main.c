#include <stdio.h>
#include <stdlib.h>

int main()
{
    //FILE
    FILE* archivo;
    //Recibe 2 punteros a char Path (si esta en el mismo directorio solo el nombre) y tipo de apertura

    archivo = fopen("Prueba.txt", "w");
    if(archivo == NULL)
    {
        printf("El archivo no pudo ser creado");
        exit(1);
    }
    printf("Archivo Creado");

    fprintf(archivo,"Primera linea en mi archivo");

    fclose(archivo);

    return 0;
}
