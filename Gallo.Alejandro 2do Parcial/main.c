#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Tarea.h"

int main()
{

    char seguir='s';
    int opcion;

    ArrayList* tareas = al_newArrayList();
    ArrayList* tareasAltas = al_newArrayList();
    ArrayList* tareasBajas = al_newArrayList();

    Tarea* auxTarea;

    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
        /*Cargar Lista de Tareas*/
            imprimirTitulo("CARGAR LISTA DE TAREAS");
            cargarTareasPendientes(tareas);
            infoMessage("TAREAS CARGADAS...");
            break;
        case 2:
        /*Particionar por Prioridad*/
            imprimirTitulo("PARTICIONAR POR PRIORIDAD");
            particionarPorPrioridad(tareas,tareasAltas,tareasBajas);
            infoMessage("TAREAS PARTICIONADAS...");
            break;
        case 3:
        /*ORDENAR*/
            imprimirTitulo("ORDENAR TAREAS");
            ordenarListasDeTareas(tareasAltas,tareasBajas);
            printf("\nTAREAS ALTAS\n");
            mostrarTareas(tareasAltas);
            printf("\n\nTAREAS BAJAS\n");
            mostrarTareas(tareasBajas);
            break;

        case 4:
        /*RESOLVER TAREAS*/
            imprimirTitulo("RESOLVER TAREAS");
            if(tareasAltas->isEmpty(tareasAltas)== 1)
            {
                tareasBajas->sort(tareasBajas, compareTiempoTarea,1);
                auxTarea = tareasBajas->pop(tareasBajas,0);

            }
            else
            {
                tareasAltas->sort(tareasAltas, compareTiempoTarea,1);
                auxTarea = tareasAltas->pop(tareasAltas,0);
            }
            mostrarProximaTarea(auxTarea);
            break;

        case 5:
        /*SALIR*/
            seguir='n';
            break;

        }
        printf("\n\n");
        if(opcion!=5)
            system("pause"); //Para q no pida 2 veces la tecla al salir
    }



    return 0;
}
