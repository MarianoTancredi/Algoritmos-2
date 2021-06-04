#include "abb.h"

abb_t* arbol_crear(abb_comparador comparador, abb_liberar_elemento destructor){
    if(comparador == NULL){
        return NULL;
    }
    
    abb_t* arbol = malloc((sizeof(nodo_abb_t*)+16));
    if(!arbol){
        return NULL;
    }

    arbol->nodo_raiz = NULL;
    arbol->comparador = comparador;
    arbol->destructor = destructor;
    
    return arbol;
}

int arbol_insertar(abb_t* arbol, void* elemento){
    
    if(arbol == NULL){
        return -1;
    }
    
    if (arbol->nodo_raiz == NULL){
        arbol->nodo_raiz = malloc(sizeof(nodo_abb_t));
        if(!arbol->nodo_raiz){
            return -1;
        }
        arbol->nodo_raiz->elemento = elemento;
        arbol->nodo_raiz->derecha = NULL;
        arbol->nodo_raiz->izquierda = NULL;
        return 0;
    }

    int resultado = 0;
    nodo_abb_t* temp = arbol->nodo_raiz;
    nodo_abb_t* nuevo_nodo = malloc(sizeof(nodo_abb_t));
    if(!nuevo_nodo){
            return -1;
        }
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;
    
    while(temp->derecha != NULL && temp->izquierda != NULL ){
        resultado = arbol->comparador(nuevo_nodo->elemento,temp->elemento);
        if(resultado > 0){
            temp = temp->derecha;
        }
        else if(resultado <= 0){
            temp = temp->izquierda;
        }
    }

    resultado = arbol->comparador(nuevo_nodo->elemento,temp->elemento);
    
    if(resultado > 0){
        temp->derecha = nuevo_nodo;
    }
    else if(resultado <= 0){
        temp->izquierda = nuevo_nodo;
    }
    
    return 0;
}
int arbol_borrar(abb_t* arbol, void* elemento){
    if(!arbol){
        return -1;
    }
    
    nodo_abb_t* temp = arbol->nodo_raiz;
    //De esta manera obtengo el nodo anterior
    nodo_abb_t* anterior = NULL;

    if(elemento == temp->elemento){
        arbol->nodo_raiz = temp->izquierda;
        arbol->nodo_raiz->derecha = temp->derecha;
        arbol->destructor(temp->elemento);
        return 0;
    }

    while(temp != NULL){
        int resultado = arbol->comparador(elemento,temp->elemento);
        
        if(resultado > 0){
            anterior = temp->derecha;
            temp = temp->derecha;
        }
        else if(resultado < 0){
            anterior = temp->izquierda;
            temp = temp->izquierda;
        }
        else if(resultado == 0){
            
            if (temp->izquierda == NULL) {
            anterior = temp->derecha;
            arbol->destructor(temp->elemento);
            return 0;
            
        }
            else if (temp->derecha == NULL) {
            anterior = temp->izquierda;
            arbol->destructor(temp->elemento);
            return 0;
            
        }   
            anterior = temp->izquierda;
            anterior->derecha = temp->derecha;
            arbol->destructor(temp->elemento);
            return 0;
        }

    }


    return -1;
}
void* arbol_buscar(abb_t* arbol, void* elemento){
    
    if(arbol == NULL){
        return NULL;
    }

    nodo_abb_t* temp = arbol->nodo_raiz;
    while(temp != NULL){
        int resultado = arbol->comparador(elemento,temp->elemento);
        if(resultado > 0){
            temp = temp->derecha;
        }
        else if(resultado < 0){
            temp = temp->izquierda;
        }
        else if(resultado == 0){
            return elemento;
        }

    }

    return NULL;
}
void* arbol_raiz(abb_t* arbol){
    if(arbol != NULL){
    return arbol->nodo_raiz->elemento;
    }
    return NULL;
}
bool arbol_vacio(abb_t* arbol){
    if(arbol == NULL || arbol->nodo_raiz == NULL){
        return true;
    }

    return false;
}
size_t arbol_recorrido_inorden(abb_t* arbol, void** array, size_t tamanio_array){
    return 0;
}
size_t arbol_recorrido_preorden(abb_t* arbol, void** array, size_t tamanio_array){
    return 0;
}
size_t arbol_recorrido_postorden(abb_t* arbol, void** array, size_t tamanio_array){
    return 0;
}
void arbol_destruir(abb_t* arbol){
}
size_t abb_con_cada_elemento(abb_t* arbol, int recorrido, bool (*funcion)(void*, void*), void* extra){
    return 0;
}
