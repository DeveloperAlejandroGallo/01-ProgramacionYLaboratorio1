#ifndef PASEADORES_H_INCLUDED
#define PASEADORES_H_INCLUDED

#define QTY_PASEADORES 20
#define QTY_PERROS 20
#define QTY_RAZAS 5
#define QTY_PASEOS 100
#define LARGO_NAME 50


/* ESTRUCTURAS */
typedef struct
{
    int idPaseador;
    char nombre[LARGO_NAME];
} ePaseador;

typedef struct
{
    int idPerro;
    char nombre[LARGO_NAME];
    int idRaza;
} ePerro;

typedef struct
{
    int idPaseador;
    int idPerro;
    int idPaseo;
}ePaseadoresPerros; //Paseo

typedef struct
{
    int idRaza;
    char descripcion[LARGO_NAME];
}eRaza;

/***/
typedef struct
{
    char nombre[50];
    int cantidad;
} ePaseadorCantPaseos;

/*********************DECLARACIONES*****************************/

void cargar10DatosEnEstructuras(ePaseador paseadores[], ePerro perros[], eRaza razas[]);


#endif // PASEADORES_H_INCLUDED
