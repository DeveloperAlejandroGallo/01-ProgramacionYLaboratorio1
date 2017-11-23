#include "MiLibreria.h"

int sumar(int n1, int n2)
{
    return n1 + n2;
}

int restar(int n1, int n2)
{
    return n1 + n2;
}

float dividir(float nro1, float nro2)
{
    if(nro2 == 0)
    {
        printf("No se puede dividir por CERO!!!\n");
        return 0.0;
    }
    return nro1 / nro2;

}

int multiplicar(int nro1, int nro2)
{
    return nro1 * nro2;
}

int factorial(int nro)
{
    if(nro==0)
        return 1;
    else
        return nro * factorial(nro-1);
}


