#include "abb.h"
#include <stdio.h>
#include "pa2mm.h"
#include "string.h"

typedef struct clave{
    int numero;
}clave;

clave* crear_clave(int numero){
    clave* clave_nueva = (clave*)malloc(sizeof(clave));
    if(!clave_nueva){
        return NULL;
    }

    clave_nueva->numero = numero;
    return clave_nueva;
}

void crear_arbol(abb_comparador comparador, abb_liberar_elemento destructor){
  
  abb_t* arbol = arbol_crear(comparador,destructor);
  pa2m_afirmar(( arbol_crear(comparador,NULL) != NULL),"No puede crearse un arbol con un comparador NULL");
  pa2m_afirmar(( arbol_crear(NULL,destructor) == NULL),"Puede crearse un arbol con un destructor NULL");
  pa2m_afirmar(( arbol != NULL),"Se puede crear un arbol correctamente");
  pa2m_afirmar((arbol->nodo_raiz == NULL),"El arbol esta vacio");

  pa2m_nuevo_grupo("Insertar un elemento");
  clave*  numero = crear_clave(3);
  clave*  numero2 = crear_clave(6);
  clave*  numero3 = crear_clave(2);
  clave*  numero4 = crear_clave(4);
  clave*  numero5 = crear_clave(1);
  
  pa2m_afirmar((arbol_insertar(NULL,numero) == -1),"No puede insertarse en un arbol NULL");
  pa2m_afirmar((arbol_insertar(arbol,numero) == 0),"Puede insertarse un nodo");
  pa2m_afirmar((arbol_raiz(arbol) == numero),"El nodo insertado es el Nodo Raiz");
  pa2m_afirmar((arbol_insertar(arbol,numero2) == 0),"Puede insertarse un segundo nodo");
  pa2m_afirmar((arbol->nodo_raiz->derecha->elemento == numero2),"El segundo nodo esta a la derecha del primero");
  pa2m_afirmar((arbol_insertar(arbol,numero3) == 0),"Puede insertarse un tercer nodo");
  pa2m_afirmar((arbol->nodo_raiz->izquierda->elemento == numero3),"El tercer nodo esta a la izquierda del primero");
  pa2m_afirmar((arbol_insertar(arbol,numero4) == 0),"Puede insertarse un cuarto nodo");
  pa2m_afirmar((arbol_insertar(arbol,numero5) == 0),"Puede insertarse un quinto nodo");

  pa2m_nuevo_grupo("Buscar un elemento");

  pa2m_afirmar((arbol_buscar(NULL,numero) == NULL),"No puede buscarse en un arbol NULL");
  pa2m_afirmar((arbol_buscar(arbol,numero) == numero),"Puede buscarse en un arbol");
  pa2m_afirmar((arbol_buscar(arbol,numero2) == numero2),"Puede buscarse un segundo elemento en el arbol");
  pa2m_afirmar((arbol_buscar(arbol,NULL) == NULL),"Un elemento que no existe devuelve NULL");

  pa2m_nuevo_grupo("Eliminar elemento");
  
  pa2m_afirmar((arbol_borrar(NULL,numero2) == -1),"No puede eliminarse en un arbol NULL");
  pa2m_afirmar((arbol_borrar(arbol,numero2) == 0),"Se puede eliminar un Nodo");
  pa2m_afirmar((arbol_buscar(arbol,numero2) == NULL),"El elemento ya no se encuentra en el arbol");
  clave* numeros = arbol->nodo_raiz->derecha->elemento;
  printf("%d",numeros->numero);

}

int comparador(void* elemento1, void* elemento2){
    if(!elemento1 || !elemento2)
        return 0;

    clave* c1 = elemento1;
    clave* c2 = elemento2;

    return c1->numero - c2->numero;
}

void destructor(void* elemento){
  free((clave*)elemento);
}

int main(){
  pa2m_nuevo_grupo("Crear Arbol");
  crear_arbol(comparador,destructor);
  return pa2m_mostrar_reporte();
}
