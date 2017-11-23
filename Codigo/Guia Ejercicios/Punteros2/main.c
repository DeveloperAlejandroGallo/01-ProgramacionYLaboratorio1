#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int legajo2;
    char nombre2[20];
    float sueldo2;
    eFecha fechaIngreso;
}eEmpleado;


void cargarEmpleado(eEmpleado* x);



int main()
{
    eEmpleado unEmpleado;

    cargarEmpleado(&unEmpleado);
    printf("\n\nCON PUNTERO PURO &(*ESTRUCTURA):\n");
    printf("Legajo: %d\n", unEmpleado.legajo);
    printf("Nombre: %s\n", unEmpleado.nombre);
    printf("Sueldo: %.2f\n", unEmpleado.sueldo);
    printf("Fecha Ingreso: %d/%d/%d\n\n\n", unEmpleado.fechaIngreso.dia,unEmpleado.fechaIngreso.mes, unEmpleado.fechaIngreso.anio);

    printf("CON OPERADOR FLECHA:\n");
    printf("Legajo2: %d\n", unEmpleado.legajo2);
    printf("Nombre2: %s\n", unEmpleado.nombre2);
    printf("Sueldo2: %.2f\n", unEmpleado.sueldo2);
    printf("Fecha Ingreso2: %d/%d/%d\n\n\n", unEmpleado.fechaIngreso.dia,unEmpleado.fechaIngreso.mes, unEmpleado.fechaIngreso.anio);
}


void cargarEmpleado(eEmpleado* x)
{
    printf("Ingrese Legajo:");
    scanf("%d", &(*x).legajo);
    printf("Ingrese Nombre:");
    fflush(stdin);
    gets((*x).nombre);
    printf("Ingrese Sueldo:");
    scanf("%f", &(*x).sueldo);
    printf("Ingrese dia de ingreso:");
    scanf("%d", &(*x).fechaIngreso.dia);
    printf("Ingrese mes de ingreso:");
    scanf("%d", &(*x).fechaIngreso.mes);
    printf("Ingrese anio de ingreso:");
    scanf("%d", &(*x).fechaIngreso.anio);


    //Con operador Flecha
    printf("Ingrese Legajo2:");
    scanf("%d", &x->legajo2);
    printf("Ingrese Nombre2:");
    fflush(stdin);
    gets(x->nombre2);
    printf("Ingrese Sueldo2:");
    scanf("%f", &x->sueldo2);
    printf("Ingrese dia de ingreso2:");
    scanf("%d", &x->fechaIngreso.dia);
    printf("Ingrese mes de ingreso2:");
    scanf("%d", &x->fechaIngreso.mes);
    printf("Ingrese anio de ingreso2:");
    scanf("%d", &x->fechaIngreso.anio);

}
