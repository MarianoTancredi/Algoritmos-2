#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


lista_t* lista_crear(){
    lista_t* linked_list = malloc(24);
    if(!linked_list){
        return NULL;
    }

    linked_list->cantidad = 0;
    linked_list->nodo_inicio = NULL;
    linked_list->nodo_fin = linked_list->nodo_inicio;
    return linked_list;
    
}

int lista_insertar(lista_t* lista, void* elemento){
    
    if(lista == NULL){
        return -1;
    }
    
    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    if(nuevo_nodo == NULL){
        return -1;
    }
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = NULL;
    

    if(lista->cantidad == 0){
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_fin = lista->nodo_inicio;
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

    if(lista == NULL){
        return -1;
    }
    

    if(((posicion == 0) && (lista->cantidad == 0))|| lista->cantidad == 0 || posicion > (lista->cantidad - 1)){
        return lista_insertar(lista,elemento);
    }

    void* elemento_posicion = lista_elemento_en_posicion(lista,posicion);
    

    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    if(nuevo_nodo == NULL ){
        return -1;
    }
    nuevo_nodo->elemento = elemento;
    
    
    nodo_t* temp;
    temp = lista->nodo_inicio;

    if(posicion == 0){
        nuevo_nodo->siguiente = temp;
        lista->nodo_inicio = nuevo_nodo;
        lista->cantidad += 1;
        return 0;
    }


    while(temp->siguiente->elemento != elemento_posicion){
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
    
    if(lista->cantidad == 1){
        free(lista->nodo_inicio);
        lista->cantidad -= 1;
        return 0;
    }

    nodo_t* temp;
    temp = lista->nodo_inicio;

    while(temp->siguiente->siguiente != NULL){
        temp = temp->siguiente; 
    }

    lista->nodo_fin = temp;
    free(temp->siguiente);
    temp->siguiente = NULL;
    lista->cantidad -= 1;
    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){

    if(lista == NULL || lista->cantidad == 0 ){
        return -1;
    }

    if(posicion >= lista->cantidad){
        return lista_borrar(lista);
    }

    if(posicion == 0){
        nodo_t* temp;
        temp = lista->nodo_inicio;
        lista->nodo_inicio = temp->siguiente;
        free(temp);
        lista->cantidad -= 1;
        return 0;
    }
    void* elemento_posicion = lista_elemento_en_posicion(lista,posicion);
    
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
    if(lista == NULL || lista->cantidad == 0 ){
    return NULL;
    }

    return lista->nodo_fin->elemento; 
}

bool lista_vacia(lista_t* lista){
    if(lista == NULL || lista->cantidad == 0){ 
    return true;
    }
    else{
        return false;
    }
}

size_t lista_elementos(lista_t* lista){
    if(lista == NULL){
        return 0;
    }
    return lista->cantidad;
}

int lista_apilar(lista_t* lista, void* elemento){
    
    if(lista == NULL){
        return -1;
    }

    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    if(nuevo_nodo == NULL){
        return -1;
    }
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = NULL;
    

    if(lista->cantidad == 0){
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_fin =  lista->nodo_inicio;
        lista->nodo_fin->siguiente = NULL;
        lista->cantidad += 1;
        return 0;
    }

    nuevo_nodo->siguiente = lista->nodo_inicio;
    lista->nodo_inicio = nuevo_nodo;
    lista->cantidad += 1;
    return 0;
}

int lista_desapilar(lista_t* lista){
    
    if(lista == NULL || lista->cantidad == 0 ){
        return -1;
    }

    nodo_t* temp;
    temp = lista->nodo_inicio;
    lista->nodo_inicio = temp->siguiente;
    free(temp);
    lista->cantidad -= 1;
    return 0;
}

void* lista_tope(lista_t* lista){
    if(lista == NULL){
        return NULL;
    }
    
    return lista->nodo_inicio->elemento;
}

int lista_encolar(lista_t* lista, void* elemento){
    return lista_insertar(lista,elemento);
}

int lista_desencolar(lista_t* lista){
    
    if(lista == NULL || lista->cantidad == 0 ){
        return -1;
    }
    
    nodo_t* temp;
    temp = lista->nodo_inicio;
    lista->nodo_inicio = temp->siguiente;
    free(temp);
    lista->cantidad -= 1;
    return 0;
}

void* lista_primero(lista_t* lista){
    if(lista == NULL || lista->cantidad == 0 ){
        return NULL;
    }
    return lista->nodo_inicio->elemento;
}

void lista_destruir(lista_t* lista){
    if(lista != NULL ){
        
        if(lista->cantidad != 0){
            nodo_t* tmp;

            while (lista->nodo_inicio != NULL)
            {
                tmp = lista->nodo_inicio;
                lista->nodo_inicio = lista->nodo_inicio->siguiente;
                free(tmp);
            }
            free(lista->nodo_inicio);
        }
        
        free(lista);
    }
    
    
}


lista_iterador_t* lista_iterador_crear(lista_t* lista){
    if(lista == NULL){
    return NULL;
    }
    lista_iterador_t* it = malloc(sizeof(lista_t) + sizeof(nodo_t));
    it->lista = lista;
    it->corriente = lista->nodo_inicio;

    return it;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    if(iterador->corriente == NULL || iterador->corriente->siguiente == NULL ){
        return false;
    }
    return true;
}

bool lista_iterador_avanzar(lista_iterador_t* iterador){
    
    if(iterador == NULL || iterador->corriente == NULL){
    return false;
    }

    iterador->corriente = iterador->corriente->siguiente;
    return true;
}

void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
    if(iterador == NULL || iterador->corriente == NULL){
    return NULL;}

    return iterador->corriente->elemento;
}

void lista_iterador_destruir(lista_iterador_t* iterador){
    if(iterador != NULL){
        free(iterador->corriente);
        lista_destruir(iterador->lista);
        free(iterador);
    }
}

size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
    bool temp = true;
    bool func = true;

    if( (*funcion) == NULL || contexto == NULL ){
        return 0;
    }

    lista_t* aux = lista;
    lista_iterador_t* iterador = lista_iterador_crear(aux);
    if(iterador == NULL){
        return 0;
    }

    size_t i = 0;
    while(temp != false || func != true){
        
        void* elemento = lista_iterador_elemento_actual(iterador); 
        i++;
        func = (*funcion)(elemento,contexto);
        temp = (lista_iterador_avanzar(iterador));

    }

    lista_iterador_destruir(iterador);
    return i;
}
