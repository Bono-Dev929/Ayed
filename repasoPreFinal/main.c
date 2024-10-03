#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Lista.h"
#include "Persona.h"

int* crearVector(int t);
void cargarVector(int* v, int t);
void mostrarVecor(int* v, int t);
void liberarVector(int* v);

Persona* crearVectorPersona(int t);
void cargarVectorPersona(Persona* v, int t);
void mostrarVecorPersona(Persona* v, int t);
void liberarVectorPersona(Persona* v);

int main()
{
    srand(time(0));

    Lista l = crearLista();
    Persona p1 = cargarPersona(42907294,"Lucas","Bono");
    Persona p2 = cargarPersona(11111111,"Pepito","Don");
    Persona p3 = cargarPersona(42922222,"Jose","jeje");
    Persona p6 = cargarPersona(45102294,"Martin","Palermo");
    //mostrarPersona(p1);
    insertarPrimero(l,&p1);
    insertarPrimero(l,&p2);
    insertarPrimero(l,&p3);
    mostrarLista(l, mostrarPersonaGenerico);

    mostrarPersonaGenerico(buscarElemento(l,&p6,compararPersona));

    int* vector1 = crearVector(5);

    cargarVector(vector1,5);
    mostrarVecor(vector1,5);
    liberarVector(vector1);

    Persona* pe = crearVectorPersona(5);

    cargarVectorPersona(pe,5);

    mostrarVecorPersona(pe,5);

    return 0;
}


int* crearVector(int t){
    int * vector = (int*) malloc(t*sizeof(int));
    return vector;
};
void cargarVector(int* v, int t){
    for(int i = 0; i<t ; i++){
        v[i] = rand()%10;
    }
};
void mostrarVecor(int* v,int t)
{
    printf("\n");
    for(int i =0;i<t;i++){
        printf(" %d ",v[i]);
    }
    printf("\n");
};
void liberarVector(int* v){
    free(v);
};

Persona* crearVectorPersona(int t)
{
    Persona* p = malloc(t*sizeof(Persona));
    return p;
};
void cargarVectorPersona(Persona* v, int t)
{
    for(int i =0;i<t;i++){
        v[i] = cargarPersonaTeclado();
    }
};
void mostrarVecorPersona(Persona* v, int t){
    for(int i =0;i<t;i++){
        mostrarPersona(v[i]);
    }
};
void liberarVectorPersona(Persona* v);
