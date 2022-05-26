/**
 ** Component: XueMei Lin
 ** Major: computer engineering
 ** Subject: Algoritmo y esturctura de datos avanzados
 ** University: University of La Laguna
 ** Programming language: c++
 */

#pragma once
#include "arbolbb.h"
#include "nodoavl.h"

template<class T>
class ArbolAVL: public ArbolBB<T>
{ 
  public:

    ArbolAVL() : ArbolBB<T>() { raiz = NULL; traza = false; }

    void Insert(const T& dato);
    void Remove(const T& dato);
    void Show();
    NodoAVL<T>* Search2(const T& dato);

    //activar traza
    bool traza;

  private: 
    NodoAVL<T>* BuscarRama2(NodoAVL<T>* nodo, const T& dato);
    void inserta_bal(NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece);
    void insert_re_balancea_izda(NodoAVL<T>* &nodo, bool& crece);
    void insert_re_balancea_dcha(NodoAVL<T>* &nodo, bool& crece);    

    void rotacion_II (NodoAVL<T>* &nodo);
    void rotacion_DD (NodoAVL<T>* &nodo);
    void rotacion_ID (NodoAVL<T>* &nodo);
    void rotacion_DI (NodoAVL<T>* &nodo);

    void elimina_rama(NodoAVL<T>* &nodo, const T& dato, bool& decrece);
    void sustituye(NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool &decrece);
    void eliminar_re_balancea_izda (NodoAVL<T>* &nodo, bool& decrece);
    void eliminar_re_balancea_dcha (NodoAVL<T>* &nodo, bool& decrece);

    NodoAVL<T>* raiz;
};

