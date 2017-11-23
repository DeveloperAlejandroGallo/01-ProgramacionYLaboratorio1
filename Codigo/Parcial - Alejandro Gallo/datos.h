#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#define LARGO_NAME 50
#define ANCHO_PANTA 68


void pedirDato(char mensaje[],char dato[]);

int esSoloNumero(char dato[]);

int esSoloLetras(char dato[]);

int pedirDatoNumericoValidado(char mensaje[]);

void pedirDatoSoloLetrasValido(char mensaje[], char C[]);

char pedirRespuesta(char mensaje[]);

void formatearNombre(char auxString[]);

void pedirString(char mensaje[],char dato[]);

/*****************************************************************************/
//Se que debemos poner las funciones en las librerias pero las funciones que
//devuelven float no lo devuelven correctamente al estar en librerias.
float getFloat(char mensaje[]);
float pedirDatoFloatValido(char mensaje[]);
/*******************************************************************/


//FUNC DE VISUALIZACION
void imprimoMenu();

void infoMessage(char message[]);

void imprimirTitulo(char titulo[]);



#endif // DATOS_H_INCLUDED
