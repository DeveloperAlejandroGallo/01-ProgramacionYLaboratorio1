#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "datos.h"



//Se que debemos poner las funciones en las librerias pero las funciones que
//devuelven float no lo devuelven correctamente al estar en librerias.
float getFloat(char mensaje[]);
int esNumericoFlotante(char str[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
float pedirDatoFloatValido(char mensaje[]);





int main()
{
	char seguir = 's', opcion;

	int iPosition;

    while(seguir=='s')
    {
        printMenu();
        scanf("%d",&option);

        switch(option)
        {
        case 1: //ALTA USUARIO
            imprimirTitulo("ALTA DE USUARIO");
            altaDeUsuario(usuarios);
            break;
        case 2: //MODIFICAR DATOS DEL USUARIO
            imprimirTitulo("MODIFICAR DATOS DEL USUARIO");
            modificarDatosUsuario(usuarios);
            break;
        case 3: // BAJA DEL USUARIO
            imprimirTitulo("BAJA DE USUARIO");
            bajaDeUsuario(usuarios, publicaciones);
            break;
        case 4: // PUBLICAR PRODUCTO
            imprimirTitulo("PUBLICAR PRODUCTO");
            publicarUnProductoParaUnUsuario(usuarios, productos, publicaciones);
            break;
        case 5: // MODIFICAR PUBLICACIÓN
            break;
        case 6: // CANCELAR PUBLICACIÓN
            break;
        case 7: // COMPRAR PRODUCTO
            break;
        case 8: // LISTAR PUBLICACIONES DE USUARIO
            break;
        case 9: // LISTAR PUBLICACIONES
            break;
        case 10: // LISTAR USUARIOS
            imprimirTitulo("LISTA DE USUARIOS");
            imprimirCabeceraTablaUSR();
            imprimirUsuarios(usuarios);
            break;
        case 0: // SALIR
            seguir = 'n';
            break;

		}
		if(option != 0)
			system("pause");
	}
	return 0;
}
