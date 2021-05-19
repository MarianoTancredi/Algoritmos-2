#include "lista.h"
#include "pa2mm.h"

void crea_una_lista(){
  lista_t* lista = NULL;
  pa2m_afirmar((lista = lista_crear()) != NULL,"Puedo crear una lista");
  pa2m_afirmar(lista->nodo_inicio == NULL || lista->nodo_fin == NULL, "Sus nodos son NULL");  
  pa2m_afirmar((lista->cantidad == 0),"La lista tiene 0 elementos");
  lista_destruir(lista);
}

void inserta_un_elemento(){
  lista_t* lista = lista_crear();
  void* elemento = "Prueba";
  void* elemento2 = "Prueba2";
  pa2m_afirmar((lista_insertar(lista,elemento) == 0),"Se inserto un elemento a la lista");
  pa2m_afirmar((lista->cantidad == 1),"La lista tiene 1 elementos");
  pa2m_afirmar((lista_insertar(lista,elemento2) == 0),"Se inserto un elemento a la lista");
  pa2m_afirmar((lista->cantidad == 2),"La lista tiene 2 elementos");
  pa2m_afirmar((lista->nodo_inicio->elemento == elemento),"El primer elemento insertado es el primero de la lista")
  pa2m_afirmar((lista->nodo_fin->elemento == elemento2),"El segundo elemento insertado es el ultimo de la lista")
  lista_destruir(lista);
}

int main() {
  pa2m_nuevo_grupo("Hace las pruebas");

  pa2m_nuevo_grupo("Crea una lista");
  crea_una_lista();

  pa2m_nuevo_grupo("Inserta un elemento");
  inserta_un_elemento();


  return pa2m_mostrar_reporte();
}
