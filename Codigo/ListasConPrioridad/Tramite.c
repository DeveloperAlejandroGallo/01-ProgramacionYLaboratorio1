#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Tramite.h"


void cargarTramitesPendientes(ArrayList* tramiteUrgente,ArrayList* tramiteRegular,ArrayList* atendidosUrgente,ArrayList* atendidosRegular, int* ultTurno)
{
    ArrayList* auxArray = al_newArrayList();
    Tramite* auxTramite;
    int i;

	//Tramite* t1 =  newTramite(29637001,"U",1,0);
	//Tramite* t2 =  newTramite(29637002,"U",2,0);
	//Tramite* t3 =  newTramite(29637003,"R",3,0);
	//Tramite* t4 =  newTramite(29637004,"U",4,0);
	//Tramite* t5 =  newTramite(29637005,"R",5,0);
	//Tramite* t6 =  newTramite(29637006,"R",6,0);
	//Tramite* t7 =  newTramite(29637007,"R",7,0);
	//Tramite* t8 =  newTramite(29637008,"U",8,0);
	//Tramite* t9 =  newTramite(29637009,"U",9,0);
	//Tramite* t10 = newTramite(29637010,"U",10,0);
	//Tramite* t11 = newTramite(29637011,"U",11,0);
	//Tramite* t12 = newTramite(29637012,"R",12,0);
	//Tramite* t13 = newTramite(29637013,"R",13,0);
	//Tramite* t14 = newTramite(29637014,"R",14,0);
	//Tramite* t15 = newTramite(29637015,"U",15,0);
	//Tramite* t16 = newTramite(29637016,"U",16,0);
	//Tramite* t17 = newTramite(29637017,"R",17,0);
	//Tramite* t18 = newTramite(29637018,"R",18,0);
	//Tramite* t19 = newTramite(29637019,"U",19,0);
    //Tramite* t20 = newTramite(29637020,"R",20,0);
//
    //auxArray->add(auxArray,t1);
    //auxArray->add(auxArray,t2);
    //auxArray->add(auxArray,t3);
    //auxArray->add(auxArray,t4);
    //auxArray->add(auxArray,t5);
    //auxArray->add(auxArray,t6);
    //auxArray->add(auxArray,t7);
    //auxArray->add(auxArray,t8);
    //auxArray->add(auxArray,t9);
    //auxArray->add(auxArray,t10);
    //auxArray->add(auxArray,t11);
    //auxArray->add(auxArray,t12);
    //auxArray->add(auxArray,t13);
    //auxArray->add(auxArray,t14);
    //auxArray->add(auxArray,t15);
    //auxArray->add(auxArray,t16);
    //auxArray->add(auxArray,t17);
    //auxArray->add(auxArray,t18);
    //auxArray->add(auxArray,t19);
    //auxArray->add(auxArray,t20);
//
    //for(i=0; i<auxArray->size; i++)
    //{
    //    auxTramite = (Tramite*)al_get(auxArray,i);
    //    if(strcmp(auxTramite->tipo, "U") == 0)
    //    {
    //        tramiteUrgente->add(tramiteUrgente,al_get(auxArray,i));
    //    }
    //    else
    //    {
    //        tramiteRegular->add(tramiteRegular,al_get(auxArray,i));
    //    }
    //}


    FILE* archivoTramites;
    char sDni[10], sTipo[10], sNroTurno[10], sAtendido[10];
    Tramite* pTramite;

    archivoTramites = fopen("Tramites.csv", "r");

    if(archivoTramites != NULL)
    {
        while(!feof(archivoTramites))
        {
            fscanf(archivoTramites, "%[^,],%[^,],%[^,],%[^\n]\n", sDni, sTipo, sNroTurno,sAtendido);
            pTramite = newTramite(atoi(sDni),sTipo, atoi(sNroTurno),atoi(sAtendido));
            if(strcmp(pTramite->tipo, "U") == 0 )
            {
                if(pTramite->atendido == 0)
                    tramiteUrgente->add(tramiteUrgente,pTramite);
                else
                    atendidosUrgente->add(atendidosUrgente,pTramite);
            }
            else
            {
                if(pTramite->atendido == 0)
                    tramiteRegular->add(tramiteRegular,pTramite);
                else
                    atendidosRegular->add(atendidosRegular,pTramite);
            }

            if(pTramite->nroTurno > (*ultTurno))
                (*ultTurno) = pTramite->nroTurno;
        }
    }
}