template<class T>
void 
ArbolAVL<T>::rotacion_II (NodoAVL<T>* &nodo) {
  NodoAVL<T>* nodo1 = nodo->izdo;
  nodo->izdo = nodo1->dcho;
  nodo1->dcho = nodo;
  
  if(nodo1->bal == 1) {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  else{ 
    nodo->bal = 1;
    nodo1->bal = -1;
  }

  nodo = nodo1;
}

template<class T>
void 
ArbolAVL<T>::rotacion_DD (NodoAVL<T>* &nodo) {
  NodoAVL<T>* nodo1 = nodo->dcho;
  nodo->dcho = nodo1->izdo;
  nodo1->izdo = nodo;

  if(nodo1->bal == -1) {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  else{ 
    nodo->bal = -1;
    nodo1->bal = 1;
  }
  
  nodo = nodo1; 
}

template<class T>
void 
ArbolAVL<T>::rotacion_ID (NodoAVL<T>* &nodo) {
  NodoAVL<T>* nodo1 = nodo->izdo;
  NodoAVL<T>* nodo2 = nodo1->dcho;
  nodo->izdo = nodo2->dcho;
  nodo2->dcho = nodo;
  nodo1->dcho = nodo2->izdo;
  nodo2->izdo = nodo1;
  if(nodo2->bal == -1) 
    nodo1->bal = 1;
  else
    nodo1->bal = 0;
  if(nodo2->bal == 1)
    nodo->bal = -1; 
  else
    nodo->bal = 0;
  nodo2->bal = 0;
  nodo = nodo2;
}

template<class T>
void 
ArbolAVL<T>::rotacion_DI (NodoAVL<T>* &nodo) {
  NodoAVL<T>* nodo1 = nodo->dcho;
  NodoAVL<T>* nodo2 = nodo1->izdo;
  nodo->dcho = nodo2->izdo;
  nodo2->izdo = nodo;
  nodo1->izdo = nodo2->dcho;
  nodo2->dcho = nodo1;
  if(nodo2->bal == 1) 
    nodo1->bal = -1;
  else
    nodo1->bal = 0;
  if(nodo2->bal == -1)
    nodo->bal = 1; 
  else
    nodo->bal = 0;
  nodo2->bal = 0;
  nodo = nodo2;
}

template<class T>
void 
ArbolAVL<T>::Insert(const T& dato) {
  NodoAVL<T>* nuevo = new NodoAVL<T>(dato);
  bool crece = false;
  inserta_bal(raiz, nuevo, crece); 
}

template<class T>
void 
ArbolAVL<T>::inserta_bal(NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece) {

  if(nodo == NULL) {
    nodo = nuevo;
    crece = true;
  }
  else if(nuevo->dato < nodo->dato) {
    inserta_bal(nodo->izdo,nuevo,crece);
    if(crece) 
      insert_re_balancea_izda(nodo, crece);
  }
  else {
    inserta_bal(nodo->dcho,nuevo,crece);
    if(crece) 
      insert_re_balancea_dcha(nodo, crece);
  }
}

template<class T>
void 
ArbolAVL<T>::insert_re_balancea_izda(NodoAVL<T>* &nodo, bool& crece) {

  switch(nodo->bal) {

    case -1: 
      nodo->bal = 0;
      crece = false;
      break; 

    case  0: 
      nodo->bal = 1;
      break; 
      
    case  1: 
      NodoAVL<T>* nodo1 = nodo->izdo;
      if(traza) {
        std::cout << "Desbalanceo: " << std::endl;
        Show();
      }
      if(nodo1->bal == 1) {
        rotacion_II(nodo);
        if (traza) std::cout << "Rotación II en [" << nodo->dato << "]: " << std::endl;
      }
      else {
        rotacion_ID(nodo);
        if (traza) std::cout << "Rotación ID en [" << nodo->dato << "]: " << std::endl;
      }
      crece = false;
  }

}

template<class T>
void 
ArbolAVL<T>::insert_re_balancea_dcha (NodoAVL<T>* &nodo, bool& crece) {
  
  switch(nodo->bal) {
    
    case  1: 
      nodo->bal = 0;
      crece = false;
      break; 

    case  0: 
      nodo->bal = -1;
      break; 

    case -1: 
      NodoAVL<T>* nodo1 = nodo->dcho;
      if(traza) {
        std::cout << "Desbalanceo: " << std::endl;
        Show();
      }
      if(nodo1->bal == -1) {
        rotacion_DD(nodo);
        if (traza) std::cout << "Rotación DD en [" << nodo->dato << "]: " << std::endl;
      }
      else {
        rotacion_DI(nodo);
        if (traza) std::cout << "Rotación DI en [" << nodo->dato << "]: " << std::endl;
      }
      crece = false;
  }

}

template<class T>
void 
ArbolAVL<T>::Remove(const T& dato) {
  bool decrece = false;    
  elimina_rama(raiz, dato, decrece);
}

template<class T>
void 
ArbolAVL<T>::elimina_rama(NodoAVL<T>* &nodo, const T& dato, bool& decrece) {
  if (nodo == NULL) 
    return;
  if(dato < nodo->dato) {
    elimina_rama(nodo->izdo, dato, decrece);
  if (decrece)
    eliminar_re_balancea_izda(nodo,decrece);
  }
  else if (dato > nodo->dato) {
    elimina_rama(nodo->dcho, dato, decrece);
    if (decrece)
      eliminar_re_balancea_dcha(nodo,decrece);
  }   
  else { 
    NodoAVL<T>* Eliminado = nodo;
    if(nodo->izdo == NULL) {
      nodo = nodo->dcho;
      decrece = true;
    }
    else if (nodo->dcho == NULL) {
      nodo = nodo->izdo;
      decrece = true;
    } 
    else {
      sustituye(Eliminado,nodo->izdo,decrece);
      if (decrece) 
        eliminar_re_balancea_izda(nodo,decrece);
    }
    delete Eliminado;
  }
}

template<class T>
void 
ArbolAVL<T>::sustituye(NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool &decrece) {
  if(sust->dcho != NULL) { 
      sustituye(eliminado, sust->dcho, decrece);
      if(decrece) 
        eliminar_re_balancea_dcha(sust, decrece);
  }
  else {
    eliminado->dato = sust->dato;
    eliminado = sust;
    sust = sust->izdo;
    decrece = true;
  } 
}

template<class T>
void 
ArbolAVL<T>::eliminar_re_balancea_izda (NodoAVL<T>* &nodo, bool& decrece) {
  
  NodoAVL<T>* nodo1 = nodo->dcho;

  switch(nodo->bal) {

    case -1: 
      if(nodo1->bal > 0) 
        rotacion_DI(nodo);
      else {
        if (nodo1->bal == 0)
          decrece = false;
        rotacion_DD(nodo);
      }
      break; 

    case 0: 
      nodo->bal = -1; 
      decrece = false;
      break; 
    
    case 1: 
      nodo->bal = 0;
  }
}

template<class T>
void 
ArbolAVL<T>::eliminar_re_balancea_dcha (NodoAVL<T>* &nodo, bool& decrece) {

  NodoAVL<T>* nodo1 = nodo->izdo;

  switch (nodo->bal) {

    case 1: 
      if(nodo1->bal < 0) 
        rotacion_ID(nodo);
      else {
        if(nodo1->bal == 0)
          decrece = false;
        rotacion_II(nodo);
        }
      break;

     case 0: 
      nodo->bal = 1; 
      decrece = false;
      break; 

    case -1: 
      nodo->bal = 0;

  }
}

template<class T>
void 
ArbolAVL<T>::Show() {

  std::queue<std::pair<NodoAVL<T> *, int>> Q; 

  NodoAVL<T> *nodo;
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
NodoAVL<T>* 
ArbolAVL<T>::Search2(const T& dato) { 
  return BuscarRama2(raiz, dato); 
}

template<class T>
NodoAVL<T>* 
ArbolAVL<T>::BuscarRama2(NodoAVL<T>* nodo, const T& dato) {
  
  if (nodo == NULL) 
    return NULL;
  if(dato == nodo->dato) 
    return nodo;
  if(dato < nodo->dato)
    return BuscarRama2(nodo->izdo, dato);
  return BuscarRama2(nodo->dcho, dato);

}