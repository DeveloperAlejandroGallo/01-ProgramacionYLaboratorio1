#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int dia;
int mes;
int anio;
} eFecha;

typedef struct
{
int legajo;
char* nombre;
char* apellido;
char sexo;
eFecha fechaIngreso;
} eEmpleado;

int main()
{

    eEmpleado* emple;
    emple = malloc(sizeof(eEmpleado));

    emple->fechaIngreso.anio = 2017;

    printf("%d",emple->fechaIngreso.anio);

    system("pause");
    return 0;
}
