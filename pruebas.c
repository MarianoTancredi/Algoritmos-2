#include "abb.h"
#include <stdio.h>
#include "pa2mm.h"
#include "string.h"

typedef struct cosa{
    int clave;
    char contenido[10];
}cosa;

cosa* crear_clave(int clave){
    cosa* c = (cosa*)malloc(sizeof(cosa));
    if(c)
        c->clave = clave;
    return c;
}

void destruir_cosa(cosa* c){
    free(c);
}

int comparador(void* elemento1, void* elemento2){
    if(!elemento1 || !elemento2)
        return 0;

    cosa* c1 = elemento1;
    cosa* c2 = elemento2;

    return c1->clave - c2->clave;
}

void destructor(void* elemento){
    if(!elemento)
        return;
    destruir_cosa((cosa*)elemento);
}

void crear_arbol(abb_comparador comparador, abb_liberar_elemento destructor){
  
  abb_t* arbol = arbol_crear(comparador,destructor);
  pa2m_afirmar(( arbol_crear(comparador,NULL) != NULL),"No puede crearse un arbol con un comparador NULL");
  pa2m_afirmar(( arbol_crear(NULL,destructor) == NULL),"Puede crearse un arbol con un destructor NULL");
  pa2m_afirmar(( arbol != NULL),"Se puede crear un arbol correctamente");
  pa2m_afirmar((arbol->nodo_raiz == NULL),"El arbol esta vacio");

  pa2m_nuevo_grupo("Insertar un elemento");
  cosa*  numero = crear_clave(3);
  cosa*  numero2 = crear_clave(6);
  cosa*  numero3 = crear_clave(2);
  cosa*  numero4 = crear_clave(4);
  cosa*  numero5 = crear_clave(1);
  cosa*  numero6 = crear_clave(7);
  cosa*  numero7 = crear_clave(0);

  pa2m_afirmar((arbol_insertar(NULL,numero) == -1),"No puede insertarse en un arbol NULL");
  pa2m_afirmar((arbol_insertar(arbol,numero) == 0),"Puede insertarse un nodo");
  pa2m_afirmar((arbol_raiz(arbol) == numero),"El nodo insertado es el Nodo Raiz");
  pa2m_afirmar((arbol_insertar(arbol,numero2) == 0),"Puede insertarse un segundo nodo");
  pa2m_afirmar((arbol->nodo_raiz->derecha->elemento == numero2),"El segundo nodo esta a la derecha del primero");
  pa2m_afirmar((arbol_insertar(arbol,numero3) == 0),"Puede insertarse un tercer nodo");
  pa2m_afirmar((arbol->nodo_raiz->izquierda->elemento == numero3),"El tercer nodo esta a la izquierda del primero");
  pa2m_afirmar((arbol_insertar(arbol,numero4) == 0),"Puede insertarse un cuarto nodo");
  pa2m_afirmar((arbol->nodo_raiz->derecha->izquierda->elemento == numero4),"El cuarto nodo esta a la izquierda del segundo");
  pa2m_afirmar((arbol_insertar(arbol,numero5) == 0),"Puede insertarse un quinto nodo");
  pa2m_afirmar((arbol->nodo_raiz->izquierda->izquierda->elemento == numero5),"El quinto nodo esta a la izquierda del tercero");
  pa2m_afirmar((arbol_insertar(arbol,numero6) == 0),"Puedo insertar un sexto nodo");
  pa2m_afirmar((arbol->nodo_raiz->derecha->derecha->elemento == numero6),"El sextp nodo esta a la derecha del segundo");
  

  pa2m_nuevo_grupo("Buscar un elemento");

  pa2m_afirmar((arbol_buscar(NULL,numero) == NULL),"No puede buscarse en un arbol NULL");
  pa2m_afirmar((arbol_buscar(arbol,numero) == numero),"Puede buscarse en un arbol");
  pa2m_afirmar((arbol_buscar(arbol,numero2) == numero2),"Puede buscarse un segundo elemento en el arbol");
  pa2m_afirmar((arbol_buscar(arbol,NULL) == NULL),"Un elemento NULL devuelve NULL");
  pa2m_afirmar((arbol_buscar(arbol,numero7) == NULL),"Un elemento que no existe devuelve NULL");
  arbol_destruir(arbol);
}
void eliminar_elemento(abb_comparador comparador, abb_liberar_elemento destructor){
    abb_t* arbol = arbol_crear(comparador, destructor);

    cosa* numero= crear_clave(1);
    cosa* numero2= crear_clave(2);
    cosa* numero3= crear_clave(3);
    cosa* numero4= crear_clave(4);
    cosa* numero5= crear_clave(5);
    cosa* numero6= crear_clave(6);
    cosa* numero7= crear_clave(7);

    arbol_insertar(arbol, numero4);
    arbol_insertar(arbol, numero2);
    arbol_insertar(arbol, numero6);
    arbol_insertar(arbol, numero);
    arbol_insertar(arbol, numero3);
    arbol_insertar(arbol, numero5);
    arbol_insertar(arbol, numero7);



  cosa* aux = crear_clave(3);
  cosa* aux2 = crear_clave(1);
  pa2m_afirmar((arbol_borrar(NULL,numero2) == -1),"No puede eliminarse en un arbol NULL");
  pa2m_afirmar((arbol_borrar(arbol,numero4) == 0),"Se puede eliminar el Nodo raiz");
  pa2m_afirmar((arbol_raiz(arbol) == numero3),"El nodo derecho del hijo izquierdo de la raiz  es el nuevo Nodo Raiz");
  pa2m_afirmar((arbol->nodo_raiz->izquierda->elemento == numero2),"El nodo de la izquierda esta a la izquierda del nuevo Nodo Raiz");
  pa2m_afirmar((arbol->nodo_raiz->derecha->elemento == numero6),"El nodo de la derecha  esta a la derecha del nuevo Nodo Raiz");
  pa2m_afirmar((arbol_borrar(arbol,numero) == 0),"Se puede eliminar un Nodo sin hijos");
  pa2m_afirmar((arbol_buscar(arbol,aux2) == NULL),"El elemento no se encuentra mas en el arbol");
  pa2m_afirmar((arbol_borrar(arbol,numero6) == 0),"Se puede eliminar un Nodo con 2 hijos");
  pa2m_afirmar((arbol->nodo_raiz->derecha->elemento == numero5),"Su hijo izquierdo tomo su lugar");
  pa2m_afirmar((arbol->nodo_raiz->derecha->derecha->elemento == numero7),"El hijo derecho es el hijo derecho del anterior");
  pa2m_afirmar((arbol_borrar(arbol,numero3)==0),"Puedo borrar el nodo raiz de nuevo");
  pa2m_afirmar((arbol_raiz(arbol) == numero2),"El nodo de la izquierda  es el nuevo Nodo Raiz");
  pa2m_afirmar((arbol_buscar(arbol,aux) == NULL),"El elemento no se encuentra mas en el arbol");
  pa2m_afirmar((arbol_buscar(arbol,aux2) == NULL),"No puedo borrar un elemento  que no se encuentra mas en el arbol");;



}

