#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

struct PersonaEstructura{

    int dni;
    char nombre[20];
    char apellido[20];
};



Persona cargarPersona(int dni, char nombre[20], char apellido[20]){

    Persona p = malloc(sizeof(struct PersonaEstructura));

    p->dni = dni;
    strcpy(p->nombre, nombre);
    strcpy(p->apellido, apellido);

    return p;
}

Persona cargarPersonaTeclado(){

    char n[20],a[20];
    int dni;
    Persona p = malloc(sizeof(struct PersonaEstructura));
    printf("Ingrese su nombre: ");
    gets(p->nombre);
    printf("Ingrese su apellido: ");
    gets(p->apellido);
    printf("Ingrese su dni: ");
    scanf("%d",&p->dni);
    getchar();

    return p;
};

char* getNombre(Persona p){
    return p->nombre;
};
void setNombre(Persona p, char nombreNew[20]){
    strcpy(p->nombre, nombreNew);
}
int getDni(Persona p){
    return p->dni;
}
void setDni(Persona p, int dni){
    p->dni = dni;
}
char* getApellido(Persona p){
    return p->apellido;
};
void setApellido(Persona p, char apellidoNew[20]){
    strcpy(p->apellido,apellidoNew);
};
void mostrarPersona(Persona p){
    printf("============ Persona ============\n");
    printf("DNI: %d\n", p->dni);
    printf("Apellido: %s\n", p->apellido);
    printf("Nombre: %s\n", p->nombre);
}
void mostrarPersonaGenerico(void* dato){
    if(dato == NULL){
        printf("La persona no existe NULL");
    }else{
        Persona p = *(Persona*)dato;
        mostrarPersona(p);
    }
}
int compararPersona(void* dato, void* dato2){
    Persona p = *(Persona*)dato;
    Persona p1 = *(Persona*)dato2;
    int v=0;
    if(p==p1){
        v = 1;
    }
    return v;
};
