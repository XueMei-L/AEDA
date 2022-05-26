/**
 ** Component: XueMei Lin
 ** Major: computer engineering
 ** Subject: Algoritmo y esturctura de datos avanzados
 ** University: University of La Laguna
 ** Programming language: c++
 */

#pragma once
#include "arbolb.h"

template<class T>
class ArbolBB: public ArbolB<T>
{ 
  public:

    ArbolBB() : ArbolB<T>() {}

    NodoB<T>* Search(const T& dato);

    virtual void Insert(const T& dato);

  private: 

    NodoB<T>* BuscarRama(NodoB<T>* nodo, const T& dato);
    void InsertarRama(NodoB<T>* &nodo, const T& dato);

};

template<class T>
NodoB<T>* 
ArbolBB<T>::Search(const T& dato) { 
  return BuscarRama(ArbolB<T>::raiz, dato); 
}

template<class T>
NodoB<T>* 
ArbolBB<T>::BuscarRama(NodoB<T>* nodo, const T& dato) {
  
  if (nodo == NULL) 
    return NULL;
  if(dato == nodo->dato) 
    return nodo;
  if(dato < nodo->dato)
    return BuscarRama(nodo->izdo, dato);
  return BuscarRama(nodo->dcho, dato);

}

template<class T>
void 
ArbolBB<T>::Insert(const T& dato) {
  InsertarRama(ArbolB<T>::raiz, dato); 
}

template<class T>
void 
ArbolBB<T>::InsertarRama(NodoB<T>* &nodo, const T& dato) {
  if(nodo == NULL)
    nodo = new NodoB<T>(dato);
  else if(dato < nodo->dato)
    InsertarRama(nodo->izdo, dato);
  else InsertarRama(nodo->dcho, dato); 
}
