#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


lista_t* lista_crear(){
    // Pointer+Pointer+Size_t = 36 (Agregue 4 de padding)
    lista_t* linked_list = malloc(36);
    if(!linked_list){
        return NULL;
    }

    linked_list->cantidad = 0;
    linked_list->nodo_inicio = malloc(sizeof(nodo_t));
    linked_list->nodo_fin = malloc(sizeof(nodo_t));
    linked_list->nodo_fin->siguiente = NULL;
    return linked_list;
    
}

int lista_insertar(lista_t* lista, void* elemento){
    
    if((elemento == NULL) || (lista == NULL)){
        return -1;
    }
    
    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = NULL;
    

    if(lista->cantidad == 0){
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_fin =  lista->nodo_inicio;
        lista->nodo_fin->siguiente = NULL;
        lista->cantidad += 1;
    }


    else{
        nodo_t* temp;
        temp = lista->nodo_inicio;

        while(temp->siguiente != NULL){
            temp = temp->siguiente; 
        }
        
        temp->siguiente = nuevo_nodo;
        lista->nodo_fin = temp->siguiente;
        lista->cantidad += 1;
    }
    
    return 0;

}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){

    if((elemento == NULL) || (lista == NULL)){
        return -1;
    }

    if(lista->cantidad == 0 || (lista->cantidad) + 1 == posicion){
        lista_insertar(lista,elemento);
        return 0;
    }

    void* elemento_posicion = lista_elemento_en_posicion(lista,posicion);
    if(elemento_posicion == NULL){
        return -1;
    }

    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    nuevo_nodo->elemento = elemento;
   
    nodo_t* temp;
    temp = lista->nodo_inicio;

    while(temp->elemento != elemento_posicion){
        temp = temp->siguiente; 
    }
   
    nuevo_nodo->siguiente = temp->siguiente;
    temp->siguiente = nuevo_nodo;
    lista->cantidad += 1;
    return 0;
}

int lista_borrar(lista_t* lista){
    
    if(lista == NULL || lista->cantidad == 0){
        return -1;
    }
    
    nodo_t* temp;
    temp = lista->nodo_inicio;

    while(temp->siguiente->siguiente != NULL){
        temp = temp->siguiente; 
    }
    lista->nodo_fin = temp;
    free(temp->siguiente);
    lista->cantidad -= 1;
    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){

    if( (lista->cantidad == 0) || (lista == NULL)){
        return -1;
    }

    if((lista->cantidad) == posicion){
        lista_borrar(lista);
        return 0;
    }

    void* elemento_posicion = lista_elemento_en_posicion(lista,posicion);
    if(elemento_posicion == NULL){
        return -1;
    }
   
    nodo_t* temp;
    nodo_t* temp2;
    temp = lista->nodo_inicio;

    while(temp->siguiente->elemento != elemento_posicion){
        temp = temp->siguiente; 
    }
    
    temp2 = temp->siguiente;
    temp->siguiente = temp2->siguiente;
    free(temp2);
    lista->cantidad -= 1;
    return 0;

}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    
    if((lista == NULL) || (posicion > lista->cantidad)) {
        return NULL;
    }

    int i = 0;

    nodo_t* temp;
    temp = lista->nodo_inicio;

    while(temp->siguiente != NULL){

        if(i == posicion){
            return temp->elemento; 
        }

        temp = temp->siguiente;
        i++; 
    }

    return  temp->elemento;
}

void* lista_ultimo(lista_t* lista){
    return NULL;
}

bool lista_vacia(lista_t* lista){
    return false;
}

size_t lista_elementos(lista_t* lista){
    return 0;
}

int lista_apilar(lista_t* lista, void* elemento){
    return 0;
}

int lista_desapilar(lista_t* lista){
    return 0;
}

void* lista_tope(lista_t* lista){
    return NULL;
}

int lista_encolar(lista_t* lista, void* elemento){
    return 0;
}

int lista_desencolar(lista_t* lista){
    return 0;
}

void* lista_primero(lista_t* lista){
    return NULL;
}

void lista_destruir(lista_t* lista){

    free(lista->nodo_inicio);
    free(lista);
  
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){
        return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    return false;
}

bool lista_iterador_avanzar(lista_iterador_t* iterador){
    return false;
}

void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
    return NULL;
}

void lista_iterador_destruir(lista_iterador_t* iterador){

}

size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
    return 0;
}
