#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

void crea_una_lista(){
  lista_t* lista = NULL;
  pa2m_afirmar((lista = lista_crear()) != NULL,"Puedo crear una lista");

  pa2m_afirmar((lista->nodo_fin->siguiente == NULL),"El elemento siguiente al Nodo final es NULL");  
  pa2m_afirmar((lista_elementos(lista) == 0),"La lista tiene 0 elementos");
  lista_destruir(lista);
}

void inserta_un_elemento(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  
  pa2m_afirmar((lista_insertar(lista,NULL) == -1),"Agregar un elemento NULL devuelve error");

  pa2m_afirmar((lista_insertar(lista2,elemento) == -1),"Agregar una lista NULL devuelve error");

  pa2m_afirmar((lista_insertar(lista,elemento) == 0),"Se inserto un elemento a la lista");

  pa2m_afirmar((lista_elementos(lista) == 1),"La lista tiene 1 elementos");

  pa2m_afirmar((lista_insertar(lista,elemento2) == 0),"Se inserto un elemento a la lista");

  pa2m_afirmar((lista_elementos(lista) == 2),"La lista tiene 2 elementos");
  
  pa2m_afirmar((lista_insertar(lista,elemento3) == 0),"Se inserto un elemento a la lista");

  pa2m_afirmar((lista_primero(lista) == elemento),"El primer elemento insertado es el Nodo inicial");
  
  pa2m_afirmar((lista_elemento_en_posicion(lista,1) == elemento2),"El segundo elemento insertado es el segundo de la lista");
  
  pa2m_afirmar((lista_elemento_en_posicion(lista,2)== elemento3),"El tercer elemento insertado es el tercero de la lista");

  pa2m_afirmar((lista_ultimo(lista) == elemento3),"El tercer elemento insertado es el Nodo final");

  pa2m_afirmar((lista->nodo_fin->siguiente == NULL),"El elemento que sigue al Nodo final es NULL");

  lista_destruir(lista);
}

void buscar_posicion(){
  lista_t* lista = lista_crear();
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  lista_insertar(lista,elemento);
  lista_insertar(lista,elemento2);
  lista_insertar(lista,elemento3);

  pa2m_afirmar((lista_elemento_en_posicion(lista,4) == NULL),"Si la posicion no se encuentra devuelve NULL");
  
  pa2m_afirmar((lista_elemento_en_posicion(lista,0) == elemento),"La posicion 0 devuelve el elemento insertado primero");
  
  pa2m_afirmar((lista_elemento_en_posicion(lista,1) == elemento2),"La posicion 1 devuelve el elemento insertado segundo");

  pa2m_afirmar((lista_elemento_en_posicion(lista,2) == elemento3),"La posicion 2 devuelve el elemento insertado tercero");

  lista_destruir(lista);
}

void inserta_un_elemento_indicado(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  void* elemento4 = "Prueba4";
  void* elemento5 = "Prueba5";
  lista_insertar(lista,elemento);
  lista_insertar(lista,elemento2);
  lista_insertar(lista,elemento3);
  
  pa2m_afirmar((lista_insertar(lista,NULL) == -1),"Agregar un elemento NULL devuelve error");

  pa2m_afirmar((lista_insertar(lista2,elemento) == -1),"Agregar una lista NULL devuelve error");

  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento4,1) == 0),"El elemento se inserto correctamente");
  pa2m_afirmar((lista_elemento_en_posicion(lista,2) == elemento4), "El elemento se inserto en la posicion 2");
  pa2m_afirmar((lista_ultimo(lista) == elemento3),"El nodo final sigue siendo el mismo");


  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento5,5) == 0),"Se puede agregar un elemento en la posicion final");
  pa2m_afirmar((lista_ultimo(lista) == elemento5),"El Nodo final cambio");

  lista_destruir(lista);
}

void borrar_elemento(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = lista_crear();
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  lista_insertar(lista,elemento);
  lista_insertar(lista,elemento2);
  lista_insertar(lista,elemento3);

  pa2m_afirmar((lista_borrar(lista) == 0),"El elemento se borro correctamente");
  pa2m_afirmar((lista_elementos(lista) == 2),"La cantidad de elementos se redujo en 1");
  pa2m_afirmar((lista_ultimo(lista) == elemento2),"El Nodo final es el elemento previo al que se borro");
  pa2m_afirmar((lista_borrar(lista2) == -1),"No se puede borrar una lista sin elementos");
  
  void* elemento4 = "Prueba3";
  lista_insertar(lista,elemento4);
  
  pa2m_afirmar((lista_borrar_de_posicion(lista,1)==0), "Se puede borrar el elemento en la posicion 1");
  pa2m_afirmar((lista_elemento_en_posicion(lista,1) == elemento4),"El Nodo siguiente tomo su lugar");
  pa2m_afirmar((lista_ultimo(lista) == elemento4),"El nodo siguiente sigue siendo el Nodo final");

  

}

void insertar_a_una_pila(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  
  pa2m_afirmar((lista_apilar(lista,NULL) == -1),"Agregar un elemento NULL devuelve error");
  pa2m_afirmar((lista_apilar(lista2,elemento) == -1),"Agregar una lista NULL devuelve error");

  pa2m_afirmar((lista_apilar(lista,elemento) == 0),"Se puede introducir un elemento a la pila");
  lista_apilar(lista,elemento2);
  lista_apilar(lista,elemento3);
  pa2m_afirmar((lista_primero(lista) == elemento3),"El ultimo elemento insertado es el tope de la pila");
  pa2m_afirmar((lista_ultimo(lista) == elemento),"El primer elemento insertado es el final de la pila");
  
  pa2m_nuevo_grupo("Desapilar");

  pa2m_afirmar((lista_desapilar(lista) == 0),"Se pudo desapilar correctamente");
  pa2m_afirmar((lista_tope(lista) == elemento2 ),"El nuevo tope es el Elemento siguiente al tope anterior");
  lista_desapilar(lista);
  lista_desapilar(lista);
  pa2m_afirmar((lista_desapilar(lista) == -1),"No se puede desapilar una lista sin elementos");

  free(lista);

}



int main() {
  pa2m_nuevo_grupo("Hace las pruebas");

  pa2m_nuevo_grupo("Crea una lista");
  crea_una_lista();

  pa2m_nuevo_grupo("Inserta un elemento");
  inserta_un_elemento();

  pa2m_nuevo_grupo("Buscar posicion");
  buscar_posicion();

  pa2m_nuevo_grupo("Insertar elemento en la posicion indicada");
  inserta_un_elemento_indicado();

  pa2m_nuevo_grupo("Borrar elemento");
  borrar_elemento();

  pa2m_nuevo_grupo("Pruebas de Pila");
  
  pa2m_nuevo_grupo("Insertar a una Pila");
  insertar_a_una_pila();
  return pa2m_mostrar_reporte();
}
