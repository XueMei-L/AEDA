#include <iostream>
#include "cell.hpp"
#include "grid.hpp"
#include "gridWithOpenBorder.hpp"
#include "gridWithPeriodicBorder.hpp"
#include "gridWithNoBorder.hpp"


int main(int argc, char* argv[]) {
  
  std::cout << "------------------------Game Start--------------------------\n";

  int rows, cols, turns;

  // Asks the user for the dimension
  std::cout << "Introduzca el numero de filas y columnas (rows, cols):";
  std::cin >> rows >> cols;

  // Asks the user for the number of turns
  std::cout << "Introduzca el numero de turno:";
  std::cin >> turns;

  // Create the grid with rows and cols.
  std::cout << "------------------------Grid created------------------------\n";
  // Punto de la clase Grid()
  Grid* ptr_grid;
  int choise;
  std::cout << "Introduzca que tipo de regilla quieres elegir:"
            << "1. Frontera periodica"
            << "2. Frontera reflectora"
            << "3. Sin fronteras";
  std::cin >> choise;
  while(choise > 0) {
    switch (choise)
    {
    case 1:
      ptr_grid = new GridWithOpenBorder();
      delete ptr_grid;
      choise = -1;
    break;
    
    case 2:
      ptr_grid = new GridWithPeriodicBorder();
      delete ptr_grid;
      choise = -1;
    break;
    
    case 3:
      ptr_grid = new GridWithNoBorder();
      delete ptr_grid;
      choise = -1;
    break;

    default:
      std::cout << "No es una opcion valida. Vuelva a elegir un tipo de regilla." << std::endl;
    break;
    }
  }

  // Ask user to insert cell with alive state (1)
  // ptr_Grid->insertCellStatus();

  // Print Grid
  // ptr_Grid->print();

  // Recorrer los turnos y Imprimir por la pantalla
  for(int i = 0; i < turns; i++) {
    std::cout << "-----------------Iteracion:" << i << "----------------\n";
    
    // update
    // ptr_Grid->nextGeneration();
    
    // ptr_Grid->print();
  }

  // Delete pointer
  delete ptr_grid;
  return 0;
}

