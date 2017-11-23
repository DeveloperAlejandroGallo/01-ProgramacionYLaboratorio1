#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED




typedef struct {
    int dni;
    char nombre[50];
    char apellido[50];
    int idCategoria; //FK
    int estado; //1 - Activo / 0 - Baja
}eProgramador;

typedef struct
{
    int id;
	char descripcion[50];
	int pagoXHora;
}eCategoria;

typedef struct
{
    int id;
	char nombre[50];
}eProyecto;

typedef struct
{
	int idProyecto;
	int idProgramador;
	int hsAsignadas;
	int estado; //1 - Activo / 0 - Baja
}eProyectosProgramadores; //Asignaciones



typedef struct
{
    int idProyecto;
    int cJuniors;
    int cSemiSeniors;
    int cSeniors;
    int totalProg;
}eProyectoCantCategorias;

/** \brief Inicializa lel vector de programadores con 10 programadores.
 *
 * \param programadores Vector de programadores a inicializar
 * \param cant Cantidad de Programadores
 * \return void
 *
 */
void cargar10Programadores(eProgramador programadores[], int maxCant);

/** \brief Inicializa el vector de categorias
 *
 * \param categorias[] eCategoria vector de cat vacio
 * \return void
 *
 */
void inicializarCategorias(eCategoria categorias[]);

void inicializarProyectos(eProyecto proyectos[], int cProy);

void inicializarAsiganciones(eProyectosProgramadores asignaciones[],int  cAsigna);

/**
 * \brief Obtiene el primer indice libre del array.
 *
 * \param eProgramador lista[] - Vector a buscar espacio libre.
 * \param int cantidada - Tamanio del vector
 * \return El indice del espacio libre.
 *
 */
int obtenerEspacioLibre(eProgramador lista[], int cantidad);

/**
 * \brief Obtiene el primer indice libre del array.
 *
 * \param eProgramador lista[] - Vector a buscar espacio libre.
 * \param int cantidada - Tamanio del vector
 * \return El indice del espacio libre.
 *
 */
int obtenerEspacioLibreAsignacion(eProyectosProgramadores lista[], int cantidad);


/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param eProgramador lista[] Array en el cual se buscara
 * \param int dni El DNI a ser buscado en el array.
 * \param int tam Tamanio del array
 * \return posicion El indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(eProgramador lista[], int dni, int tam);


/** \brief Guarda una programador en indice indicado
 *
 * \param programadores[] eProgramador Vector de programadores
 * \param programador eProgramador Programador a guardar
 * \param espacioLibre int Indice del espacio libre
 * \return void
 *
 */
void altaProgramador(eProgramador programadores[], eProgramador programador, int espacioLibre);

/** \brief Realiza la baja logica del registro
 *
 * \param programadores[] eProgramador Vector de programadores
 * \param pos int Indice a marcar la baja
 * \return void
 *
 */
void bajaProgramador(eProgramador programadores[], int pos);


/** \brief Imprime la cabecera de la tabla de Programadores
 *
 * \return void
 *
 */
void imprimirCabeceraTablaProgramador();

/** \brief  Imprime los datos de una programador por linea.
 *
 * \param programador eProgramador - Estructura tipo programador a leer
 * \return void
 *
 */
void mostrarProgramador(eProgramador programador,eCategoria categorias[], int cantCat);

/** \brief Obtiene la descripcion de una categoria
 *
 * \param idCategoria int id de categoria a buscarc
 * \param descCat[] char Variable donde devuelve la categoria
 * \return void
 *
 */
void getDescripcionCategoria(int idCategoria, char descCat[], eCategoria categorias[], int cantCat);

/** \brief Pide por pantalla los datos de una programador
 *
 * \param void
 * \return eProgramador PROGRAMADOR valida
 *
 */
eProgramador obtenerDatoProgramador(int DNI);


/** \brief  Iprimime la tabla de programadores activos
 *
 * \param programadores[] eProgramador lista de programadores
 * \param cantProg int cantidad max de programadores.
 * \param categorias[] eCategoria lista de categorias
 * \param cantCategorias int cantidad maxima de categorias
 * \param asignaciones[] eProyectosProgramadores lista de asignaciones
 * \param cAsigna int cantidad maxima de asignaciones.
 * \return void
 *
 */
void imprimirProgramadoresActivas(eProgramador programadores[], int cantProg, eCategoria categorias[], int cantCategorias,eProyectosProgramadores asignaciones[], int cAsigna);

 /** \brief Ordena Programadores por DNI
  *
  * \param programadores[] eProgramador lista de programadores
  * \param tamanio int  cantidad maxima de programdores.
  * \return void
  *
  */
 void bubbleSortInt(eProgramador programadores[], int tamanio );


 /** \brief Pide los datos necesarios para una asignacion a proyecto
  *
  * \param dni int Id del Programador
  * \return eProyectosProgramadores Devuelve la estructura asignacion cargada
  *
  */
 eProyectosProgramadores obtenerDatosAsignacion(int dni);


/** \brief Imprime la cabecera de la tabla de Asignaciones (ProyectosProgramadores)
 *
 * \return void
 *
 */
void imprimirCabeceraTablaAsignacion();

/** \brief Muestras toda las asignaciones de un programador
 *
 * \param asignaciones[] eProyectosProgramadores lista de asignaciones
 * \param cantAsigna int catidad maxima de asignaciones
 * \param idProg int id del Programador.
 * \param categorias[] eCategoria lista de categorias
 * \param programadores[] eProgramador lista de programadores
 * \param cantProg int cantidad maxima de programadores
 * \return void
 *
 */
void mostrarAsignacionesProgramador(eProyectosProgramadores asignaciones[], int cantAsigna, int idProg, eCategoria categorias[], int cantCat, eProgramador programadores[],int cantProg, eProyecto proyectos[], int cantPry);



