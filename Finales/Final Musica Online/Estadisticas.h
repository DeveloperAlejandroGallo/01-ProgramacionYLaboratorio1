#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

typedef struct
{
    int idUsuario;
    char* pais;
    int idTema;
    int cantReproducciones;
}Estadistica;

Estadistica* new_Estadistica(int idUsr, char* pais,int idTema, int cantReprod);

void cargarArrayEstadisticas(ArrayList* arrayEstadisticas);

void guardarEstadisticas(ArrayList* arrayEstad);

#endif // ESTADISTICAS_H_INCLUDED
