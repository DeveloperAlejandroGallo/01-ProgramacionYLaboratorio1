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

//Vectores
int mayorDeVectorInt(int vector[], int tamanio)
{
	int mayor, i;

	mayor = vector[0];

	for(i=0;i<tamanio;i++)
	{
		if(vector[i]>mayor)
			mayor = vector[i];
	}

	return mayor;

}

int menorDeVectorInt(int vector[], int tamanio)
{
	int menor, i;

	menor = vector[0];

	for(i=0;i<tamanio;i++)
	{
		if(vector[i]<menor)
			menor = vector[i];
	}

	return menor;

}


 void bubbleSortInt(int vector[], int tamanio, int criterio )
 {
	//Ordenamiento burbuja de Menor a mayor
	//Con cada recorrido va llevando hacia el fondo el nro mas grande.
    int i,j, aux;


	for(i=0;i<tamanio-1;i++)
	{
		for(j=i+1;j<tamanio;j++)
		{
            if(criterio == 0)
            {

                if(vector[i] > vector[j])
                {
                    aux = vector[i];
                    vector[i] = vector[j];
                    vector[j] = aux;
                }
            }
            else if (criterio == 1)
            {
                if(vector[i] < vector[j])
                {
                    aux = vector[i];
                    vector[i] = vector[j];
                    vector[j] = aux;
                }
            }

		}
	}
 }

 
 int BuscarIndex(int vector[], int cant)
 