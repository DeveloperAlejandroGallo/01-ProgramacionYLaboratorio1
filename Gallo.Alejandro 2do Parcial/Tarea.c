#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Tarea.h"


/** \brief Carga desde un archivo csv las tareas del sistema
 *
 * \param tareas ArrayList* Lista de tareas que se cargara con el archivo leido.
 * \return void
 *
 */
void cargarTareasPendientes(ArrayList* tareas)
{
    FILE* archivoTareas;
    char sNombre[10], sPrioridad[10], sHoras[10];
    Tarea* pTarea;

    archivoTareas = fopen("tar.csv", "r");

    if(archivoTareas != NULL)
    {
        while(!feof(archivoTareas))
        {
            fscanf(archivoTareas, "%[^,],%[^,],%[^\n]\n", sNombre, sPrioridad, sHoras);
            pTarea = newTarea(sNombre,atoi(sPrioridad), atoi(sHoras));
            tareas->add(tareas,pTarea);
        }
    }
}


/** \brief Constructor de una nueva tarea
 *
 * \param nombre[] char Nombre de la tarea
 * \param prioridad int prioridad de la tarea
 * \param horas int Horas de la tarea
 * \return Tarea* Puntero a una nueva tarea cargada con los parametros pasados.
 *
 */
Tarea* newTarea(char nombre[], int prioridad, int horas)
{
    Tarea* tareaAux = NULL;
    Tarea* pTarea = malloc(sizeof(Tarea));

    if(pTarea != NULL)
    {
        strcpy(pTarea->nombre,nombre);
        pTarea->prioridad = prioridad;
        pTarea->horas = horas;
        tareaAux = pTarea;
    }

    return tareaAux;
}


/** \brief Divide la lista de tareas "tareas" por prioridad en 2 listas
 *
 * \param tareas ArrayList* lista que contiene todas las tareas.
 * \param tareaAlta ArrayList* lista con las tareas Altas
 * \param tareaBaja ArrayList* lista con las tareas Bajas
 * \return void
 *
 */
void particionarPorPrioridad(ArrayList* tareas,ArrayList* tareaAlta,ArrayList* tareaBaja)
{
    Tarea* auxTarea;
    int i;
    if(tareas != NULL)
    {
        for(i=0; i<tareas->len(tareas); i++)
        {
            auxTarea = (Tarea*)tareas->pop(tareas,i);
            if(auxTarea->prioridad == 1)
                tareaAlta->add(tareaAlta,auxTarea);
            else
                tareaBaja->add(tareaBaja,auxTarea);
        }
    }
}

/** \brief Ordena las tareas por el tiempo de las mismas en forma descendente.
 *
 * \param tareaAlta ArrayList* lista de tareas altas a ordenar
 * \param tareaBaja ArrayList* lista de tareas bajas a ordenar
 * \return void
 *
 */
void ordenarListasDeTareas(ArrayList* tareaAlta,ArrayList* tareaBaja)
{
    if(tareaAlta != NULL && tareaBaja != NULL)
    {
        tareaAlta->sort(tareaAlta,compareTiempoTarea,0);
        tareaBaja->sort(tareaBaja,compareTiempoTarea,0);
    }
}


/** \brief Funcion que compara las horas de las tareas y devuelve 1 si la hora de la tarea A es mayor que la B o -1 si es menor
 *
 * \param pTareaA void* puntero a una tarea
 * \param pTareaB void* puntero a una tarea
 * \return int Retorna 1 si Hs de tarea A > Hs tarea B / 0 si Hs de tarea A < Hs tarea B
 *
 */
int compareTiempoTarea(void* pTareaA,void* pTareaB)
{

    if(((Tarea*)pTareaA)->horas > ((Tarea*)pTareaB)->horas)
    {
        return 1;
    }
    if(((Tarea*)pTareaA)->horas < ((Tarea*)pTareaB)->horas)
    {
        return -1;
    }
    return 0;
}



/** \brief Muestra la tarea atendida
 *
 * \param auxTarea Tarea* puntero a una tarea atendida
 * \return void
 *
 */
void mostrarProximaTarea(Tarea* auxTarea)
{
    printf("TAREA ATENDIDA:\n");
    printf("TIPO DE TAREA: ");
    if(auxTarea->prioridad == 1)
        printf("ALTA\n");
    else
        printf("BAJA\n");

    printf("NOMBRE DE TAREA: %s\n", auxTarea->nombre);
    printf("HORAS: %d\n", auxTarea->horas);
}


/** \brief Muestra el detalle de la lista de tareas
 *
 * \param tareas ArrayList* lista de tareas a mostrar
 * \return void
 *
 */
void mostrarTareas(ArrayList* tareas)
{
    int i;
    Tarea* aux;

    printf("%10s|%3s\n","NOMBRE","HORAS");
    for(i=0; i<tareas->len(tareas); i++)
    {
        aux =  (Tarea*)tareas->get(tareas,i);
        printf("%10s|%3d\n",aux->nombre,aux->horas);
    }
}



