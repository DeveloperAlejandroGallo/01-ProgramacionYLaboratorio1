#include <stdio.h>
#include <stdlib.h>
/*
1- Cantidad de n�meros pares.
2- Cantidad de n�meros impares.
3- Sumatoria de todos los n�meros impares.
4- Promedio de todos los n�meros.
5- El n�mero mayor ingresado.
6- El n�mero impar menor ingresado.
7- Cu�ntos n�meros est�n entre 3-15, entre 16-29 y 30 o m�s.
8- Dada la sumatoria de todos los n�meros impares (item 3) determinar:
a- La sumatoria de todos los n�meros que le anteceden (incluyendolo). Utilizar FOR.
b- Mostrar todos los n�meros hasta la unidad. Utilizar FOR*/
int main()
{
    int
    nro,
    cantPares=0,
    cantImp=0,
    sumaImp=0,
    sumaTot=0,
    count=0,
    mayor,
    imparMenor=0,
    cantE3y15=0,
    cantE16y29=0,
    cantMas30=0,
    sumaAnteceden=0,
    bPrimeraVezMayor=1,
    bPrimeraVezMenor=1,
    i;
    char respuesta='s';

    do
    {
        system("cls");
        printf("Ingrese un Nro positivo: \n");
        fflush(stdin);//Limpia la memoria del Buffer de entrada stdin
        scanf("%d",&nro);
        while(nro<0)
        {
            printf("Ingrese un Nro positivo: \n");
            fflush(stdin);//Limpia la memoria del Buffer de entrada stdin
            scanf("%d",&nro);
        }
        //El resto
        sumaTot += nro;

        if(bPrimeraVezMayor==1 || mayor<nro)
        {
            mayor=nro;
            bPrimeraVezMayor=0;
        }

        if(nro % 2 == 0)
            cantPares++;
        else
        {
            cantImp++;
            sumaImp += nro;
            if(bPrimeraVezMenor==1 || imparMenor>nro)
            {
                imparMenor=nro;
                bPrimeraVezMenor=0;
            }
        }

        if(nro>=3 && nro <= 15) cantE3y15++;
        if(nro>=16 && nro <= 29) cantE16y29++;
        if(nro>30) cantMas30++;


        count++;
        printf("Desea Seguir(s/n): ");
        respuesta = getche(tolower(respuesta));
        if(respuesta != 'n') respuesta = 's';
    }while(respuesta == 's');

    system("cls");
    printf("1- Cantidad de n�meros pares: %d\n\n",cantPares);
    printf("2- Cantidad de n�meros impares: %d\n\n",cantImp);
    printf("3- Sumatoria de todos los n�meros impares: %d\n\n", sumaImp);
    printf("4- Promedio de todos los n�meros: %f\n\n", (float)sumaTot/count);
    printf("5- El n�mero mayor ingresado: %d\n\n", mayor);
    printf("6- El n�mero impar menor ingresado: %d\n\n", imparMenor);
    printf("7- Cu�ntos n�meros est�n entre: \n3-15: %d \n16-29: %d \nMayor a 30: %d\n\n", cantE3y15, cantE16y29, cantMas30);

    printf("Los nros desde %d has 1 son:\n",sumaImp);
    for(i=sumaImp;i>=1;i--)
    {
        sumaAnteceden += i;
        printf("%d ",i);
    }
    printf("\nY la suma de los mismos es: %d", sumaAnteceden);
    return 0;
}
