#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "lib.h"



#define LARGO_NAME 50


void cargar10Programadores(eProgramador programadores[], int maxCant)
{
     int cant=10;
    //Se definen con el tamaño total para que los datos queden cereados y asi los tome la matriz
    int DNIs[10] = {29111111,29222222,29333333,29444444,29555555,29666666,29777777,
                    29888888,29999999,29000000};
    char Nombres [10][50]  = {"Alejandro","Nicolas","Carlos","Ariel","Matias",
                                                         "Juan","Pedro","ProgramadorH","ProgramadorI","ProgramadorJ"};
	char Apellidos [10][50]  = {"Gallo","Loco","Apellido1","Apellido2","Apellido3",
                                                         "Apellido4","Apellido5","Apellido6","Apellido7","Apellido8"};
    int IdCategorias[10] = {1, 2, 3, 1, 3, 2, 3, 2, 1, 2};
    int i;

    for(i=0;i<maxCant;i++)
    {
        programadores[i].dni = 0;
        programadores[i].idCategoria =  0;
        strcpy(programadores[i].nombre ," ");
		strcpy(programadores[i].apellido ," ");
        programadores[i].estado = 0;
    }

    for(i=0;i<cant;i++)
    {
        programadores[i].dni = DNIs[i];
        programadores[i].idCategoria = IdCategorias[i];
        strcpy(programadores[i].nombre ,Nombres[i]);
		strcpy(programadores[i].apellido ,Apellidos[i]);
        programadores[i].estado = 1;
    }



}


void inicializarCategorias(eCategoria categorias[])
{
    categorias[0].id = 1;
    strcpy(categorias[0].descripcion,"JUNIOR");
    categorias[0].pagoXHora = 90;

    categorias[1].id = 2;
    strcpy(categorias[1].descripcion,"SEMI SENIOR");
    categorias[1].pagoXHora = 120;

    categorias[2].id = 3;
    strcpy(categorias[2].descripcion,"SENIOR");
    categorias[2].pagoXHora = 150;
}


void inicializarProyectos(eProyecto proyectos[], int cProy)
{
    int i;

    for(i=0;i<cProy;i++)
    {
        proyectos[i].id = 0;
        strcpy(proyectos[i].nombre," ");
    }

    proyectos[0].id = 1;
    strcpy(proyectos[0].nombre,"SANTANDER");
    proyectos[1].id = 2;
    strcpy(proyectos[1].nombre,"BAPRO");
    proyectos[2].id = 3;
    strcpy(proyectos[2].nombre,"GALICIA");
    proyectos[3].id = 4;
    strcpy(proyectos[3].nombre,"COMAFI");
    proyectos[4].id = 5;
    strcpy(proyectos[4].nombre,"MARIVA");


}


void inicializarAsiganciones(eProyectosProgramadores asignaciones[],int  cAsigna)
{

    int i=0;

    int idProy[] = {1,1,1,1,2,2,3,3,3,3};
    int idProg[] = {29111111,29222222,29333333,29444444,29111111,29222222,29777777,
                    29888888,29999999,29111111};
    int hs[] = {40,100,50,77,80,120,160, 40, 200, 1000};

    for(i=0;i<cAsigna;i++)
    {
        asignaciones[i].idProyecto = 0;
        asignaciones[i].idProgramador = 0;
        asignaciones[i].hsAsignadas = 0;
        asignaciones[i].estado = 0;
    }

    for(i=0;i<10;i++)
    {
        asignaciones[i].idProyecto = idProy[i];
        asignaciones[i].idProgramador = idProg[i];
        asignaciones[i].hsAsignadas = hs[i];
        asignaciones[i].estado = 1;
    }

}


int obtenerEspacioLibre(eProgramador lista[], int cantidad)
{
    int posicion=-1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 0)
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}


int obtenerEspacioLibreAsignacion(eProyectosProgramadores lista[], int cantidad)
{
    int posicion=-1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 0)
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}


int buscarPorDni(eProgramador lista[], int dni, int tam)
{
    int posicion=-1, i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].dni==dni && lista[i].estado == 1) //Solo busco en los dados de alta.
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}


void altaProgramador(eProgramador programadores[], eProgramador programador, int espacioLibre)
{
    programadores[espacioLibre] = programador;
}


void bajaProgramador(eProgramador programadores[], int pos)
{
    programadores[pos].estado = 0;
    infoMessage("PROGRAMADOR DADO DE BAJA");
}


void imprimirCabeceraTablaProgramador()
{
     int i, largo = strlen("NOMBRE Y APELLIDO");

    printf("|%8s", "DNI");
    printf("|%s", "NOMBRE Y APELLIDO");
        for(i=0;i<51-largo;i++) //Imprimo los espacios necesario para alinear la tabla
        printf(" ");
    printf("|%10s|\n","CATEGORIA");

}