void recorridos(abb_comparador comparador, abb_liberar_elemento destructor){
abb_t* arbol = arbol_crear(comparador,destructor);
cosa*  numero = crear_clave(3);
cosa*  numero2 = crear_clave(6);
cosa*  numero3 = crear_clave(2);
cosa*  numero4 = crear_clave(4);
cosa*  numero5 = crear_clave(1);
arbol_insertar(arbol,numero);
arbol_insertar(arbol,numero2);
arbol_insertar(arbol,numero3);
arbol_insertar(arbol,numero4);
arbol_insertar(arbol,numero5);
void** array = calloc(6,sizeof(cosa*));
void** array2 = calloc(4,sizeof(cosa*));

pa2m_nuevo_grupo("Recorrido Inorden");
pa2m_afirmar((arbol_recorrido_inorden(arbol,array,6) == 5),"Recorrido InOrder devuelve los elementos recorridos");
pa2m_afirmar((array[0] == numero5),"El primer elemento del array es el correcto");
pa2m_afirmar((array[1] == numero3),"El segundo elemento del array es el correcto");  
pa2m_afirmar((array[2] == numero),"El tercer elemento del array es el correcto");  
pa2m_afirmar((array[3] == numero4),"El cuarto elemento del array es el correcto");  
pa2m_afirmar((array[4] == numero2),"El quinto elemento del array es el correcto");
pa2m_afirmar((arbol->nodo_raiz->elemento == numero),"El primer elemento queda igual");
pa2m_afirmar((arbol->nodo_raiz->derecha->elemento == numero2),"El segundo elemento queda igual");
pa2m_afirmar((arbol->nodo_raiz->derecha->izquierda->elemento == numero4),"El tercer elemento queda igual");
pa2m_afirmar((arbol->nodo_raiz->izquierda->elemento == numero3),"El cuarto elemento queda igual");
pa2m_afirmar((arbol->nodo_raiz->izquierda->izquierda->elemento == numero5),"El quinto elemento queda igual");


pa2m_afirmar((arbol_recorrido_inorden(arbol,array2,2) == 2),"Se puede recorrer menos elementos de los necesarios");
pa2m_afirmar((array2[0] == numero5),"El primer elemento del array es el correcto");
pa2m_afirmar((array2[1] == numero3),"El segundo elemento del array es el correcto");
pa2m_afirmar((array2[2] == NULL),"El tercer elemento del array es NULL");
pa2m_afirmar((arbol_recorrido_inorden(NULL,array2,2) == 0),"No se puede recorrer un arbol NULL");    
pa2m_afirmar((arbol_recorrido_inorden(arbol,NULL,2) == 0),"No se puede recorrer con un array NULL");    
free(array);
free(array2);

pa2m_nuevo_grupo("Recorrido Preorden");

void** array3 = calloc(6,sizeof(cosa*));
void** array4 = calloc(4,sizeof(cosa*));

arbol_recorrido_preorden(arbol,array3,6);
pa2m_afirmar((array3[0] == numero),"El primer elemento del array es el correcto");
pa2m_afirmar((array3[1] == numero3),"El segundo elemento del array es el correcto");  
pa2m_afirmar((array3[2] == numero5),"El tercer elemento del array es el correcto");  
pa2m_afirmar((array3[3] == numero2),"El cuarto elemento del array es el correcto");  
pa2m_afirmar((array3[4] == numero4),"El quinto elemento del array es el correcto");
pa2m_afirmar((arbol_recorrido_preorden(arbol,array4,2) == 2),"Se puede recorrer menos elementos de los necesarios");
pa2m_afirmar((array4[0] == numero),"El primer elemento del array es el correcto");
pa2m_afirmar((array4[1] == numero3),"El segundo elemento del array es el correcto");
pa2m_afirmar((array4[2] == NULL),"El tercer elemento del array es NULL");
pa2m_afirmar((arbol_recorrido_preorden(NULL,array4,2) == 0),"No se puede recorrer un arbol NULL");    
pa2m_afirmar((arbol_recorrido_preorden(arbol,NULL,2) == 0),"No se puede recorrer con un array NULL");    

pa2m_nuevo_grupo("Recorrido Postorden");
void** array5 = calloc(6,sizeof(cosa*));
void** array6 = calloc(4,sizeof(cosa*));

pa2m_afirmar((arbol_recorrido_postorden(arbol,array,6) == 5),"Recorrido Postorden devuelve los elementos recorridos");
pa2m_afirmar((array5[0] == numero5),"El primer elemento del array es el correcto");
pa2m_afirmar((array5[1] == numero3),"El segundo elemento del array es el correcto");  
pa2m_afirmar((array5[2] == numero4),"El tercer elemento del array es el correcto");  
pa2m_afirmar((array5[3] == numero2),"El cuarto elemento del array es el correcto");  
pa2m_afirmar((array5[4] == numero),"El quinto elemento del array es el correcto");
pa2m_afirmar((arbol_recorrido_postorden(arbol,array4,2) == 2),"Se puede recorrer menos elementos de los necesarios");
pa2m_afirmar((array6[0] == numero),"El primer elemento del array es el correcto");
pa2m_afirmar((array6[1] == numero3),"El segundo elemento del array es el correcto");
pa2m_afirmar((array6[2] == NULL),"El tercer elemento del array es NULL");

}

