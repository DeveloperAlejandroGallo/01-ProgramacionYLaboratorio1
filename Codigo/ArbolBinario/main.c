#include <stdio.h>
#include <stdlib.h>


/* estructura autorreferenciada */
typedef struct
{
    struct nodoArbol* ptrIzq;   /* apuntador al sub�rbol izquierdo */
    int dato;                   /* valor del nodo */
    struct nodoArbol* prtDer;   /* apuntador al sub�rbol derecho */
}nodoArbol;                     /* fin de la estructura nodoArbol */

typedef struct nodoArbol NodoArbol; /* sin�nimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol;    /* sin�nimo de NodoArbol* */

void insertaNodo()


int main()
{




    return 0;
}
