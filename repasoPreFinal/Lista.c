#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct ListaEstructura{
    Nodo primero;
};

Lista crearLista(){
    Lista l = malloc(sizeof(struct ListaEstructura));
    l->primero = NULL;
    return l;
};

Nodo getPrimero(Lista l){
    return l->primero;
};
void setPrimero(Lista l, Nodo n){
    l->primero = n;
};

void insertarPrimero(Lista l, Dato d){

    Nodo n = crearNodo(d,l->primero);
    printf("incertando al principio\n");
    l->primero = n;
};
void insertarUltimo(Lista l, Dato d) {
    Nodo ult = crearNodo(d, NULL);
    Nodo actual = l->primero;

    // Si la lista está vacía, inserta al principio
    if (actual == NULL) {
        printf("Se agrega al principio\n");
        l->primero = ult;
    } else {
        // Recorre hasta encontrar el último nodo
        while (getSiguiente(actual) != NULL) {
            printf("Buscando\n");
            actual = getSiguiente(actual);
        }
        // Conecta el último nodo con el nuevo nodo
        setSiguiente(actual, ult);
    }
}

void insertarPosicion(Lista l, Dato d, int pos) {
    if (pos < 0 || pos > obtenerTamanio(l)) {
        printf("Error: posición fuera de rango\n");
        return;  // Verifica que 'pos' esté dentro de los límites válidos
    }
    if (pos == 0) {
        insertarPrimero(l, d);  // Inserta al inicio
    } else if (pos == obtenerTamanio(l)) {
        insertarUltimo(l, d);   // Inserta al final
    } else {
        Nodo actual = l->primero;
        // Recorre hasta el nodo anterior a la posición 'pos'
        for (int i = 0; i < pos - 1; i++) {  // 'i' comienza en 0 porque asumes base-0
            actual = getSiguiente(actual);  // Avanza al siguiente nodo
        }
        // Inserta el nuevo nodo en la posición correcta
        Nodo nuevoNodo = crearNodo(d, getSiguiente(actual));  // Conectar el nuevo nodo con el siguiente
        setSiguiente(actual, nuevoNodo);  // Conectar 'actual' con el nuevo nodo
    }
}

Dato obtenerPrimero(Lista l){
    return getDato(getPrimero(l));
};
Dato obtenerUltimo(Lista l){
    Nodo aux=l->primero;
    while(getSiguiente(aux) != NULL){
        aux = getSiguiente(aux);
    };
    return getDato(aux);
};
Dato obtenerPosicion(Lista l, int pos) {
    Dato d= NULL;
    Nodo actual = l->primero;

    if (pos < 0 || pos > obtenerTamanio(l)) {
        printf("Error: posición fuera de rango.\n");
    }else{
        if(pos == 0){
            d = getDato(actual);
        }else{
            for (int i = 0; i < pos; i++) {  // Manejar posición base-1 correctamente
                actual = getSiguiente(actual);
            }

            d = getDato(actual);
        }
    }

    return d;
}

Dato eliminarPrimero(Lista l){
    Nodo aux = l->primero;
    l->primero = getSiguiente(aux);

    liberarNodo(aux);
};
Dato eliminarUltimo(Lista l){

    Nodo actual = l->primero;
    for(int i =0; i<obtenerTamanio(l)-1;i++){
        actual = getSiguiente(actual);
    }
    liberarNodo(getSiguiente(actual));
    setSiguiente(actual,NULL);


};
Dato eliminarPosicion(Lista l, int pos){

    Nodo actual = l->primero,aux;
    for(int i =0; i<pos-1;i++){
        actual = getSiguiente(actual);
    }
    aux = getSiguiente(actual);
    setSiguiente(actual,getSiguiente(aux));
    liberarNodo(aux);

};

int obtenerTamanio(Lista l){
    Nodo aux = l->primero;
    int c = 0;
    while(aux !=NULL){
        c++;
        aux = getSiguiente(aux);
    }

    return c;
};

Dato buscarElemento(Lista l, Dato d, int(*funcionCallBack)(Dato,Dato)){
    Nodo actual = l->primero;
    Dato aux = NULL;

    while(actual!= NULL && aux == NULL){
        if((*funcionCallBack)(getDato(actual),d) == 1){
            aux = getDato(actual);
            //break;
        }
        actual = getSiguiente(actual);
    }
    return aux;
};

void mostrarLista(Lista l, void(*funcionCallBack)(Dato)){
    Nodo actual = l->primero;

    printf("LISTA= \nTamanio: %d\n",obtenerTamanio(l));
    while(actual !=NULL){
        (*funcionCallBack)(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("========FIN de LISTA========\n\n");
};
