#include <stdio.h>
#include <stdlib.h>
#include "datos.h"
#include "lib.h"

eUsuario usuarios[QTY_USRS] = {{1,"coco","zxcv1",1},
                                {2,"lala","zxcv1",1},
                                {3,"memo","zxcv1",1},
                                {4,"pepo","zxcv1",1},
                                {5,"noco","zxcv1",1},
                                {6,"poco","zxcv1",1},
                                {7,"relo","zxcv1",1},
                                {8,"pechi","zxcv1",1},
                                {9,"roco","zxcv1",0},
                                {10,"pepa","zxcv1",0} //10
                                };
                                    //
eProducto productos[QTY_PRODS] = {
                                    {10,"notebook"            },
                                    {20,"pc"                     },
                                    {30,"samsung galaxy" },
                                    {40,"honda cbr"         },
                                    {50,"lapicera"              },
                                    {60,"taza"                  },
                                    {70,"teclado"                },
                                    {80,"mouse"                  },
                                    {90,"pen drive 8GB"      },
                                    {100,"monitor 21"       },
                                    {110,"lcd 42"               } //11
                                    };

ePublicacion publicaciones[QTY_PUBLIC] = {{1,10  ,100,1},
                          {1,20  ,100 ,12000    ,1},
                          {1,30  ,50   ,1245      ,1},
                          {2,10  ,1     ,4567    ,1},
                          {3,40  ,15    ,999    ,1},
                          {3,50  ,25   ,7899.88     ,1},
                          {4,10  ,200  ,15245     ,1},
                          {4,100,58 ,4444        ,1},
                          {5,110,12  ,5555       ,1},
                          {6,80  ,3    ,666     ,1},
                          {6,70  ,88  ,888      ,1},
                          {7,60  ,100 ,123      ,1},
                          {8,90  ,100  ,585     ,1},
                          {9,10  ,100  ,2000     ,0} //14
                        };
int main()
{



    char seguir='s', respuesta;
    int opcion=0;
    cererarDatosBasuraVectores(usuarios, 10, productos, 11, publicaciones, 14);



    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
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
        printf("\n\n");
        if(opcion!=0)
            system("pause"); //Para q no pida 2 veces la tecla al salir
    }




}
