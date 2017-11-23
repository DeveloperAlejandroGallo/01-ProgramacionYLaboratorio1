#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[1024] = {"Hola maldito mundo."};
    int cant, cantEscritos;
    //FILE
    FILE* archivo;
    //Recibe 2 punteros a char Path (si esta en el mismo directorio solo el nombre) y tipo de apertura


    archivo = fopen("Prueba2.txt", "w");
    if(archivo == NULL)
    {
        printf("El archivo no pudo ser creado");
        exit(1);
    }
    printf("Archivo Creado");
    /*
    fwrite - 4 parametros
    1 - origen de donde quiero leer
    2 - tamaño de lo que voy a guardar
    3 - cantidad de lo que voy a guardar
    4 - puntero a file
    Devuelve la cantidad de caracteres escritos
    */

    cant = strlen(cadena);

    cantEscritos = fwrite(cadena,sizeof(char),cant,archivo);
    if(cantEscritos < cant)
    {
        printf("Error al escribir en el archivo");
    }
    else
        printf("See escribieron %d caracteres",cant);

    fclose(archivo);

    return 0;
}