Tramite* newTramite(int dni, char tipo[], int nroTurno, int atendido)
{
    Tramite* tramiteAux = NULL;
    Tramite* pTramite = malloc(sizeof(Tramite));

    if(pTramite != NULL)
    {
        pTramite->dni = dni;
        strcpy(pTramite->tipo,tipo);
        pTramite->nroTurno = nroTurno;
        pTramite->atendido = atendido;
        tramiteAux = pTramite;
    }

    return tramiteAux;
}




int nroTramiteProximo(ArrayList* tramiteUrgente,ArrayList* tramiteRegular)
{
    int maxUrgente, maxRegular;
    Tramite* auxTramite;

    tramiteUrgente->sort(tramiteUrgente,compareNroTramite,1);
    auxTramite = tramiteUrgente->get(tramiteUrgente,0);
    maxUrgente = auxTramite->nroTurno;

    tramiteRegular->sort(tramiteRegular,compareNroTramite,1);
    auxTramite = tramiteRegular->get(tramiteRegular,0);
    maxRegular = auxTramite->nroTurno;

    if(maxRegular > maxUrgente)
        return maxRegular++;
    else
        return maxUrgente++;

}


int compareNroTramite(void* pTramiteU,void* pTramiteR)
{

    if(((Tramite*)pTramiteU)->nroTurno > ((Tramite*)pTramiteR)->nroTurno)
    {
        return 1;
    }
    if(((Tramite*)pTramiteU)->nroTurno < ((Tramite*)pTramiteR)->nroTurno)
    {
        return -1;
    }
    return 0;
}

int compareDNI(void* pTramiteU,void* pTramiteR)
{

    if(((Tramite*)pTramiteU)->dni > ((Tramite*)pTramiteR)->dni)
    {
        return 1;
    }
    if(((Tramite*)pTramiteU)->dni < ((Tramite*)pTramiteR)->dni)
    {
        return -1;
    }
    return 0;
}



void mostrarProximoTramite(Tramite* auxTramite)
{
    printf("TIPO DE TRAMITE: ");
    if(strcmp(auxTramite->tipo,"U")==0)
        printf("URGENTE\n");
    else
        printf("REGULAR\n");

    printf("NRO DE TURNO: %d\n", auxTramite->nroTurno);
    printf("DNI: %d\n", auxTramite->dni);
}


void mostrarTramites(ArrayList* tramite)
{
    int i;
    Tramite* aux;
    printf("%8s|%8s\n","DNI","TURNO");
    for(i=0; i<tramite->size;i++)
    {
        aux =  (Tramite*)tramite->get(tramite,i);
        printf("%8d|%8d\n",aux->dni,aux->nroTurno);
    }
}


void guardarArchivo(ArrayList* tramiteUrgente,ArrayList* tramiteRegular,ArrayList* atendidosUrgente,ArrayList* atendidosRegular)
{
    int i;
    FILE* archivoTramites = fopen("Tramites.csv", "w");
    Tramite* auxTramite;

    if(archivoTramites!=NULL)
    {
        escribirEnArchivoElArray(archivoTramites,tramiteUrgente);
        escribirEnArchivoElArray(archivoTramites,tramiteRegular);
        escribirEnArchivoElArray(archivoTramites,atendidosUrgente);
        escribirEnArchivoElArray(archivoTramites,atendidosRegular);

    }


}


void escribirEnArchivoElArray(FILE* archivoTramites,ArrayList* lista)
{
    Tramite* auxTramite;
    int i;

    for(i=0; i< lista->len(lista);i++)
    {
        auxTramite = (Tramite*)lista->get(lista,i);
        fprintf(archivoTramites,"%d,%s,%d,%d\n",auxTramite->dni,auxTramite->tipo,auxTramite->nroTurno,auxTramite->atendido);
    }

}





