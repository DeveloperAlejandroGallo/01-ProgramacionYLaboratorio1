#ifndef TRAMITE_H_INCLUDED
#define TRAMITE_H_INCLUDED


typedef struct
{
    int dni;
    char tipo[1]; //U - Urgente / R - Regular
    int nroTurno;
    int atendido; //0 - NO Atendido / 1 - Atendido
}Tramite;

void cargarTramitesPendientes(ArrayList* tramiteUrgente,ArrayList* tramiteRegular,ArrayList* atendidosUrgente,ArrayList* atendidosRegular, int* ultTurno);

Tramite* newTramite(int dni, char tipo[], int nroTurno, int atendido);

int nroTramiteProximo(ArrayList* tramiteUrgente,ArrayList* tramiteRegular);

int compareNroTramite(void* pTramiteU,void* pTramiteR);

int compareDNI(void* pTramiteU,void* pTramiteR);

void mostrarProximoTramite(Tramite* auxTramite);

void mostrarTramites(ArrayList* tramite);

void guardarArchivo(ArrayList* tramiteUrgente,ArrayList* tramiteRegular,ArrayList* atendidosUrgente,ArrayList* atendidosRegular);

void escribirEnArchivoElArray(FILE* archivoTramites,ArrayList* lista);

#endif // TRAMITE_H_INCLUDED
