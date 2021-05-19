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
    linked_list->nodo_fin = NULL;
    linked_list->nodo_inicio->siguiente = linked_list->nodo_fin;
    return linked_list;
    
}

int lista_insertar(lista_t* lista, void* elemento){

    if(elemento == NULL){
        return -1;
    }
    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = NULL;

    if(lista->cantidad == 0){
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_inicio->siguiente = lista->nodo_fin;
        lista->cantidad += 1;
    }

    else if(lista->cantidad == 1){
        lista->nodo_inicio->siguiente = malloc(sizeof(nodo_t));
        lista->nodo_inicio->siguiente = nuevo_nodo;
        lista->nodo_fin = nuevo_nodo->siguiente;
        lista->cantidad += 1;
    }
    else{
        while(lista->nodo_inicio->siguiente != NULL){
            if(lista->nodo_inicio->siguiente == NULL ){
                lista->nodo_inicio->siguiente = nuevo_nodo;
                lista->cantidad += 1;
                break;
            }
        }
    }

    
    return 0;

}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
    return 0;
}

int lista_borrar(lista_t* lista){
    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    return 0;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    return NULL;
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
   nodo_t* nodo = lista->nodo_fin;

   while(nodo){
       free(nodo);
       nodo = lista->nodo_fin;
   }
   
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
