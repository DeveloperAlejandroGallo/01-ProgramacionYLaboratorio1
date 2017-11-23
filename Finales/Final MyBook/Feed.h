#ifndef FEED_H_INCLUDED
#define FEED_H_INCLUDED

typedef struct
{
    int idMensaje;
    char* mensaje;
    int popularidadMsg;
    int idUsuarioMsg;
    char* nick;
    int popularidadUsr;
}Feed;

void armarArrayFinal(ArrayList* arrayPost,ArrayList* arrayUsrs,ArrayList* arrayFeeds);

Feed* new_Feed(int id, char* mensaje, int popuMsg, int idUsr, char* nick, int popuUsr);

int ordenPorPopuaridad(void* feed1, void* feed2);

void guardarArchivoFeeds(ArrayList* arrayFeeds);

#endif // FEED_H_INCLUDED
