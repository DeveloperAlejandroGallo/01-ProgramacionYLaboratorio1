#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma=0;
    float promedio=0;

    int nro;
    int i;
    for(i=0;i<2;i++)
    {
        printf("Ingrese el %d numero\n",i+1);
        scanf("%d",&nro);
        suma+=nro;
    }
    promedio = (float)suma/i;
    printf("El promedio de los nros es: %.2f",promedio);

    return 0;
}