void mostrarProgramador(eProgramador programador,eCategoria categorias[], int cantCat)
{
    char categoria[11];
    int i, largo = strlen(programador.nombre);
    largo += strlen(programador.apellido);

    formatearNombre(programador.nombre);
    formatearNombre(programador.apellido);

    printf("|%08d", programador.dni);
    printf("|%s",programador.nombre);
    printf(", ");
    printf("%s", programador.apellido);
    for(i=0;i<49-largo;i++) //Imprimo los espacios necesario para alinear la tabla
        printf(" ");
    getDescripcionCategoria(programador.idCategoria, categoria, categorias, cantCat);
    printf("|%10s|\n",categoria);


}

void getDescripcionCategoria(int idCategoria, char descCat[], eCategoria categorias[], int cantCat)
{
    int i;
    for(i=0;i<cantCat;i++)
    {
        if(categorias[i].id == idCategoria)
        {
            strcpy(descCat, categorias[i].descripcion);
            break;
        }
    }
}

eProgramador obtenerDatoProgramador(int DNI)
{
    char auxString[200];
    eProgramador programador;

    programador.dni = DNI;
    pedirDatoSoloLetrasValido("NOMBRE: ",auxString);
    formatearNombre(auxString);
    strcpy(programador.nombre,auxString);
    pedirDatoSoloLetrasValido("APELLIDO: ",auxString);
    formatearNombre(auxString);
    strcpy(programador.apellido,auxString);
    programador.idCategoria = pedirDatoNumericoValidado("ID Categoria (1-Junior/2-Semi Senior/3-Senior):");
    programador.estado = 1;
    printf("\n");

    return programador;
}



void imprimirProgramadoresActivas(eProgramador programadores[], int cantProg, eCategoria categorias[], int cantCategorias,eProyectosProgramadores asignaciones[], int cAsigna)
{
    int i,j;
    for(i=0;i<cantProg;i++)
    {
        if(programadores[i].estado == 1) //Solo imprimo los que poseen estado activo
        {
            mostrarProgramador(programadores[i], categorias, cantCategorias);
        }

    }
}


 void bubbleSortInt(eProgramador programadores[], int tamanio )
 {
	//Ordenamiento burbuja de Menor a mayor
	//Con cada recorrido va llevando hacia el fondo el nro mas grande.
    int i,j;
    eProgramador aux;

	for(i=0;i<tamanio-1;i++)
	{
		for(j=i+1;j<tamanio;j++)
		{
			if(programadores[i].dni > programadores[j].dni)
			{
				aux = programadores[i];
				programadores[i] = programadores[j];
				programadores[j] = aux;
			}
		}
	}

 }


 eProyectosProgramadores obtenerDatosAsignacion(int dni)
 {
     int nroAux;
     eProyectosProgramadores asignacionAux;

    nroAux = pedirDatoNumericoValidado("Id de Proyecto a Asignar: ");
    asignacionAux.idProgramador = dni;
    asignacionAux.idProyecto = nroAux;
    asignacionAux.estado = 1;
    nroAux = pedirDatoNumericoValidado("Horas a Trabajar:(En formato entero): ");
    asignacionAux.hsAsignadas = nroAux;

    return asignacionAux;
 }


void imprimirCabeceraTablaAsignacion()
{
    printf("                                       |%10s", "PROYECTO");
    printf("|%10s", "CANT HS");
    printf("|%10s|\n","GANANCIA");

}


void mostrarAsignacionesProgramador(eProyectosProgramadores asignaciones[], int cantAsigna, int idProg, eCategoria categorias[], int cantCat, eProgramador programadores[],int cantProg, eProyecto proyectos[], int cantPry)
{
     int i, iBuscado;

    for(i=0;i<cantAsigna;i++)
    {
        if(asignaciones[i].idProgramador == idProg)
        {
            iBuscado = buscarPorDni(programadores, idProg, cantProg);
            mostrarAsignacion(asignaciones[i], programadores[iBuscado],categorias, cantCat,proyectos, cantPry);
        }
    }
 }



void mostrarAsignacion(eProyectosProgramadores asignacion,eProgramador programador, eCategoria categorias[], int cantCat, eProyecto proyectos[], int cantPry)
 {
     char descripcionPry[60];
     int importeXCat;

     getDescripcionProyecto(proyectos,cantPry,asignacion.idProyecto, descripcionPry);
     printf("                                       |%10s", descripcionPry);
     printf("|%10d",asignacion.hsAsignadas);
     importeXCat = getImportePorCategoria(categorias, cantCat, programador.idCategoria);
     printf("|%10.2f|\n", (float)(importeXCat * asignacion.hsAsignadas));

 }



void getDescripcionProyecto(eProyecto proyectos[], int cantPry, int idProyecto, char descripcion[])
 {
     int i;

     for(i=0;i<cantPry;i++)
     {
         if(proyectos[i].id == idProyecto)
         {
             strcpy(descripcion,proyectos[i].nombre);
             break;
         }
     }

 }


