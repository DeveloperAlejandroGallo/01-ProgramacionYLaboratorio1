#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Tramite.h"

int main()
{

    char seguir='s';
    int opcion,nroTramite=0,auxDNI;

    ArrayList* tramiteUrgente = al_newArrayList();
    ArrayList* tramiteRegular = al_newArrayList();
    ArrayList* atendidosUrgente = al_newArrayList();
    ArrayList* atendidosRegular = al_newArrayList();

    Tramite* auxTramite;

    cargarTramitesPendientes(tramiteUrgente, tramiteRegular, atendidosUrgente, atendidosRegular, &nroTramite);


    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
        /*TRAMITE URGENTE: Se otorga un numero de turno para los tramites urgentes.*/
            //nroTramite = nroTramiteProximo(tramiteUrgente, tramiteRegular);
            nroTramite++;
            auxDNI = pedirDatoNumericoValidado("Ingrese su DNI: ");
            auxTramite = newTramite(auxDNI, "U", nroTramite, 0);
            tramiteUrgente->add(tramiteUrgente, auxTramite);
            printf("TURNO: \nDNI: %d\nNRO TURNO: %d",auxDNI, nroTramite);

            break;

        case 2:
        /*TRAMITE REGULAR: Se otorga un numero de turno para los tramites regulares.*/
            //nroTramite = nroTramiteProximo(tramiteUrgente, tramiteRegular);
            nroTramite++;
            auxDNI = pedirDatoNumericoValidado("Ingrese su DNI: ");
            auxTramite = newTramite(auxDNI, "R", nroTramite, 0);
            tramiteRegular->add(tramiteRegular, auxTramite);
            printf("TURNO: \nDNI: %d\nNRO TURNO: %d",auxDNI, nroTramite);
            break;

        case 3:
        /*PROXIMO CLIENTE: El sistema le indicara al usuario quien es el próximo turno
        a ser atendido y a que tramite corresponde.*/
            imprimirTitulo("PROXIMO TRAMITE A ATENDER");
            if(tramiteUrgente->isEmpty(tramiteUrgente)== 1)
            {
                tramiteRegular->sort(tramiteRegular, compareNroTramite,1);
                auxTramite = tramiteRegular->pop(tramiteRegular,0);
                atendidosRegular->add(atendidosRegular,auxTramite);
            }
            else
            {
                tramiteUrgente->sort(tramiteUrgente, compareNroTramite,1);
                auxTramite = tramiteUrgente->pop(tramiteUrgente,0);
                atendidosUrgente->add(atendidosUrgente,auxTramite);
            }
            mostrarProximoTramite(auxTramite);
            break;

        case 4:
        /*LISTAR : En esta opción se listan las personas pendientes de ser atendidas en
        cada tramite.*/
            imprimirTitulo("TRAMITES PENDIENTES");
            printf("\nTRAMITES URGENTES\n");
            mostrarTramites(tramiteUrgente);
            printf("\n\nTRAMITES REGULARES\n");
            mostrarTramites(tramiteRegular);
            break;

        case 5:
        /*INFORMAR:
        Los clientes atendidos en cada uno de los tramites ordenados por DNI de manera
        descendente.*/
            imprimirTitulo("TRAMITES ATENDIDOS");
            atendidosUrgente->sort(atendidosUrgente,compareDNI,0);
            printf("\nTRAMITES URGENTES\n");
            mostrarTramites(atendidosUrgente);

            atendidosRegular->sort(atendidosRegular,compareDNI,0);
            printf("\nTRAMITES REGULAR\n");
            mostrarTramites(atendidosRegular);

            break;

        case 6:
        /*SALIR*/
            seguir='n';
            guardarArchivo(tramiteUrgente,tramiteRegular,atendidosUrgente,atendidosRegular);
            break;

        }
        printf("\n\n");
        if(opcion!=6)
            system("pause"); //Para q no pida 2 veces la tecla al salir
    }



    return 0;
}
