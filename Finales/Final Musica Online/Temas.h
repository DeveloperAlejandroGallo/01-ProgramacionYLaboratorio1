#ifndef TEMAS_H_INCLUDED
#define TEMAS_H_INCLUDED

typedef struct
{
    int id;
    char* nombre;
    char* artista;
}Tema;

void cargarArrayTemas(ArrayList* arrayTemas);

Tema* new_Tema(int id, char* nombre,char* artista);

int ordenarPorArtistaYTema(void* tema1, void* tema2);

int ordenarPorTema(void* tema1, void* tema2);
#endif // TEMAS_H_INCLUDED
