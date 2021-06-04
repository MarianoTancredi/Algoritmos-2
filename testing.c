#include "abb.h"
#include <stdio.h>
#include "string.h"

int comparador(void* elemento1, void* elemento2){
    if(!elemento1 || !elemento2)
        return 0;

    int c = *((int *)elemento1);
    int d = *((int *)elemento2);

    return c - d;
}

void destructor(void* elemento){
  free(elemento);
}

int main(){
    abb_t* arbol = arbol_crear(comparador,destructor);
    void* numero = "Hola";
    arbol_insertar(arbol,numero);
    printf("%s",(char*) arbol->nodo_raiz->elemento);

    return 0;
}