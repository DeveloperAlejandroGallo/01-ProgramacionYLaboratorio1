#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char marca[20];
    char modelo[15];
    float precio;
}eNotebook;



int main()
{
     int cant, cantEscritos;
    //FILE
    FILE* archivo;

    eNotebook* unaNotebook;
    eNotebook* otraNotebook;
    unaNotebook = new_notebook();
    otraNotebook = new_notebookParam(1,"Toshiba","Satellite", 14000);
    if(unaNotebook == NULL )
    {
        printf("No se puede asignar memoria");
        exit(1);
    }


    archivo = fopen("Notebooks.dat", "rb");
    if(archivo == NULL)
    {
        archivo = fopen("Notebooks.dat", "wb");
        if(archivo==NULL)
        {
            printf("Sin memoria suficiente para crear el archivo");
            exit(1);
        }
    }

    fwrite(otraNotebook, sizeof(eNotebook),1,archivo);

    mostrarNotebook(unaNotebook);
    printf("\n");
    mostrarNotebook(otraNotebook);

    fclose(archivo);
    free(unaNotebook);
    free(otraNotebook);

    return 0;
}




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
