#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

typedef struct
{
    int id;
    char* nombre;
    char* email;
    char* sexo;
    char* pais;
    char* password;
    char* ip_address;
}Usuario;

void cargarArrayUsuarios(ArrayList* arrayUsuarios);

Usuario* new_Usuario(int id, char* nombre,char* email,char* sexo,char* pais,char* passw,char* ip);

int ordenPorNombre(void* usr1, void* usr2);

int ordenPorNacionalidadYNombre(void* usr1, void* usr2);

void imprimirUsuarios(ArrayList* arrayUsuarios);
#endif // USUARIOS_H_INCLUDED
