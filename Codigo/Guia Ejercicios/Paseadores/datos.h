#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#define LARGO_NAME 50
#define COLS 3
#define ANCHO_PANTA 68

void pedirDato(char mensaje[],char dato[]);

int esSoloNumero(char dato[]);

int esSoloLetras(char dato[]);

int pedirDatoNumericoValidado(char mensaje[]);

void pedirDatoSoloLetrasValido(char mensaje[], char C[]);

char pedirRespuesta(char mensaje[]);



#endif // DATOS_H_INCLUDED
