#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED


typedef struct
{
    int id;
    char* nick;
    int popularidad;
}Usuario;


Usuario* new_Usuario(int id, char* nick, int popu);

void cargarArchivoEnListaUsr(ArrayList* arrayUsuarios);

#endif // USUARIOS_H_INCLUDED