int getImportePorCategoria(eCategoria categorias[], int cantCat, int idCategoria)
 {
     int i;
     int importe;

     for(i=0;i<cantCat; i++)
     {
         if(categorias[i].id == idCategoria)
         {
             importe = categorias[i].pagoXHora;
             break;
         }
     }

     return importe;
 }



void cargarProyectosCantCategorias(eProyecto proyectos[], int cProy,eProyectosProgramadores asignaciones[], int cAsigna,eProgramador programadores[], int cProg, eCategoria categorias[], int cCat, eProyectoCantCategorias proyectosCantidades[])
 {
     int i;

     for(i=0;i<cProy;i++)
     {
         if(proyectos[i].id!=0)
         {

             proyectosCantidades[i].idProyecto = proyectos[i].id;
             proyectosCantidades[i].cJuniors = cantidadDeUnaCategoriaEnUnProyecto(getIdCategoria("JUNIOR", categorias, cCat), proyectos[i].id, asignaciones, cAsigna, programadores, cProg);
             proyectosCantidades[i].cSemiSeniors = cantidadDeUnaCategoriaEnUnProyecto(getIdCategoria("SEMI SENIOR", categorias, cCat), proyectos[i].id, asignaciones, cAsigna, programadores, cProg);
             proyectosCantidades[i].cSeniors = cantidadDeUnaCategoriaEnUnProyecto(getIdCategoria("SENIOR", categorias, cCat), proyectos[i].id, asignaciones, cAsigna, programadores, cProg);
             proyectosCantidades[i].totalProg = proyectosCantidades[i].cJuniors + proyectosCantidades[i].cSemiSeniors + proyectosCantidades[i].cSeniors;
         }
     }

 }



 int getIdCategoria(char categoria[], eCategoria categorias[], int cCat)
{
    int i;

    for(i=0;i<cCat; i++)
    {
        if(strcmp(categoria,categorias[i].descripcion)==0)
            return categorias[i].id;
    }
}



 int cantidadDeUnaCategoriaEnUnProyecto(int idCategoria, int idProyecto,eProyectosProgramadores asignaciones[],int cAsigna,eProgramador programadores[],int cProg)
 {
     int i, contador=0;

     for(i=0;i<cAsigna;i++)
     {
         if(asignaciones[i].idProyecto == idProyecto && asignaciones[i].estado ==1)
         {
             if(esProgramadorDeCategoria(idCategoria, asignaciones[i].idProgramador,programadores, cProg)==1)
                 contador++;
         }
     }
     return contador;
 }


int esProgramadorDeCategoria(int idCategoria,int idProgramador,eProgramador programadores[],int cProg)
{
    int i, respuesta=0;

    for(i=0;i<cProg;i++)
    {
        if(programadores[i].estado==1 && programadores[i].dni == idProgramador && programadores[i].idCategoria == idCategoria)
        {
            respuesta =1;
            break;
        }
    }

    return respuesta;
}




void mostrarProyectosUnProgramador(eProyectosProgramadores asignaciones[],int cAsigna,eProyecto proyectos[], int cProy,int idProg)
{
    int i, flag=0;
    char descripcion[60];
    for(i=0;i<cAsigna;i++)
    {
        if(asignaciones[i].estado ==1 && asignaciones[i].idProgramador==idProg)
        {
            getDescripcionProyecto(proyectos,cProy,asignaciones[i].idProyecto,descripcion);
            printf("%s\n",descripcion);
            flag = 1;
        }
    }
    if(flag==0)
        printf("SIN ASIGNACIONES ACTUALES.");
}



int idProyectoConMasProgramadores(eProyectoCantCategorias proyectosCantidades[], int cPry)
{
    int i, posicion, maximo;

    maximo = proyectosCantidades[0].totalProg;
    posicion = 0;
    for(i=0;i<cPry;i++)
    {
        if(maximo < proyectosCantidades[i].totalProg)
        {
            maximo = proyectosCantidades[i].totalProg;
            posicion = i;
        }
    }

    return posicion;
}


void imprimirCabeceraTablaProyectos()
{
    printf("|%3s", "ID");
    printf("|%10s\n", "DESCRIPCION");
}


void mostrarProyectos(eProyecto proyectos[], int cPry)
{
    int i;

    for(i=0;i<cPry; i++)
    {
        if(proyectos[i].id!=0)
        {
            printf("|%3d",proyectos[i].id);
            printf("|%10s\n",proyectos[i].nombre);
        }
    }
}


int existeProgramadorEnProyecto(eProyectosProgramadores asignaciones[],int cAsigna,int idProg,int idProy)
{
    int i, existe = 0;

    for(i=0;i<cAsigna;i++)
    {
        if(asignaciones[i].estado == 1 && asignaciones[i].idProyecto == idProy && asignaciones[i].idProgramador == idProg )
        {
            existe = 1;
            break;
        }

    }

    return existe;
}




