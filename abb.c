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
    nodo_abb_t* nodo_actual = arbol->nodo_raiz;
    nodo_abb_t* nodo_anterior = nodo_actual;
    nodo_abb_t* nuevo_nodo = malloc(sizeof(nodo_abb_t));
    if(!nuevo_nodo){
            return -1;
        }
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;
    
    while(nodo_actual != NULL){
        resultado = arbol->comparador(nuevo_nodo->elemento,nodo_actual->elemento);
        nodo_anterior = nodo_actual;
        if(resultado > 0){
            nodo_actual = nodo_actual->derecha;
        }
        else if(resultado <= 0){
            nodo_actual = nodo_actual->izquierda;
        }
    }

    resultado = arbol->comparador(nuevo_nodo->elemento,nodo_anterior->elemento);
    
    if(resultado > 0){
        nodo_anterior->derecha = nuevo_nodo;
    }
    else if(resultado <= 0){
        nodo_anterior->izquierda = nuevo_nodo;
    }
    
    return 0;
}
int arbol_borrar(abb_t* arbol, void* elemento){
    if(!arbol || arbol->nodo_raiz == NULL){
        return -1;
    }

    nodo_abb_t* nodo_actual = arbol->nodo_raiz;
    nodo_abb_t* anterior = nodo_actual;
    nodo_abb_t* nodo_final_derecho = NULL;
    nodo_abb_t* nodo_aux = NULL;

    //Si el elemento es el mismo que el nodo raiz prosigo
    if(arbol->comparador(elemento,arbol->nodo_raiz->elemento) == 0){
        
        //Si los dos hijos son nulos, borro solo el nodo
        if(nodo_actual->derecha == NULL && nodo_actual->izquierda == NULL){
            arbol->destructor(nodo_actual->elemento);
            free(nodo_actual);
            return 0;
        }
        //Si solo el izquierdo es nulo, el derecho toma su lugar
        else if (nodo_actual->izquierda == NULL) {
            arbol->nodo_raiz = arbol->nodo_raiz->derecha;
            arbol->destructor(nodo_actual->elemento);
            free(nodo_actual);
            return 0;
        }
        //Si el derecho es nulo, el izquierdo lo ocupa    
        else if (nodo_actual->derecha == NULL) {
            arbol->nodo_raiz = arbol->nodo_raiz->izquierda;
            arbol->destructor(nodo_actual->elemento);
            free(nodo_actual);
            return 0;
        }
        
        //Si ningun es NULO, me muevo uno a la izquierda
        nodo_final_derecho = nodo_actual->izquierda;
        anterior = nodo_final_derecho;
        //Si el nodo derecho existe, me muevo hasta que me encuentre en el nodo  de la derecha final
        while(nodo_final_derecho != NULL && nodo_final_derecho->derecha != NULL){
            anterior = nodo_final_derecho;
            nodo_final_derecho = nodo_final_derecho->derecha;
        }
        //Si existe un hijo izquierdo al nodo de la derecha final, lo conecto al predecesor del nodo derecho
        if(nodo_final_derecho->izquierda != NULL){
            anterior->derecha = nodo_final_derecho->izquierda;
        }
        //Si no tiene hijos, lo apunto a NULL
        else if(nodo_final_derecho->izquierda == NULL){
            anterior->derecha = NULL;
        }
        

        //Si el nodo final coincide con el elemento a la izquierda de la raiz, solo enlazo el hijo derecho de la raiz
        if(arbol->nodo_raiz->izquierda == nodo_final_derecho){
            nodo_final_derecho->derecha = arbol->nodo_raiz->derecha;
        }
        //En otro caso, enlazo los dos hijos de la raiz al nuevo nodo
        else{
            nodo_final_derecho->derecha = arbol->nodo_raiz->derecha;
            nodo_final_derecho->izquierda = arbol->nodo_raiz->izquierda;
        }

        //Borro el Nodo
        arbol->nodo_raiz = nodo_final_derecho;
        arbol->destructor(nodo_actual->elemento);
        nodo_actual->elemento = NULL;
        free(nodo_actual);
        return 0;
        
    }


    int resultado;

    while(nodo_actual != NULL){
        
        resultado = arbol->comparador(elemento,nodo_actual->elemento);
        //SI el resultado es mayor, muevo el nodo actual a la derecha
        if(resultado > 0){
            anterior = nodo_actual;
            nodo_actual = nodo_actual->derecha;
        }
        //Si el resultado es menor, muevo el nodo actual a la izquierda
        else if(resultado < 0){
            anterior = nodo_actual;
            nodo_actual = nodo_actual->izquierda;
        }

        //Si el resultado igual, me quedo parado sobre este nodo
        else if(resultado == 0){
            //Realizo una funcion de comapracion mas, para saber que camino debe apuntar el predecesor del nodo a borrar
            resultado = arbol->comparador(elemento,anterior->elemento);
            
            //Si los dos hijos son nulos, borro solo el nodo
            if(nodo_actual->derecha == NULL && nodo_actual->izquierda == NULL){
                    
                    if(resultado > 0){
                        anterior->derecha = NULL;
                    }
                    else{
                        anterior->izquierda = NULL;
                    }

                    arbol->destructor(nodo_actual->elemento);
                    nodo_actual->elemento = NULL;
                    free(nodo_actual);
                    nodo_actual = NULL;
                    return 0;
            }
            

            //Si el izquierdo es Nulo, el derecho toma su lugar
            else if (nodo_actual->izquierda == NULL){
                if(resultado > 0){
                        anterior->derecha = nodo_actual->derecha;
                }
                else{
                        anterior->izquierda = nodo_actual->derecha;
                }

                arbol->destructor(nodo_actual->elemento);
                nodo_actual->elemento = NULL;
                free(nodo_actual);
                return 0;
            }
            
            //SI el derecho es Nulo, el izquierdo toma su lugar
            else if (nodo_actual->derecha == NULL) {
                if(resultado > 0){
                    anterior->derecha = nodo_actual->izquierda;
                }
                else{
                    anterior->izquierda = nodo_actual->izquierda;
                }

                arbol->destructor(nodo_actual->elemento);
                nodo_actual->elemento = NULL;
                free(nodo_actual);
                return 0;
            }
            
            //Si ningun es NULO, me muevo uno a la izquierda
            nodo_final_derecho = nodo_actual->izquierda;
            
            //Si el nodo derecho existe, me muevo hasta que me encuentre en el nodo  de la derecha final
            while( nodo_final_derecho != NULL && nodo_final_derecho->derecha != NULL){
                nodo_aux = nodo_final_derecho;
                nodo_final_derecho = nodo_final_derecho->derecha;
            }
            //Si existe un hijo izquiero al nodo de la derecha final, lo conecto al predecesor del nodo derecho
            if(nodo_final_derecho->izquierda != NULL){
                nodo_aux->derecha = nodo_final_derecho->izquierda;
            }
            

            //Si el nodo final coincide con el elemento a la izquierda del nodo a borrar, solo enlazo el hijo derecho de nodo actual
            if(nodo_actual->izquierda == nodo_final_derecho){
                nodo_final_derecho->derecha = nodo_actual->derecha;
            }
            //En otro caso, enlazo los dos hijos de la raiz al nuevo nodo
            else{
                nodo_final_derecho->derecha = nodo_actual->derecha;
                nodo_final_derecho->izquierda = nodo_actual->izquierda;
            }
            
            if(resultado > 0){
                anterior->derecha = nodo_final_derecho;
            }
            else if(resultado <= 0){
                anterior->izquierda = nodo_final_derecho;
            }

            arbol->destructor(nodo_actual->elemento);
            free(nodo_actual);
            return 0;
        }
    }

    return -1;

}
void* arbol_buscar(abb_t* arbol, void* elemento){
    
    if(arbol == NULL || !elemento){
        return NULL;
    }

    if(elemento == arbol->nodo_raiz->elemento){
        return elemento;
    }

    int resultado;
    nodo_abb_t* nodo_actual = arbol->nodo_raiz;
    while(nodo_actual != NULL){
        resultado = arbol->comparador(elemento,nodo_actual->elemento);
        
        if(resultado > 0){
            nodo_actual = nodo_actual->derecha;
        }
        else if(resultado < 0){
            nodo_actual = nodo_actual->izquierda;
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
    if(arbol == NULL || array == NULL || arbol->nodo_raiz == NULL){
        return 0;
    }

    size_t i = 0;
    abb_t* arbol2 = arbol;
    nodo_abb_t* nodo_actual = arbol2->nodo_raiz;
    nodo_abb_t* nodo_final_derecho;
    
    // Mientras el nodo en el que estoy parado sea distinto de NULL y el contador menor que al tamanio que me pasaron
    while(nodo_actual != NULL){
        
        //Si el nodo izquierdo al actual es NULLm, lo agrego al array, y muevo el nodo actual a la derecha
        if(nodo_actual->izquierda == NULL){
            if(i<tamanio_array){
            array[i] = nodo_actual->elemento;
            i++;
            }

            nodo_actual = nodo_actual->derecha;

        }

        else{
            //Me muevo uno a la izquierda, y si hay derecha, hacia el final de la derecha
            nodo_final_derecho = nodo_actual->izquierda;
            while(nodo_final_derecho->derecha != NULL && nodo_final_derecho->derecha != nodo_actual){
                nodo_final_derecho = nodo_final_derecho->derecha;
            }

            //Si ya no hay mas derecha, muevo el nodo actual a la derecha del nodo final , y el nodo actual lo cambio por su izquierda
            if(nodo_final_derecho->derecha == NULL){
                nodo_final_derecho->derecha  = nodo_actual;
                nodo_actual = nodo_actual->izquierda;
            }

            //Sino, apunto la derecha del nodo final a NULL, y guardo el elemento del nodo actual en el array, luego muevo el nodo actuala la  derecha
            else{
                nodo_final_derecho->derecha  = NULL;
                if(i<tamanio_array){
                array[i] = nodo_actual->elemento;
                i++;
                }
                nodo_actual = nodo_actual->derecha;

            } 
        } 

    }

    return i;
}

size_t arbol_recorrido_preorden(abb_t* arbol, void** array, size_t tamanio_array){
    if(arbol == NULL || array == NULL || arbol->nodo_raiz == NULL){
        return 0;
    }

    size_t i = 0;
    abb_t* arbol2 = arbol;
    nodo_abb_t* nodo_actual = arbol2->nodo_raiz;
    nodo_abb_t* nodo_final_derecho;
    
    
    // Mientras el nodo en el que estoy parado sea distinto de NULL y el contador menor que al tamanio que me pasaron
    while(nodo_actual != NULL && i<tamanio_array){
    
        //Si el nodo izquierdo al actual es NULLm, lo agrego al array, y muevo el nodo actual a la derecha
        if(nodo_actual->izquierda == NULL){
            if(i<tamanio_array){
            array[i] = nodo_actual->elemento;
            i++;
            }
            nodo_actual = nodo_actual->derecha;    
        }

        else{
            //Me muevo uno a la izquierda, y si hay derecha, hacia el final de la derecha
            nodo_final_derecho = nodo_actual->izquierda;
            while(nodo_final_derecho->derecha != NULL && nodo_final_derecho->derecha != nodo_actual){
                nodo_final_derecho = nodo_final_derecho->derecha;
            }

            //Si ya no hay mas derecha, muevo el nodo actual a la derecha del nodo final , y el nodo actual lo cambio por su izquierda
            if(nodo_final_derecho->derecha == NULL){
                nodo_final_derecho->derecha  = nodo_actual;
                nodo_actual = nodo_actual->izquierda;
            }

            //Sino, apunto la derecha del nodo final a NULL, y guardo el elemento del nodo actual en el array, luego muevo el nodo actuala la  derecha
            else{
                
                nodo_final_derecho->derecha  = NULL;
                if(i<tamanio_array){
                array[i] = nodo_actual->elemento;
                i++;
                }
                nodo_actual = nodo_actual->izquierda;
                
            } 
        } 

    }


    return i;
}

size_t arbol_recorrido_postorden(abb_t* arbol, void** array, size_t tamanio_array){
       if(arbol == NULL || array == NULL || arbol->nodo_raiz == NULL){
        return 0;
    }

    size_t i = 0;
    


    return i;
}
void arbol_destruir(abb_t* arbol){
    if(arbol){    
        free(arbol);
    }
}
size_t abb_con_cada_elemento(abb_t* arbol, int recorrido, bool (*funcion)(void*, void*), void* extra){
    return 0;
}
