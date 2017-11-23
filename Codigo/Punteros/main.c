#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre;
    int nota;
}alumno;

int main()
{

    int* a[]={1,2,3,4,5,6};
    int* b;
    int c=15,i;
    int matriz[3][2]={{0,1},{2,3},{4,5},{6,7}};
    char string[] = {"Buen dia"};
    char* cadena;
    alumno* pAlumno;

    b=matriz;

    cadena=string;
    printf("Memoria 2do elem matriz: %d\n",*(b+3));

    printf("Contenido 2do elem matriz: %d\n",matriz[1][1]);

    i=0;
    while (string[i] != '\0')
    {
        printf("%c",string[i]);
        i++;
    }
    printf("\n\n");
    i=0;
    while ( *cadena != '\0')
    {
        printf("%c",*cadena);
        cadena++;
    }
    printf("\n\n");
    return 0;
}