void prueba(abb_comparador comparador, abb_liberar_elemento destructor){

abb_t* arbol = arbol_crear(comparador,destructor);
cosa*  numero = crear_clave(3);
cosa*  numero2 = crear_clave(6);
cosa*  numero3 = crear_clave(2);
cosa*  numero4 = crear_clave(4);
cosa*  numero5 = crear_clave(1);
arbol_insertar(arbol,numero);
arbol_insertar(arbol,numero2);
arbol_insertar(arbol,numero3);
arbol_insertar(arbol,numero4);
arbol_insertar(arbol,numero5);


void** array3 = calloc(6,sizeof(cosa*));
void** array4 = calloc(4,sizeof(cosa*));

arbol_recorrido_preorden(arbol,array3,6);
pa2m_afirmar((array3[0] == numero),"El primer elemento del array es el correcto");
pa2m_afirmar((array3[1] == numero3),"El segundo elemento del array es el correcto");  
pa2m_afirmar((array3[2] == numero5),"El tercer elemento del array es el correcto");  
pa2m_afirmar((array3[3] == numero2),"El cuarto elemento del array es el correcto");  
pa2m_afirmar((array3[4] == numero4),"El quinto elemento del array es el correcto");
pa2m_afirmar((arbol_recorrido_preorden(arbol,array4,2) == 2),"Se puede recorrer menos elementos de los necesarios");
pa2m_afirmar((array4[0] == numero),"El primer elemento del array es el correcto");
pa2m_afirmar((array4[1] == numero3),"El segundo elemento del array es el correcto");
pa2m_afirmar((array4[2] == NULL),"El tercer elemento del array es NULL");
pa2m_afirmar((arbol_recorrido_preorden(NULL,array4,2) == 0),"No se puede recorrer un arbol NULL");    
pa2m_afirmar((arbol_recorrido_preorden(arbol,NULL,2) == 0),"No se puede recorrer con un array NULL");    

}

int main(){
  pa2m_nuevo_grupo("Crear Arbol");
  crear_arbol(comparador,destructor);

   pa2m_nuevo_grupo("Eliminar elemento");
   eliminar_elemento(comparador,destructor);


  pa2m_nuevo_grupo("Recorrer Arbol");
  recorridos(comparador,destructor);

    pa2m_nuevo_grupo("prueba");
    prueba(comparador,destructor);

  return pa2m_mostrar_reporte();
}
