#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

typedef struct ListaEstructura * Lista;

Lista crearLista();

Nodo getPrimero(Lista l);
void setPrimero(Lista l, Nodo n);

void insertarPrimero(Lista l, Dato d);
void insertarUltimo(Lista l, Dato d);
void insertarPosicion(Lista l, Dato d, int pos);

Dato obtenerPrimero(Lista l);
Dato obtenerUltimo(Lista l);
Dato obtenerPosicion(Lista l, int pos);

Dato eliminarPrimero(Lista l);
Dato eliminarUltimo(Lista l);
Dato eliminarPosicion(Lista l, int pos);

int obtenerTamanio(Lista l);

Dato buscarElemento(Lista l, Dato d, int(*funcionCallBack)(Dato,Dato));

void mostrarLista(Lista l, void(*funcionCallBack)(Dato));
#endif // LISTA_H_INCLUDED
