#include <string.h>
#include "lib.h"



/** \brief Cerea todos los datos no usados de los vectores para que no haya basura
 *
 * \param usuarios[] eUsuario vector usuarios
 * \param cUsuarios int cantidad de usuarios cargados
 * \param productos[] eProducto vector productos
 * \param cProductos int cantidad productos cargados
 * \param publicaciones[] ePublicacion vector publicaciones
 * \param cpublicaciones int cantidad de publicaciones cargadas
 * \return void
 *
 */
void cererarDatosBasuraVectores(eUsuario usuarios[],int cUsuarios,eProducto productos[], int cProductos,ePublicacion publicaciones[], int cPublicaciones)
{
    int i;

    for (i=cUsuarios;i<QTY_PRODS;i++)
    {
        usuarios[i].idUsuario =0;
        strcpy(usuarios[i].nombre,"");
        strcpy(usuarios[i].password,"");
        usuarios[i].estado=0;
    }

    for(i=cProductos;i<QTY_USRS;i++)
    {
        productos[i].idProducto = 0;
        strcpy(productos[i].nombre , "");
    }

    for(i=cPublicaciones;i<QTY_PUBLIC;i++)
    {
        publicaciones[i].estado = 0;
        publicaciones[i].idProducto = 0;
        publicaciones[i].idUsuario=0;
        publicaciones[i].precio = 0.0;
        publicaciones[i].stock = 0;
    }
}




/** \brief Maneja el Altra del usuario verificando lugar
 *
 * \param usuarios[] eUsuario lista de usuarios
 * \return void
 *
 */
void altaDeUsuario(eUsuario usuarios[])
{
    int i, idBuscado;
    eUsuario usr;

    idBuscado = obtenerEspacioLibre(usuarios, QTY_USRS);
    if(idBuscado != -1)
    {
        usr = obtenerDatoUsuario();
        if(existeUsuario(usuarios, usr.idUsuario) == 0)
        {
                darAltaEnId(usuarios, usr, idBuscado);
                imprimirCabeceraTablaUSR();
                mostrarUsuario(usuarios[idBuscado]);
        }
        else
            infoMessage("El usuario ya existe");

    }
    else
        infoMessage("SIN ESPACIO PARA NUEVO USUARIO.");
}



/** \brief Pide los datos de un usuario por pantalla y devuelve un usuario
 *
 * \param void
 * \return eUsuario usuario cargado con todos los datos validos.
 *
 */
eUsuario obtenerDatoUsuario(void)
{
    int idUsr;
    eUsuario usuario;

    imprimirTitulo("ALTA DE USUARIO");
    usuario.idUsuario = pedirDatoNumericoValidado("ID DE USUARIO:");

    pedirRespuestaCadenaConLargo("NOMBRE: ",LONG_USR_NAME,usuario.nombre);
    //formatearNombre(auxString);
    pedirRespuestaCadenaConLargo("PASSWORD: ", LONG_PASSWORD,usuario.password);

    usuario.estado = 1;
    printf("\n");

    return usuario;
}


/** \brief Busca un usuario por su id
 *
 * \param usuarios eUsuario lista de usuarios
 * \param idUsr int id de usuario buscado
 * \return int 1- Usuario encontrado / 0 - Usuario no encontrado
 *
 */
int existeUsuario(eUsuario usuarios[],int idUsr)
{
    int i, respuesta=0;

    for(i=0;i<QTY_USRS;i++)
    {
        if(usuarios[i].estado == 1 && usuarios[i].idUsuario==idUsr)
        {
            respuesta=1;
            break;
        }
    }
    return respuesta;
}


/** \brief Asigna los valores del usuario recibido a la posicion del vector correspondiente
 *
 * \param usuarios[] eUsuario lista de usuarios
 * \param usuario eUsuario usuario cargado
 * \param id int id a guardar en el vector
 * \return void
 *
 */
void darAltaEnId(eUsuario usuarios[], eUsuario usuario, int id)
{
    usuarios[id].idUsuario = usuario.idUsuario;
    strcpy(usuarios[id].nombre,usuario.nombre);
    strcpy(usuarios[id].password,usuario.password);
    usuarios[id].estado = usuario.estado;

}



void mostrarUsuario(eUsuario usr)
{

    printf("|%10d", usr.idUsuario);
    printf("|%10s",usr.nombre);
    printf("|%12d\n",0);

}