/** \brief Muestra una asignacion
 *
 * \param asignacion eProyectosProgramadores lista de programdores
 * \param programador eProgramador programador de la asignacion
 * \param categorias[] eCategoria lista de categorias
 * \param cantCat int cantidad maxima de categorias
 * \param proyectos[] eProyecto lista de proyectos
 * \param cantPry int cantidad maxima de proyectos.
 * \return void
 *
 */
void mostrarAsignacion(eProyectosProgramadores asignacion,eProgramador programador, eCategoria categorias[], int cantCat, eProyecto proyectos[], int cantPry);

 /** \brief Obtiene la descripcion de un proyecto
  *
  * \param proyectos[] eProyecto lista de proyectos
  * \param idProyecto int id de proyecto buscado
  * \param descripcion[] char variable donde devuelvo la descripcion
  * \param cantPry int cantidad max de proyectos
  * \return void
  *
  */
 void getDescripcionProyecto(eProyecto proyectos[], int cantPry, int idProyecto, char descripcion[]);

 /** \brief Obtiene el importe para una categoria
  *
  * \param categorias[] eCategoria lista de categorias
  * \param cantCat int cantidad max categorias
  * \param idCategoria int categoria buscada
  * \return float importe devuelto
  *
  */
 int getImportePorCategoria(eCategoria categorias[], int cantCat, int idCategoria);


/** \brief Carga la estructura auxiliar que contrendra los totales de cada tipo de programador por proyecto y un total gral
 *
 * \param proyectos[] eProyecto lista de proyectos
 * \param cProy int cantidad maxima de proyectos
 * \param asignaciones[] eProyectosProgramadores lista de asignaciones
 * \param cAsigna int cantidad maxima de asignaciones
 * \param programadores[] eProgramador lista de programadores.
 * \param cProg int cantidad maxima de programdores.
 * \param proyectosCantidades[] eProyectoCantCategorias estructura a llenar
 * \param categorias[] eCategoria
 * \param cCat int
 * \return void
 *
 */
void cargarProyectosCantCategorias(eProyecto proyectos[], int cProy,eProyectosProgramadores asignaciones[], int cAsigna,eProgramador programadores[], int cProg, eCategoria categorias[], int cCat, eProyectoCantCategorias proyectosCantidades[]);


 /** \brief obtiene el id de una categoria
  *
  * \param categoria[] char Nombre de la categoria a buscar
  * \param categorias[] eCategoria lista de categorias
  * \param cCat int cantidad maxima de categorias
  * \return int id de la categoria encontrada
  *
  */
 int getIdCategoria(char categoria[], eCategoria categorias[], int cCat);


/** \brief Obtiene la cantidad de una categoria pasada como parametro en un proyecto.
 *
 * \param idCategoria int Categoria buscada
 * \param idProyecto int Proyecto buscado
 * \param asignaciones[] eProyectosProgramadores lista de asignaciones
 * \param cAsigna int cantidad maxima de asignaciones
 * \param programadores eProgramador lista de programadores.
 * \param cProg int cantidad maxima de programadores
 * \return int Cantidad de programadores en la categoria.
 *
 */
int cantidadDeUnaCategoriaEnUnProyecto(int idCategoria, int idProyecto,eProyectosProgramadores asignaciones[],int cAsigna,eProgramador programadores[],int cProg);



/** \brief Verifica si un programador pertenece a una categoria
 *
 * \param idCategoria int id categoria buscada
 * \param idProgramador int id programador buscado
 * \param programadores[] eProgramador lista de programadores
 * \param cProg int cantidad maxima de programadores
 * \return int 0 - Falso / 1 - Verdadero
 *
 */
int esProgramadorDeCategoria(int idCategoria,int idProgramador,eProgramador programadores[],int cProg);


/** \brief Muestra los proyectos asignados a un programador.
 *
 * \param asignaciones[] eProyectosProgramadores lista de asignaciones
 * \param cAsigna int cantidad maxima de asignaciones
 * \param proyectos[] eProyecto lista de proyectos
 * \param cProy int cantidad maxima de proyectos
 * \param idProg int id Programador analizado
 * \return void
 *
 */
void mostrarProyectosUnProgramador(eProyectosProgramadores asignaciones[],int cAsigna,eProyecto proyectos[], int cProy,int idProg);



/** \brief Devuelve el la psiscion del proyecto con mas programadores
 *
 * \param proyectosCantidades[] eProyectoCantCategorias lista de proyectos con totales por categorias y un total final
 * \param cPry int cantidad maxima de proyectos
 * \return int indice en donde se encuentra el proyecto.
 *
 */
int idProyectoConMasProgramadores(eProyectoCantCategorias proyectosCantidades[], int cPry);


/** \brief Imprime los titulos de la tabla de poryectos
 *
 * \return void
 *
 */
void imprimirCabeceraTablaProyectos();


/** \brief Imprime los datos de cada proyecto formateados en columnas
 *
 * \param proyectos[] eProyecto lista de proyectos
 * \param cPry int cantidad maxima de proyectos
 * \return void
 *
 */
void mostrarProyectos(eProyecto proyectos[], int cPry);


/** \brief Verifica si un programador ya existe en un proyecto
 *
 * \param asignaciones[] eProyectosProgramadores lista de asignaciones
 * \param cAsigna int cantidad maxima de asignaciones
 * \param idProg int id de programador analizado
 * \param idProy int id del proyecto analizado
 * \return int 1 - Existe / 0 - No existe
 *
 */
int existeProgramadorEnProyecto(eProyectosProgramadores asignaciones[],int cAsigna,int idProg,int idProy);



#endif // LIB_H_INCLUDED
