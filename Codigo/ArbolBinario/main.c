#include <stdio.h>
#include <stdlib.h>


/* estructura autorreferenciada */
typedef struct
{
    struct nodoArbol* ptrIzq;   /* apuntador al subárbol izquierdo */
    int dato;                   /* valor del nodo */
    struct nodoArbol* prtDer;   /* apuntador al subárbol derecho */
}nodoArbol;                     /* fin de la estructura nodoArbol */

typedef struct nodoArbol NodoArbol; /* sinónimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol;    /* sinónimo de NodoArbol* */

void insertaNodo()


int main()
{




    return 0;
}
