#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

void crea_una_lista(){
  lista_t* lista = NULL;
  pa2m_afirmar((lista = lista_crear()) != NULL,"Puedo crear una lista");

  pa2m_afirmar((lista_elementos(lista) == 0),"La lista tiene 0 elementos");
  
  free(lista);

}

void inserta_un_elemento(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  

  pa2m_afirmar((lista_insertar(lista2,elemento) == -1),"Agregar una lista NULL devuelve error");

  pa2m_afirmar((lista_insertar(lista,elemento) == 0),"Se inserto un elemento a la lista");

  pa2m_afirmar((lista_elementos(lista) == 1),"La lista tiene 1 elementos");
  
  pa2m_afirmar((lista_ultimo(lista) == elemento),"EL nodo Final es el ingresado");

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
  void* elemento6 = "Prueba6";
  void* elemento7 = "Prueba7";
  lista_insertar(lista,elemento);
  lista_insertar(lista,elemento2);
  lista_insertar(lista,elemento3);
  

  pa2m_afirmar((lista_insertar(lista2,elemento) == -1),"Agregar una lista NULL devuelve error");

  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento4,1) == 0),"El elemento se inserto correctamente");
  pa2m_afirmar((lista_elemento_en_posicion(lista,1) == elemento4), "El elemento se inserto en la posicion 1");
  pa2m_afirmar((lista_elemento_en_posicion(lista,2)== elemento2),"El elemento en la posicion 2 es el de la posicion 1");
  pa2m_afirmar((lista_ultimo(lista) == elemento3),"El nodo final sigue siendo el mismo");


  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento5,10) == 0),"Si la posicion no existe, se agrega en la posicion final");
  pa2m_afirmar((lista_ultimo(lista) == elemento5),"El Nodo final cambio");
  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento6,0) == 0),"Puede introducirse un Nodo en la posicion inicial");
  pa2m_afirmar((lista_primero(lista)==elemento6), "El nodo inicial ahora es el nuevo elemento insertado");
  pa2m_afirmar((lista->nodo_inicio->siguiente->elemento == elemento),"El siguiente a nodo inicial es el anterior");
  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento7,5)== 0),"Se puede insertar un elemento en el final");
  pa2m_afirmar((lista_ultimo(lista)==elemento5),"Se movio el Nodo final");

  lista_destruir(lista);
}

void chanutron(){
  lista_t* lista = lista_crear();
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  pa2m_afirmar((lista_insertar_en_posicion(lista,elemento,124) == 0),"Se puede insertar");
  lista_insertar(lista,elemento2);
  lista_insertar(lista,elemento3);

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
  pa2m_afirmar((lista_borrar_de_posicion(lista,12)==0), "Si la posicion no existe, se borra el ultimo lugar");
  pa2m_afirmar((lista_ultimo(lista) == elemento),"El nodo restante es el nodo final");

  lista_destruir(lista);
  lista_destruir(lista2);

}

void insertar_a_una_pila(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  
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

  lista_destruir(lista);

}

void insertar_a_una_cola(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";

  pa2m_afirmar((lista_encolar(lista2,elemento) == -1),"Agregar una lista NULL devuelve error");

  pa2m_afirmar((lista_encolar(lista,elemento) == 0),"Se puede introducir un elemento a la cola");
  lista_apilar(lista,elemento2);
  lista_apilar(lista,elemento3);
  pa2m_afirmar((lista_primero(lista) == elemento3),"El primer elemento insertado es el tope de la cola");
  pa2m_afirmar((lista_ultimo(lista) == elemento),"El ultimo elemento insertado es el final de la cola");

  pa2m_nuevo_grupo("Desencolar");

  pa2m_afirmar((lista_desencolar(lista) == 0),"Se pudo desencolar correctamente");
  pa2m_afirmar((lista_tope(lista) == elemento2 ),"El nuevo tope es el Elemento siguiente al tope anterior");
  lista_desapilar(lista);
  lista_desapilar(lista);
  pa2m_afirmar((lista_desencolar(lista) == -1),"No se puede desnecolar una lista sin elementos");
  
  lista_destruir(lista);
}

void iterar_sobre_una_lista(){
  lista_t* lista = lista_crear();
  lista_t* lista2 = NULL;
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  void* elemento3 = "Prueba3";
  lista_insertar(lista,elemento);
  lista_insertar(lista,elemento2);
  lista_insertar(lista,elemento3);

  lista_iterador_t* it = lista_iterador_crear(lista);
  lista_iterador_t* it2 = lista_iterador_crear(lista2);

  pa2m_afirmar((it2 == NULL),"No puede crearse un iterador con una lista NULL");
  pa2m_afirmar((it != NULL),"Pudo crearse un iterador correctamente con una lista de 3 elementos");
  pa2m_afirmar((lista_iterador_elemento_actual(it) == elemento),"El nodo corriente es el nodo inicial");
  pa2m_afirmar((lista_iterador_avanzar(it) == true),"Puedo avanzar el nodo corriente 1 vez");
  pa2m_afirmar((lista_iterador_avanzar(it) == true),"Puedo avanzar el nodo corriente 2 veces");
  pa2m_afirmar((lista_iterador_avanzar(it) == true),"Puedo avanzar el nodo corriente 3 veces");
  pa2m_afirmar((lista_iterador_avanzar(it) == false),"No puedo avanzar el nodo corriente 4 veces");
  pa2m_afirmar((it->corriente == NULL),"El nodo corriente actual es NULL");
  pa2m_afirmar((lista_con_cada_elemento(lista,NULL,NULL) == 0),"Una funcion NULL devuelve 0");

  lista_iterador_destruir(it);  
}

void pruebas_de_lista(){
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

  pa2m_nuevo_grupo("Chanutro");
  chanutron();
}

void pruebas_de_pila(){
  pa2m_nuevo_grupo("Pruebas de Pila");
  pa2m_nuevo_grupo("Insertar a una Pila");
  insertar_a_una_pila();

}

void pruebas_de_cola(){
  pa2m_nuevo_grupo("Pruebas de Cola");
  pa2m_nuevo_grupo("Insertar a una Cola");
  insertar_a_una_cola();

}

void pruebas_de_iterador(){
  pa2m_nuevo_grupo("Pruebas de Iterador");
  iterar_sobre_una_lista();

}
int main() {

  pruebas_de_lista();
  
  pruebas_de_pila();
  
  pruebas_de_cola();

  pruebas_de_iterador();
  
  return pa2m_mostrar_reporte();
}
