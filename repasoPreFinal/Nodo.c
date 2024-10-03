#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"

struct NodoEstructura{
    Dato dato;
    Nodo sig;
};

Nodo crearNodo(Dato d, Nodo sig){

    Nodo n = malloc(sizeof(struct NodoEstructura));

    n->dato=d;
    n->sig = sig;

    return n;
};

Dato getDato(Nodo n){
    return n->dato;
};
void setDato(Nodo n, Dato d){
    n->dato = d;
};

Nodo getSiguiente(Nodo n){
    return n->sig;
};
void setSiguiente(Nodo n, Nodo newSig){
    n->sig = newSig;
};

void mostrarNodo(Nodo n);

void liberarNodo(Nodo n){
    free(n);
};
