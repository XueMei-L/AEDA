/**
 ** Component: XueMei Lin
 ** Major: computer engineering
 ** Subject: Algoritmo y esturctura de datos avanzados
 ** University: University of La Laguna
 ** Programming language: c++
 */

#pragma once
#include "nodob.h"
#include <queue>
#include <utility>
#include <iostream>

template<class T>
class ArbolB 
{ 
  public:

    ArbolB() : raiz(NULL) { }
    ~ArbolB() { Prune(raiz); }

    void Prune(NodoB<T>* &nodo);

    void InsertarEquil(const T& dato);

    bool Empty(NodoB<T> *nodo);
    bool Leaf(NodoB<T> *nodo);

    const int Tam();
    const int Alt();

    //Busqueda
    bool BuscarRecorrido(const T& dato);

    //Recorrido por niveles
    virtual void Show();

    NodoB<T>* get_raiz() { return raiz; }

  protected:

    NodoB<T> *raiz;

  private: 

    const int TamRama(NodoB<T>* nodo);
    const int AltN(NodoB<T>* nodo);
    bool BuscarPreorden(const T& dato, NodoB<T>* nodo);
    void InsertarEquilRama(const T& dato, NodoB<T>* nodo);

    void recorreN(NodoB<T>* nodo);

};

template<class T>
void 
ArbolB<T>::Prune(NodoB<T>* &nodo) {
  if(nodo == NULL) return;
  Prune(nodo->izdo); // Podar subarbol izquierdo
  Prune(nodo->dcho); // Podar subarbol derecho
  delete nodo;       // Eliminar nodo
  nodo = NULL;
}

template<class T>
bool 
ArbolB<T>::Leaf(NodoB<T> *nodo) { 
  return !nodo->dcho && !nodo->izdo; 
}

template<class T>
bool 
ArbolB<T>::Empty(NodoB<T> *nodo) { 
  return nodo == NULL; 
}

template<class T>
void 
ArbolB<T>::InsertarEquil(const T& dato) {
  if (raiz == NULL) 
    raiz = new NodoB<T>(dato, NULL, NULL);
  else 
    InsertarEquilRama(dato, raiz); 
}

template<class T>
void 
ArbolB<T>::InsertarEquilRama(const T& dato, NodoB<T>* nodo) {

  if(TamRama(nodo->izdo) <= TamRama(nodo->dcho)) {
    if (nodo->izdo!= NULL)
      InsertarEquilRama(dato, nodo->izdo);
    else
      nodo->izdo = new NodoB<T>(dato, NULL, NULL);
  }
  else {
    if (nodo->dcho!= NULL) 
      InsertarEquilRama(dato, nodo->dcho);
    else
      nodo->dcho = new NodoB<T>(dato, NULL, NULL);
  }
}

template<class T>
const int 
ArbolB<T>::Tam() { 
  return TamRama(raiz); 
}

template<class T>
const int 
ArbolB<T>::TamRama(NodoB<T>* nodo) {
  if(nodo == NULL) 
  return 0;
  
  return(1 + TamRama(nodo->izdo) + TamRama(nodo->dcho));
}

template<class T>
const int 
ArbolB<T>::Alt() { 
  return AltN(raiz); 
}

template<class T>
const int 
ArbolB<T>::AltN(NodoB<T>* nodo) {
  if(nodo == NULL)
    return 0 ;
  int alt_i = AltN(nodo->izdo);
  int alt_d = AltN(nodo->dcho);
  
  if(alt_d > alt_i) 
    return ++alt_d;
  else
    return ++alt_i; 
}


template<class T>
bool 
ArbolB<T>::BuscarRecorrido(const T& dato) {
  return BuscarPreorden(dato, raiz);
}

template<class T>
bool 
ArbolB<T>::BuscarPreorden(const T& dato, NodoB<T>* nodo) {

  if(nodo == NULL) 
    return false;
  if (dato == nodo->dato)
    return true;
  
  return (BuscarPreorden(dato, nodo->izdo) || BuscarPreorden(dato, nodo->dcho));

}

template<class T>
void 
ArbolB<T>::Show() {

  std::queue<std::pair<NodoB<T> *, int>> Q; 

  NodoB<T> *nodo;
  int nivel, Nivel_actual = 0;

  std::cout << "Nivel " << Nivel_actual << ": ";

  Q.push(std::make_pair(raiz, 0));

  while (!Q.empty()) {

    nodo = Q.front().first;
    nivel = Q.front().second;
    Q.pop();

    if (nivel > Nivel_actual) {
      Nivel_actual = nivel;     //Incremento de nivel
      std::cout << std::endl;
      std::cout << "Nivel " << Nivel_actual << ": ";
    }

    if(nodo != NULL) {

        std::cout << "[" << nodo->dato << "]";

      Q.push(std::make_pair(nodo->izdo, nivel+1));
      Q.push(std::make_pair(nodo->dcho, nivel+1));
    }
    else {
      std::cout << "[" << "." << "]";
    }
  }

  std::cout << std::endl;

}


template<class T>
void 
ArbolB<T>::recorreN(NodoB<T> *Raiz) {

  std::queue<std::pair<NodoB<T> *, int>> Q; 

  NodoB<T> *nodo;
  int nivel, Nivel_actual = 0;

  Q.push(std::make_pair(raiz, 0));

  while (!Q.empty()) {

    nodo = Q.front().first;
    nivel = Q.front().second;
    Q.pop();

    if (nivel > Nivel_actual)
      Nivel_actual = nivel;     //Incremento de nivel

    if(nodo != NULL) {
      Q.push(std::make_pair(nodo->izdo, nivel+1));
      Q.push(std::make_pair(nodo->dcho, nivel+1));
    }
    else {  //Subarbol vacío
    }
  }
}