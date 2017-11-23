#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#define ANCHO_PANTA 80

void pedirDato(char mensaje[],char dato[]);

int esSoloNumero(char dato[]);

int esSoloLetras(char dato[]);

int pedirDatoNumericoValidado(char mensaje[]);

void pedirDatoSoloLetrasValido(char mensaje[], char C[]);

char pedirRespuesta(char mensaje[]);

int esAlfaNumerico(char str[]);

void pedirNDato(char mensaje[],char dato[], int cant);

void limpiarSaltoDeLinea(char cadena[]);

void imprimoMenu();

void infoMessage(char message[]);

void imprimirTitulo(char titulo[]);



#endif // DATOS_H_INCLUDED
