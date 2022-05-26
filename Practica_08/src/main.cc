/**
 * Universidad de La Laguna
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 * 
 * @author Mario Alfonso Clavijo Mojica   
 * Compilation:
 * g++ -g main.cc -o main
 * 
 */

#include <iostream>
#include "arbolbb.h"
#include "arbolb.h"
#include "nodob.h"
#include "nodoavl.h"
#include "arbolavl.h"

int main (int argc, const char **argv) {  

  ArbolAVL<int> arbolavl;
  NodoB<int>* nodo;
  NodoAVL<int>* node;

  int opcion, clave;

  while (opcion != 0) {

  std::cout << "[0] Salir" << std::endl;
  std::cout << "[1] Insertar Clave" << std::endl;
  std::cout << "[2] Buscar Clave" << std::endl;
  std::cout << "[3] Eliminar Clave" << std::endl;  
  std::cout << "[4] Activar/Desactivar modo traza" << std::endl;
  std::cout << "Introducir una opción: ";
  std::cin >> opcion;

  switch (opcion) {

    case (0):
      break;

    case(1):
      std::cout << "Introducir el valor de Clave a Insert: ";
      std::cin >> clave;
      arbolavl.Insert(clave);
      arbolavl.Show();
      break;

    case(2):
      std::cout << "Introducir el valor de Clave a buscar: ";
      std::cin >> clave;

      node = arbolavl.Search2(clave);
      if (nodo != NULL)
        std::cout << "Sí se encuentra" << std::endl;
      else 
        std::cout << "NO se encuentra" << std::endl;
      break;

    case (3):
      std::cout << "Introducir el valor de Clave a eliminar: ";
      std::cin >> clave;
      arbolavl.Remove(clave);
      arbolavl.Show();
      break;
    
    case (4):

      arbolavl.traza = !arbolavl.traza;

      if (arbolavl.traza)
        std::cout << "Se ha activado el modo traza " << std::endl;
      else
        std::cout << "Se ha desactivado el modo traza " << std::endl;
      break;

    }

  }
  
}