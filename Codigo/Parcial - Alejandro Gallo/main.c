#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "datos.h"

#define QTY_PROGRA 50
#define QTY_PROYECTOS 1000
#define QTY_CATEGORIAS 3
#define QTY_ASIGNACIONES 1000   //Deberia ser de 50 * 1000

int main()
{
    char seguir='s', respuesta;
    int opcion=0, iDNIBuscado, i,j;

    eProgramador programadores[QTY_PROGRA] ;
    eCategoria categorias[QTY_CATEGORIAS]; //= {{1,"Junior",110},{2,"SemiSenior",210},{3,"Senior",310}};
    eProyecto proyectos[QTY_PROYECTOS] ;
    eProyectosProgramadores asignaciones[QTY_ASIGNACIONES] ;
    cargar10Programadores(programadores, QTY_PROGRA);
    inicializarCategorias(categorias);
    inicializarProyectos(proyectos, QTY_PROYECTOS);
    inicializarAsiganciones(asignaciones,QTY_ASIGNACIONES);


    //Auxiliares
    int iBuscado, nroAux;
    eProgramador programadorAux;
    eProyecto proyectoAux;
    eProyectosProgramadores asignacionAux;
    eProyectoCantCategorias proyectosCantidades[QTY_PROYECTOS];

    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                iBuscado = obtenerEspacioLibre(programadores, QTY_PROGRA);
                if(iBuscado != -1)
                {
                    imprimirTitulo("ALTA DE PROGRAMADOR");
                    iDNIBuscado = pedirDatoNumericoValidado("DNI: ");
                    if(buscarPorDni(programadores,iDNIBuscado,QTY_PROGRA) == -1)
                    {
                        programadorAux=obtenerDatoProgramador(iDNIBuscado);
                        altaProgramador(programadores,programadorAux,iBuscado);
                        imprimirTitulo("PROGRAMADOR DADO DE ALTA");
                        imprimirCabeceraTablaProgramador();
                        mostrarProgramador(programadores[iBuscado], categorias, QTY_CATEGORIAS);
                    }
                    else
                        infoMessage("EL PROGRAMADOR YA EXISTE!");

                }
                else
                    infoMessage("NO QUEDAN LUGARES LIBRES.");
                break;
            case 2:
                 imprimirTitulo("MODIFICAR PROGRAMADOR");

                bubbleSortInt(programadores, QTY_PROGRA);
                imprimirCabeceraTablaProgramador();
                imprimirProgramadoresActivas(programadores, QTY_PROGRA, categorias, QTY_CATEGORIAS, asignaciones, QTY_ASIGNACIONES);

                 nroAux=pedirDatoNumericoValidado("\nDNI Buscado: ");
                 iBuscado =  buscarPorDni(programadores,nroAux,QTY_PROGRA);
                 printf("\n\n");
                 if(iBuscado != -1)
                 {
                     imprimirCabeceraTablaProgramador();
                     mostrarProgramador(programadores[iBuscado], categorias, QTY_CATEGORIAS);
                     printf("\n\n");
                     programadorAux = obtenerDatoProgramador(programadores[iBuscado].dni);
                     programadores[iBuscado] = programadorAux;
                     printf("\nProgramador Modificado:\n");
                     imprimirCabeceraTablaProgramador();
                     mostrarProgramador(programadores[iBuscado], categorias, QTY_CATEGORIAS);
                 }
                break;
            case 3:
                 imprimirTitulo("BAJA DE PROGRAMADOR");

                bubbleSortInt(programadores, QTY_PROGRA);
                imprimirCabeceraTablaProgramador();
                imprimirProgramadoresActivas(programadores, QTY_PROGRA, categorias, QTY_CATEGORIAS, asignaciones, QTY_ASIGNACIONES);

                 nroAux=pedirDatoNumericoValidado("\nDNI Buscado: ");
                 iBuscado =  buscarPorDni(programadores,nroAux,QTY_PROGRA);
                 printf("\n\n");
                 if(iBuscado != -1)
                 {
                     imprimirCabeceraTablaProgramador();
                     mostrarProgramador(programadores[iBuscado], categorias, QTY_CATEGORIAS);

                     respuesta = pedirRespuesta("\nDesea Eliminarlo? (s/n): ");

                     if(respuesta=='s')
                     {
                       bajaProgramador(programadores,iBuscado);
                     }
                     else
                     {
                       infoMessage("La programador NO se ha dado de Baja.");
                     }

                 }
                 else
                     infoMessage("EL PROGRAMADOR NO EXISTE");
                break;
            case 4:
                imprimirTitulo("ASIGNAR PROGRAMADOR A PROYECTO");

                iBuscado = obtenerEspacioLibreAsignacion(asignaciones, QTY_ASIGNACIONES);

                bubbleSortInt(programadores, QTY_PROGRA);
                imprimirCabeceraTablaProgramador();
                imprimirProgramadoresActivas(programadores, QTY_PROGRA, categorias, QTY_CATEGORIAS, asignaciones, QTY_ASIGNACIONES);

                nroAux = pedirDatoNumericoValidado("\nQue programador desea asignar: ");
                iDNIBuscado =  buscarPorDni(programadores,nroAux,QTY_PROGRA);
                printf("\n\n");

                if(iDNIBuscado != -1)
                 {
                     printf("Proyectos Activos:\n");
                     imprimirCabeceraTablaProyectos();
                     mostrarProyectos(proyectos, QTY_PROYECTOS);
                     nroAux = pedirDatoNumericoValidado("\nId de Proyecto a Asignar: ");
                     if(existeProgramadorEnProyecto(asignaciones, QTY_ASIGNACIONES, programadores[iDNIBuscado].dni, nroAux)==0)
                     {
                         asignacionAux.idProgramador = programadores[iDNIBuscado].dni;
                         asignacionAux.idProyecto = nroAux;
                         asignacionAux.estado = 1;
                         nroAux = pedirDatoNumericoValidado("\nHoras a Trabajar:(En formato entero): ");
                         asignacionAux.hsAsignadas = nroAux;
                         asignaciones[iBuscado] = asignacionAux;
                         infoMessage("ASIGNACION REALIZADA");
                     }
                     else
                        infoMessage("EL PROGRAMADOR YA EXISTE EN EL PROYECTO.");
                 }
                 else
                     infoMessage("PROGRAMADOR NO EXISTE");
                break;
            case 5:
                imprimirTitulo("LISTA DE PROGRAMADORES");
                imprimirCabeceraTablaProgramador();
                for(i=0; i<QTY_PROGRA;i++)
                {

                    if(programadores[i].estado ==1)
                    {

                        mostrarProgramador(programadores[i],categorias,QTY_CATEGORIAS);
                        printf("\n");
                        imprimirCabeceraTablaAsignacion();
                        mostrarAsignacionesProgramador(asignaciones,QTY_ASIGNACIONES,programadores[i].dni, categorias, QTY_CATEGORIAS, programadores,QTY_PROGRA,proyectos, QTY_PROYECTOS);
                        printf("\n");
                    }
                }

                break;
            case 6:
                imprimirTitulo("LISTA DE PROYECTOS:");
                cargarProyectosCantCategorias(proyectos, QTY_PROYECTOS, asignaciones, QTY_ASIGNACIONES, programadores, QTY_PROGRA, categorias, QTY_CATEGORIAS, proyectosCantidades);
                for(i=0;i<QTY_PROYECTOS;i++)
                {
                    if(proyectos[i].id!=0)
                    {
                        printf("PROYECTO: %s\n",proyectos[i].nombre);
                        printf("Juniors: %d\n", proyectosCantidades[i].cJuniors);
                        printf("Semi Seniors: %d\n",proyectosCantidades[i].cSemiSeniors);
                        printf("Seniors: %d\n\n",proyectosCantidades[i].cSeniors);
                    }
                }
                break;
            case 7:
                imprimirTitulo("PROYECTOS DE UN PROGRAMADOR");
                bubbleSortInt(programadores, QTY_PROGRA);
                imprimirCabeceraTablaProgramador();
                imprimirProgramadoresActivas(programadores, QTY_PROGRA, categorias, QTY_CATEGORIAS, asignaciones, QTY_ASIGNACIONES);

                nroAux = pedirDatoNumericoValidado("\nElija un programador: ");
                iBuscado =  buscarPorDni(programadores,nroAux,QTY_PROGRA);
                printf("\n\n");

                if(iBuscado != -1)
                 {

                     printf("Proyectos al cual esta asignado: %s, %s\n", programadores[iBuscado].nombre, programadores[iBuscado].apellido);
                     mostrarProyectosUnProgramador(asignaciones,QTY_ASIGNACIONES,proyectos, QTY_PROYECTOS, programadores[iBuscado].dni);
                 }
                 else
                     infoMessage("PROGRAMADOR NO EXISTE");
                break;
            case 8:
                imprimirTitulo("PROYECTO DEMANDANTE");
                cargarProyectosCantCategorias(proyectos, QTY_PROYECTOS, asignaciones, QTY_ASIGNACIONES, programadores, QTY_PROGRA, categorias, QTY_CATEGORIAS, proyectosCantidades);
                iBuscado = idProyectoConMasProgramadores(proyectosCantidades, QTY_PROYECTOS);
                printf("El Proyecto %s es el que mayor cantidad de programadores posee con un total de %d.\n\n",proyectos[iBuscado].nombre,proyectosCantidades[iBuscado].totalProg);
                break;
            case 0:
                seguir = 'n';
                break;
        }
        printf("\n\n");
        if(opcion!=0)
                system("pause"); //Para q no pida 2 veces la tecla al salir
    }

    return 0;

}

