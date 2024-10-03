#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef struct NodoEstructura * Nodo;
typedef void * Dato;

Nodo crearNodo(Dato d, Nodo sig);

Dato getDato(Nodo n);
void setDato(Nodo n, Dato d);

Nodo getSiguiente(Nodo n);
void setSiguiente(Nodo n, Nodo newSig);

void mostrarNodo(Nodo n);
void liberarNodo(Nodo n);
#endif // NODO_H_INCLUDED
