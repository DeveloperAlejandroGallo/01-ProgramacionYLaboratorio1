#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 5

typedef struct
{
    int anio;
    int mes;
    int dia;
}sFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    sFecha fNac;
} ePersona;

void mostrarPersona(ePersona);
void cargarUnaPersona();
void mostrarTodasLasPersonas(ePersona[] , int );

int main()
{
    int accion;
    int i;

    ePersona gente[] = { {1, "A",1000, 'M', {1982,7,31}},
                                            {2, "B",2000, 'F', {1985,4,2}},
                                            {3, "C",3000, 'M', {1990,8,31}},
                                            {4, "D",4000, 'F', {1995,6,20}},
                                            {5, "E",5000, 'M', {2000,7,1}}
                                        };
    printf("Accion;\n1-Mostrar Una\n2-Cargar\n3-Mostrar Todas\n");
    ePersona unaPersona = {123, "Coco",1000, 'M', {1982,07,31}};
    fflush(stdin);
    scanf("%d",&accion);

    switch(accion)
    {
    case 1:
        mostrarPersona(unaPersona);
        break;
    case 2:
        cargarUnaPersona();
      break;
    case 3:
        mostrarTodasLasPersonas(gente, MAX);
        break;
    }

    return 0;
}



void mostrarPersona(ePersona persona)
{
    printf("Legajo: %d\n",persona.legajo);
    printf("Nombre: %s\n", persona.nombre);
    printf("Sueldo %.2f\n", persona.sueldo);
    printf("Sexo: %c\n",persona.sexo);
    printf("Fecha de Nacimiento: %02d/%02d/%d\n\n",persona.fNac.dia,persona.fNac.mes,persona.fNac.anio);

}

void cargarUnaPersona()
{
    ePersona persona;
    printf("Ingrese los datos de la persona:\n\n");
    printf("Legajo: ");
    scanf("%d",&persona.legajo);
    printf("Nombre: ");
    fflush(stdin);
    gets(persona.nombre);
    printf("\nSueldo: ");
    scanf("%f",&persona.sueldo);
    fflush(stdin);
    printf("Sexo: ");
    scanf("%c",&persona.sexo);
    printf("Fecha de Nacimiento:\n");
    printf("   *Anio: ");
    scanf("%d",&persona.fNac.anio);
    printf("   *Mes: ");
    scanf("%d",&persona.fNac.mes);
    printf("   *Dia: ");
    scanf("%d",&persona.fNac.dia);

    printf("La persona cargada es:\n");
    mostrarPersona(persona);
}

void mostrarTodasLasPersonas(ePersona gente[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
        mostrarPersona(gente[i]);
}