/** \brief Imprime la cabecera de la tabla de Usuarios
 *
 * \return void
 *
 */
void imprimirCabeceraTablaUSR()
{
     int i;
    printf("|%10s", "ID   ");
    printf("|%10s","NOMBRE  ");
    printf("|%12s\n","CALIFICACION");
}


/** \brief Imprime rlos usr activos
 *
 * \param usuarios[] eUsuario lista de usarios
 * \return void
 *
 */
void imprimirUsuarios(eUsuario usuarios[])
{
    int i;

    for(i=0;i<QTY_USRS;i++)
    {
        if(usuarios[i].estado==1)
            mostrarUsuario(usuarios[i]);
    }
}



/**
 * \brief Obtiene el primer indice libre del array.
 *
 * \param eUsuario lista[] - Vector a buscar espacio libre.
 * \param int cantidada - Tamanio del vector
 * \return El indice del espacio libre.
 *
 */
int obtenerEspacioLibre(eUsuario lista[], int cantidad)
{
    int posicion=-1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 0)
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}



/**
 * \brief Obtiene el primer indice libre del array.
 *
 * \param eUsuario lista[] - Vector a buscar espacio libre.
 * \param int cantidada - Tamanio del vector
 * \return El indice del espacio libre.
 *
 */
int obtenerEspacioLibreProd(eProducto lista[], int cantidad)
{
    int posicion=-1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].idProducto == 0)
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}




/**
 * \brief Obtiene el primer indice libre del array.
 *
 * \param eUsuario lista[] - Vector a buscar espacio libre.
 * \param int cantidada - Tamanio del vector
 * \return El indice del espacio libre.
 *
 */
int obtenerEspacioLibrePubli(ePublicacion lista[], int cantidad)
{
    int posicion=-1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 0)
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}

/** \brief Ordena la Lista de personas por nombre
 *
 * \param usuarios[] eUsuario Vector de personas
 * \param tam int tamaño del vector
 * \return void
 *
 */
void ordenarListaXNombre(eUsuario usuarios[],  int tam)
{

    int i, j;
    eUsuario aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(usuarios[i].nombre, usuarios[j].nombre) == 1  )
            {
                aux = usuarios[i];
                usuarios[i]=usuarios[j];
                usuarios[j]=aux;
            }
        }
    }
}



/** \brief Pide un Nro de Usr y si existe permite modificar sus datos
 *
 * \param usuarios eUsuario vector de usuarios
 * \return void
 *
 */
void modificarDatosUsuario(eUsuario usuarios[])
{
    int i, idUsr, iPosicion;

    idUsr = pedirDatoNumericoValidado("ID DE USUARIO: ");

    iPosicion = obtenerUsuarioPorId(idUsr,usuarios);
    if(iPosicion!=-1)
    {
        imprimirCabeceraTablaUSR();
        mostrarUsuario(usuarios[iPosicion]);
        printf("\nIngrese los nuevos datos:\n");
        pedirRespuestaCadenaConLargo("NOMBRE: ",LONG_USR_NAME,usuarios[iPosicion].nombre);
        pedirRespuestaCadenaConLargo("PASSWORD: ", LONG_PASSWORD,usuarios[iPosicion].password);
    }
    else
    {
        infoMessage("EL USUARIO NO EXISTE");
    }

}


/** \brief Devuelve un la posicion del usr activo buscado por id
 *
 * \param idUsr int id Buscado
 * \param usuarios eUsuario lista de usr
 * \return int posicion encontrado
 *
 */
int obtenerUsuarioPorId(int idUsr, eUsuario usuarios[])
{
    int i, respuesta=-1;

    for(i=0;i<QTY_USRS;i++)
    {
        if(usuarios[i].estado == 1 && usuarios[i].idUsuario == idUsr)
        {
            respuesta = i;
        }
    }
    return respuesta;
}



/** \brief De de baja logica un usuario y sus publicaciones
 *
 * \param usuarios[] eUsuario
 * \param publicaciones[] ePublicacion
 * \return void
 *
 */
