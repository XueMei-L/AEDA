/**
 ** Component: XueMei Lin
 ** Major: computer engineering
 ** Subject: Algoritmo y esturctura de datos avanzados
 ** University: University of La Laguna
 ** Programming language: c++
 */

#pragma once
#include <algorithm>

template<class T>
class NodoAVL
{ 

  public: 
  
    NodoAVL(const T dat, NodoAVL *izq = NULL, NodoAVL *der = NULL): dato(dat), izdo(izq), dcho(der), bal(0) {}
  
    T dato;  
    NodoAVL *izdo;
    NodoAVL *dcho;
    int bal;

};

