#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GalloAlejandro.h"


int main()
{
    char seguir='s';
    char opcion;
    int bOperando1=0;
    int bOperando2=0;
    float operando1;
    float operando2;


    while(seguir=='s')
    {
        system("cls");
        printf("******************************\n");
        printf("*     CALCULADORA 1RO G      *\n");
        printf("******************************\n\n");
        printf("MENU:\n");
        if(bOperando1 == 0) printf("1- Ingresar 1er operando (A=x)\n");
        else printf("1- Ingresar 1er operando (A=%f)\n",operando1);

        if(bOperando2 == 0) printf("2- Ingresar 2do operando (B=y)\n");
        else printf("2- Ingresar 2do operando (B=%f)\n",operando2);

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        //scanf("%f",&opcion);
        opcion = getch();

        switch(opcion)
        {
            case '1':
                printf("A= ");
                operando1 = obtenerNro();
                bOperando1=1;
                break;
            case '2':
                printf("B= ");
                operando2 = obtenerNro();
                bOperando2=1;
                break;
            case '3':
				if(bOperando1 == 1 && bOperando2 == 1)
					printf("%f + %f= %f \n", operando1,operando2,sumar(operando1,operando2));
                break;
            case '4':
				if(bOperando1 == 1 && bOperando2 == 1)
					printf("%f - %f= %f \n",operando1,operando2, restar(operando1,operando2));
                break;
            case '5':
				if(bOperando1 == 1 && bOperando2 == 1)
                {
                    if(operando2 !=0 )
                        printf("%f / %f= %f \n", operando1,operando2,dividir(operando1,operando2));
					else
                        printf("%f / %f= ERROR: Esta intentando dividir por cero.\n",operando1,operando2);
                }
                break;
            case '6':
				if(bOperando1 == 1 && bOperando2 == 1)
					printf("%f * %f= %f \n",operando1,operando2, multiplicar(operando1,operando2));
                break;
            case '7':
                //Se requiere el 1er operando y debe ser mayor o igual a cero. Ya que matematicamente se define 0! = 1.
				if(bOperando1 == 1 )
					if(operando1>=0)
                        printf("%d!= %d \n",(int)operando1, factorial((int)operando1));
					else
                        printf("%d!= ERROR el Nro debe ser mayor o igual a cero\n",(int) operando1);
                break;
            case '8':
				if(bOperando1 == 1 && bOperando2 == 1)
				{
					printf("\n");
					printf("%f + %f= %f \n", operando1,operando2,sumar(operando1,operando2));

					printf("%f - %f= %f \n",operando1,operando2, restar(operando1,operando2));

					if(operando2 !=0 )
                        printf("%f / %f= %f \n", operando1,operando2,dividir(operando1,operando2));
					else
                        printf("%f / %f= ERROR: Esta intentando dividir por cero.\n");

					printf("%f * %f= %f \n",operando1,operando2, multiplicar(operando1,operando2));

					if(operando1>=0)
                        printf("%d!= %d \n",(int)operando1, factorial((int)operando1));
					else
                        printf("%d!= ERROR el Nro debe ser mayor o igual a cero\n",(int)operando1);
				}
                break;
            case '9':
                seguir = 'n';
				printf("USTED HA SALIDO DEL SISTEMA\n\n");
                break;
        }

        //Ambos operandos deben estar cargados para las opciones que requieren los 2
		if((bOperando1 == 0 || bOperando2 == 0) && opcion != '9' && opcion != '1' && opcion != '2'  && opcion != '7')
		{
			printf("Ambos operandos deben estar cargados!\n\n");
		}
		else if (bOperando1 == 0 && opcion == '7')  //Validacion para el factorial ya que solo requiere el 1er operador
            printf("Debe cargar el 1er operando.\n\n");

        //Pausa para mostrar el resultado
		if(opcion != '1' && opcion != '2')
		system("pause");
    }
    return 0;
}
