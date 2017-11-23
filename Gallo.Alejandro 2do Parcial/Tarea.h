#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED


typedef struct
{
    char nombre[10];
    int prioridad; // 1-Alta / 0-baja
    int horas;
}Tarea;

/** \brief Carga desde un archivo csv las tareas del sistema
 *
 * \param tareas ArrayList* Lista de tareas que se cargara con el archivo leido.
 * \return void
 *
 */
void cargarTareasPendientes(ArrayList* tarea);

/** \brief Constructor de una nueva tarea
 *
 * \param nombre[] char Nombre de la tarea
 * \param prioridad int prioridad de la tarea
 * \param horas int Horas de la tarea
 * \return Tarea* Puntero a una nueva tarea cargada con los parametros pasados.
 *
 */
Tarea* newTarea(char nombre[], int prioridad, int horas);

/** \brief Divide la lista de tareas "tareas" por prioridad en 2 listas
 *
 * \param tareas ArrayList* lista que contiene todas las tareas.
 * \param tareaAlta ArrayList* lista con las tareas Altas
 * \param tareaBaja ArrayList* lista con las tareas Bajas
 * \return void
 *
 */
void particionarPorPrioridad(ArrayList* tareas,ArrayList* tareaAlta,ArrayList* tareaBaja);

/** \brief Ordena las tareas por el tiempo de las mismas en forma descendente.
 *
 * \param tareaAlta ArrayList* lista de tareas altas a ordenar
 * \param tareaBaja ArrayList* lista de tareas bajas a ordenar
 * \return void
 *
 */
void ordenarListasDeTareas(ArrayList* tareaAlta,ArrayList* tareaBaja);

/** \brief Funcion que compara las horas de las tareas y devuelve 1 si la hora de la tarea A es mayor que la B o -1 si es menor
 *
 * \param pTareaA void* puntero a una tarea
 * \param pTareaB void* puntero a una tarea
 * \return int Retorna 1 si Hs de tarea A > Hs tarea B / 0 si Hs de tarea A < Hs tarea B
 *
 */
int compareTiempoTarea(void* pTareaA,void* pTareaB);

/** \brief Muestra la tarea atendida
 *
 * \param auxTarea Tarea* puntero a una tarea atendida
 * \return void
 *
 */
void mostrarProximaTarea(Tarea* auxTarea);

/** \brief Muestra el detalle de la lista de tareas
 *
 * \param tareas ArrayList* lista de tareas a mostrar
 * \return void
 *
 */
void mostrarTareas(ArrayList* tareas);

#endif // TAREA_H_INCLUDED
