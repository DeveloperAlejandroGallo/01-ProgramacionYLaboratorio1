#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "paseadores.h"



int main()
{

//Alta e Inicializacion de estructuras
    ePaseador paseadores[] = {{10,"Leo"},{20,"Pablo"},{30,"Anahi"},{40,"Juan"},{50,"Ale"}};
    ePerro perros[] = {{1,"Firulais",100},{2,"cuki",100},{3,"Pupi",300},{4,"Perruli",200},{5,"Negro",400}};
    eRaza razas[] = {{100,"doberman"},{200,"gran danes"},{300,"beagle"},{400,"manto negro"},{500,"chiwawa"}};



    ePaseadoresPerros paseos[]={{10,1,1},{20,2,2},{20,3,3},{20,1,4},{30,1,5},{40,5,6}};

    char seguir='s', respuesta;
    int opcion=0;
    //Auxiliares
    int idBuscado, nro;
    ePaseador paseadorAux;
    char nombreBuscado[LARGO_NAME];


    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                imprimirTitulo("CANTIDAD PASEOS PERRO");
                pedirDato("Nombre del perro: ",nombreBuscado);
                idBuscado = buscoIdPerro(nombreBuscado, perros, QTY_PERROS);
                if(idBuscado !=0)
                    cuantosPaseosHizoUnPerro(idBuscado, nombreBuscado,paseos,QTY_PASEOS);
                else
                    infoMessage("El Perro no existe en la base.");
                break;
            case 2:
                imprimirTitulo("PASEADOR QUE MAS PASEA");
                paseadorQueMasPasea(paseadores, QTY_PASEADORES, paseos, QTY_PASEOS);
                break;
            case 3:


                break;
            case 4:

                break;
            case 5:
                seguir = 'n';
                break;
        }
        printf("\n\n");
        if(opcion!=5)
                system("pause"); //Para q no pida 2 veces la tecla al salir
    }

    return 0;
}

