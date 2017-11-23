#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char marca[20];
    char modelo[15];
    float precio;
}eNotebook;


eNotebook* new_notebook(void)
{
    eNotebook* x;
    x = (eNotebook*)malloc(sizeof(eNotebook)); //Consigo memoria dinamica
    //De esta manera dejo q el contructor devuelva el puntero inicializado.

    if(x != NULL)
    {
        x->id=0;
        x->precio=0;
        strcpy(x->marca,"");
        strcpy(x->modelo,"");
    }
    return x;
}

eNotebook* new_notebookParam(int id, char* marca, char* modelo, float precio)
{
    eNotebook* x;
    x = (eNotebook*)malloc(sizeof(eNotebook)); //Consigo memoria dinamica
    //De esta manera dejo q el contructor devuelva el puntero inicializado.

    if(x != NULL)
    {
        x->id=id;
        x->precio=precio;
        strcpy(x->marca,marca);
        strcpy(x->modelo,modelo);
    }

    return x;
}





void mostrarNotebook(eNotebook* x)
{
    printf("Id: %d\n",x->id);
    printf("Marca: %s\n", x->marca);
    printf("Modelo: %s\n", x->modelo);
    printf("Precio: %.2f\n", x->precio);
}


int main()
{

    eNotebook* unaNotebook;
    eNotebook* otraNotebook;
    unaNotebook = new_notebook();
    otraNotebook = new_notebookParam(1,"Toshiba","Satellite", 14000);
    if(unaNotebook == NULL )
    {
        printf("No se puede asignar memoria");
        exit(1);
    }

    mostrarNotebook(unaNotebook);
    printf("\n");
    mostrarNotebook(otraNotebook);
    free(unaNotebook);
    free(otraNotebook);

    return 0;
}
