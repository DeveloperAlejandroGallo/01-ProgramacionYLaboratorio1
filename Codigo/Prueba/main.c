#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, mes, anio;
    printf("Ingrese la fecha de Nacimiento (dd/mm/aaaa): ");

    scanf("%2d/%2d/%4d",&dia, &mes, &anio);

    printf("\n%02d/%02d/%4d",dia, mes, anio);
    return 0;
}
