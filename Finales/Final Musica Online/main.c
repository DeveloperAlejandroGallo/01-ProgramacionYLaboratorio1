#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Usuarios.h"
#include "Temas.h"
#include "Estadisticas.h"

#define ASC 1
#define DESC -1

int main()
{

    ArrayList* arrayUsrs = al_newArrayList();
    ArrayList* arrayTemas = al_newArrayList();
    ArrayList* arrayEstadistic = al_newArrayList();
    char seguir = 's', orden;
    char nombre[30], passw[30], tema[30], pais[3];
    int opcion, idUsr, idTema;

    cargarArrayUsuarios(arrayUsrs);
    cargarArrayTemas(arrayTemas);
    cargarArrayEstadisticas(arrayEstadistic);

    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
        /*TRAMITE URGENTE: Se otorga un numero de turno para los tramites urgentes.*/
            imprimirTitulo("LISTAR USUARIOS");
            printf("Elija una opcion:\n");
            printf("a) Por Nombre.\n");
            printf("b) Por Nacionalidad y Nombre.\n");
            scanf("%s",&orden);
            switch(toupper(orden))
            {
            case 'A':
                arrayUsrs->sort(arrayUsrs, ordenPorNombre,DESC);
                break;
            case 'B':
                arrayUsrs->sort(arrayUsrs, ordenPorNacionalidadYNombre,DESC);
                break;
            default:
                infoMessage("No es una opcion válida.");
                break;
            }
            if(toupper(orden) =='A' || toupper(orden)=='B')
                imprimirUsuarios(arrayUsrs);
        break;

        case 2:
            imprimirTitulo("LISTAR TEMAS");
            arrayTemas->sort(arrayTemas,ordenarPorArtistaYTema,DESC);
            imprimirTemas(arrayTemas);
        break;

        case 3:
            imprimirTitulo("ESCUCHAR TEMA");
            printf("Ingrese su Nombre: ");
            scanf("%s",nombre);
            printf("Ingrese su Password: ");
            scanf("%s",passw);
            if(usuarioYPasswValidos(arrayUsrs, nombre, passw, &idUsr, pais))
            {
                printf("Elija un tema: ");
                scanf("%s",tema);
                if(existeTema(arrayTemas,tema, &idTema))
                {
                    agregarTemaAEstadistica(arrayEstadistic,idUsr, pais, idTema);
                }
                else
                    infoMessage("El tema no existe");
            }
            else
                infoMessage("Usuario o Password invalidos.");
        break;

        case 4:
            imprimirTitulo("GUARDAR ESTADISTICA");
            guardarEstadisticas(arrayEstadistic);
        break;

        case 5:
            imprimirTitulo("INFORME");


            break;

        case 6:
        /*SALIR*/
            seguir='n';
            break;

        }
        printf("\n\n");
        if(opcion!=6)
            system("pause"); //Para q no pida 2 veces la tecla al salir
    }



    return 0;
}
