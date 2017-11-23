#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SYSTEMTIME fecha;
    GetLocalTime(&fecha);

    int edadDia, edadMes, edadAnio, dia, mes, anio;
    int edad=0;

    printf("Ingrese dia de Nac:");
    scanf("%d",&edadDia);
    printf("Ingrese mes de Nac:");
    scanf("%d",&edadMes);
    printf("Ingrese Anio de Nac:");
    scanf("%d",&edadAnio);

    dia = fecha.wDay;
    mes = fecha.wMonth;
    anio = fecha.wYear;

    printf("Fecha Actual: %02d/%02d/%4d\n",dia,mes,anio);

    printf("Fecha Nacimiento: %02d/%02d/%4d\n",edadDia,edadMes,edadAnio);

    if(anio > edadAnio)
     {


        edad = (anio-1) - edadAnio;

        if(edadMes < mes)
            edad++;

        if(edadMes == mes)
        {
            if(edadDia <= dia)
                edad++;

        }
    }

    printf("\nSu edad es: %d\n", edad);

    return 0;
}
