#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#define QTY_USRS 100
#define QTY_PRODS 1000
#define QTY_PUBLIC 100
#define LONG_USR_NAME 10
#define LONG_PASSWORD 10
#define LONG_PRD_NAME 50

typedef struct
{
    char nombre[LONG_USR_NAME];
    char password[LONG_PASSWORD];
    int estado;
}eUsuario;



typedef struct
{
    int idUsuario;
    int idProducto;
    char nombre[LONG_PRD_NAME];
    int stock;
    float precio;
    int estado;
}ePublicacion;

typedef struct
{
    int idUsuario;
    int idProducto;
    int idComprador;
    int calificacion;
}eVentas;


void cererarDatosBasuraVectores(eUsuario usuarios[],int cUsuarios,eProducto productos[], int cProductos,ePublicacion publicaciones[], int cPublicaciones);


void ordenarListaXNombre(eUsuario usuarios[],  int tam);

int obtenerEspacioLibre(eUsuario lista[], int cantidad);

eUsuario obtenerDatoUsuario(void);

void modificarDatosUsuario(eUsuario usuarios[]);

int obtenerUsuarioPorId(int idUsr, eUsuario usuarios[]);

void bajaDeUsuario(eUsuario usuarios[],ePublicacion publicaciones[]);

int obtenerEspacioLibreProd(eProducto lista[], int cantidad);

int obtenerEspacioLibrePubli(ePublicacion lista[], int cantidad);

#endif // LIB_H_INCLUDED
