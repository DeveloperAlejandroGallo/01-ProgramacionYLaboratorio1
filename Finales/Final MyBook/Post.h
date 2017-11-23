#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

typedef struct
{
    int id;
    char* mensaje;
    int popularidad;
    int idUsrPublicacion;
}Post;

Post* new_Post(int id, char* mensaje, int popu, int idUsrPubli);

void cargarArchivoEnListaPost(ArrayList* arrayPost);


#endif // POST_H_INCLUDED