void bajaDeUsuario(eUsuario usuarios[],ePublicacion publicaciones[])
{
    int i, idUsr, iPosicion;
    char respuesta;

    idUsr = pedirDatoNumericoValidado("ID DE USUARIO: ");
    iPosicion = obtenerUsuarioPorId(idUsr,usuarios);
    if(iPosicion != -1)
    {
        imprimirCabeceraTablaUSR();
        mostrarUsuario(usuarios[iPosicion]);
        respuesta = pedirRespuesta("Esta seguro de eliminar este usuario y sus publicaciones?(s/n): ");
        if(respuesta == 's')
        {
            bajaDePublicacionesUsuario(usuarios[iPosicion].idUsuario, publicaciones);
            usuarios[iPosicion].estado = 0;
        }
        else
            infoMessage("El usuario NO ha sido dado de baja");

    }


}



/** \brief Da de baja las publicaciones de un usuario.
 *
 * \param idUsuario int IdUsuario
 * \param publicaciones[] ePublicacion publicaciones
 * \return void
 *
 */
void bajaDePublicacionesUsuario(int idUsuario,ePublicacion publicaciones[])
{
    int i;

    for(i=0;i<QTY_PUBLIC;i++)
    {
        if(publicaciones[i].idUsuario==idUsuario)
            publicaciones[i].estado = 0;
    }
}



/** \brief Valida todo para poder dar de alta una publicacion
 *
 * \param usuarios[] eUsuario
 * \param productos[] eProducto
 * \param publicaciones[] ePublicacion
 * \return void
 *
 */
void publicarUnProductoParaUnUsuario(eUsuario usuarios[],eProducto productos[],ePublicacion publicaciones[])
{
    int i, idUsr, iPosicion;
    char respuesta;

    idUsr = pedirDatoNumericoValidado("ID DE USUARIO: ");
    iPosicion = obtenerUsuarioPorId(idUsr,usuarios);
    if(iPosicion != -1)
    {
        imprimirCabeceraTablaUSR();
        mostrarUsuario(usuarios[iPosicion]);
        pedirDatosPublicacion(publicaciones, productos);
    }
    else
        infoMessage("El usuario no existe");

}


void pedirDatosPublicacion(ePublicacion publicaciones[],eProducto productos[], int idUsr)
{
    int i, posProd, posPubli, respuesta;
    float importe;
    char numero[50];
    ePublicacion publicacion;
    eProducto producto;

    //imprimirTitulo("ALTA PUBLICACION");
    producto.idProducto = pedirDatoNumericoValidado("ID PRODUCTO:");
    posProd = obtenerEspacioLibreProd(productos, QTY_PRODS);
    posPubli = obtenerEspacioLibrePubli(publicaciones, QTY_PUBLIC);


    if(posProd != -1 && posPubli != -1)
    {

        if(existeProducto(productos, producto.idProducto)== -1)
        {
            pedirRespuestaCadenaConLargo("NOMBRE: ",LONG_PRD_NAME,producto.nombre);
            //formatearNombre(auxString);
            publicacion.precio = pedirDatoFloatValido("PRECIO: ");

            publicacion.stock = pedirDatoNumericoValidado("STOCK: ");
            productos[posProd].idProducto = producto.idProducto;
            strcpy(productos[posProd].nombre , producto.nombre);
            publicaciones[posPubli].idProducto = producto.idProducto;
            publicaciones[posPubli].idUsuario = idUsr;
            publicaciones[posPubli].precio = publicacion.precio;
            publicaciones[posPubli].stock = publicacion.stock;
            publicaciones[posPubli].estado = 1;
            imprimirCabeceraTablaPBL();
            imprimirPublicacion(publicacion, producto);

        }else
        {
            infoMessage("El producto ya existe");
        }

    }
    else
        infoMessage("No hay lugar para una nueva publicacion");

}




int existeProducto(eProducto prods[], int idPrd)
{
    int i, buscado = -1;

    for(i=0;i<QTY_PRODS;i++)
    {
        if(prods[i].idProducto == idPrd)
        {
            buscado = 1;
            break;
        }

    }
    return buscado;
}


void imprimirCabeceraTablaPBL()
{
    printf("|%10s", "ID   ");
    printf("|%10s","NOMBRE  ");
    printf("|%10s","PRECIO");
    printf("|%5s\n","STOCK");
}


void imprimirPublicacion(ePublicacion publicacion, eProducto producto)
{
    printf("|%10d", producto.idProducto);
    printf("|%10s",producto.nombre);
    printf("|%10f",publicacion.precio);
    printf("|%5s\n",publicacion.stock);
}
