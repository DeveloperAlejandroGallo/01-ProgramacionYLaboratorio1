#include <stdio.h>
#include "GalloAlejandro.h"
/**************************************************************************************************/
//Implementacion
/**************************************************************************************************/


float sumar(float n1, float n2)
{
    return n1 + n2;
}

float restar(float n1, float n2)
{
    return n1 - n2;
}

float dividir(float nro1, float nro2)
{

    return (float)nro1 / (float)nro2;

}

float multiplicar(float nro1, float nro2)
{
    return nro1 * nro2;
}

int factorial(int nro)
{//Solo recibo la parte entera de A para calcular el factorial.
    if(nro==0)
        return 1;
    else
        return nro * factorial(nro-1);
}

float obtenerNro()
{
	float nro;
	fflush(stdin);
	scanf("%f",&nro);

	return nro;
}


