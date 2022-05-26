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
class NodoB 
{ 

  public: 
  
    NodoB(const T dat, NodoB *izq = NULL, NodoB *der = NULL): dato(dat), izdo(izq), dcho(der) {}
  
    T dato;  
    NodoB *izdo;
    NodoB *dcho;

};