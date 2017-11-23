#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



int esBisiesto();

int main()
{
    SYSTEMTIME  fecha;
    int anio, mes, dia, anioH=0, mesH=0, diaH=0, cantDiasPasados, respuesta;

    //GetSystemTime(&fecha); //hora mundial

    GetLocalTime (&fecha); //parametro  pasar por parametro la estructura SYSTEMTIME

    printf("Fecha %02d/%02d/%4d \nHora:%02d:%02d:%02d\n\n",fecha.wDay,fecha.wMonth,fecha.wYear,fecha.wHour,fecha.wMinute,fecha.wSecond);

    printf("FECHA DESDE:\n\n");
    printf("Ingrese el Anio: ");
    scanf("%d",&anio);
    printf("Ingrese el Mes: ");
    scanf("%d",&mes);
    printf("Ingrese el dia: ");
    scanf("%d",&dia);

    printf("Fecha %02d/%02d/%4d \nHora:%02d:%02d:%02d\n\n",fecha.wDay,fecha.wMonth,fecha.wYear,fecha.wHour,fecha.wMinute,fecha.wSecond);

    printf("\n1 - Hasta Hoy");
    printf("\n2 - Hasta Fecha Especifica\n\n");
    scanf("%d",&respuesta);

    if(respuesta == 2)
    {

        printf("FECHA HASTA:\n");
        printf("Ingrese el Anio: ");
        scanf("%d",&anioH);
        printf("Ingrese el Mes: ");
        scanf("%d",&mesH);
        printf("Ingrese el dia: ");
        scanf("%d",&diaH);
    }


    cantDiasPasados = calcularDiasPasados(anio,mes,dia, fecha, anioH, mesH, diaH, respuesta);

    printf("\nCANTIDAD DE DIAS PASADOS: %d",cantDiasPasados);

    return 0;
}


int calcularDiasPasados(int anio,int mes, int dia, SYSTEMTIME fecha, int anioH, int mesH, int diaH, int flag)
{

                               // 0  1
    int i=0, cantDias=0;      //  E  F  M  A  M  J  J  A  S  O  N  D
    int meses [12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int
    anioF = fecha.wYear,
    mesF = fecha.wMonth,
    diaF = fecha.wDay;

    printf("Fecha %02d/%02d/%4d \nHora:%02d:%02d:%02d\n\n",fecha.wDay,fecha.wMonth,fecha.wYear,fecha.wHour,fecha.wMinute,fecha.wSecond);


    if(mes==2 && esBisiesto(anio)==1)
        cantDias = 29 - dias;
    else
        cantDias = meses[mes-1] - dias;

    if(anio == anioF)
    {
        for(i=mes;i<mesF;i++)
        {
            cantDias+=meses[i];
            if(esBisiesto(anio)==1 && i == 1)
                cantDias++;
         }

    }
    else
    {

        for(i=mes;i<12;i++)
        {
            cantDias+=meses[i];
            if(esBisiesto(anio)==1 && i == 1)
                cantDias++;

        }
    }
    //Años en el medio
    for(i=anio+1;i<anioF;i++)
    {
        if(esBisiesto(i)==1)
            cantDias+=366;
        else
            cantDias+=365;
    }






    return cantDias;

}



int esBisiesto(int anio)
{
    int esBisiesto = 0;
    if( ((anio % 4) == 0 && (anio % 100) != 0) || (anio % 400) == 0)
        esBisiesto = 1;

    return esBisiesto;




}

int calcularDiasDesdePrincipioDeAnio(int dia, int mes, int anio)
{
    int i=0, cantDias=0;      //  E  F  M  A  M  J  J  A  S  O  N  D
    int meses [] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for(i=0;i<mes-1;i++)
    {
        cantDias += meses[i];
    }
    if(esBisiesto(annio)=01 && mes>2)
        cantDias++;

    cantDias+=dia;

}


int calcularDiasHastaElFinal(int mesI, int dia)
{
    int i=0, cantDias=0;      //  E  F  M  A  M  J  J  A  S  O  N  D
    int meses [] = {31,28,31,30,31,30,31,31,30,31,30,31};



}


int cuantosDiasHastaAnioSig(int anioI, int mesI, int diaI, int anioF, int mesF, int diaF, int meses[])
{

    int i, dias=0;



    else
    {
        if(anioI==anioF)
        {
            for(i=mes;i<mesF;i++)
                dias += meses[i];
        }
        else
        {
            for(i=mes;i<12;i++)
                dias += meses[i];

        }
    }
}






int cuantosDiasEsteAnio(int mes, int dia)
{

}


