#include <stdio.h>
#include <stdlib.h>


int main()
{
    char respuesta;

    do
    {
        printf("Desea salir? (s/n)");
        fflush(stdin);
        respuesta = getche();
    }
    while(toupper(respuesta) != 'S' && toupper(respuesta) != 'N');

    return 0;
}
