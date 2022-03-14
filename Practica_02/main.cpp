#include <iostream>
#include "cell.hpp"
#include "grid.hpp"


int main(int argc, char* argv[]) {
  
  std::cout << "------------------------Game Start--------------------------\n";

  int rows, cols, turns;

  // Asks the user for the dimension
  std::cout << "Enter the number of rows, columns you want to form:";
  std::cin >> rows >> cols;

  // Asks the user for the number of turns
  std::cout << "Enter the number of turns that u want to realize:";
  std::cin >> turns;

  // Create the grid with rows and cols.
  std::cout << "------------------------Grid created------------------------\n";
  Grid* ptr_Grid = new Grid(rows, cols);

  // Ask user to insert cell with alive state (1)
  ptr_Grid->insertCellStatus();

  // Print Grid
  ptr_Grid->print();

  // printCell
  for(int i = 0; i < turns; i++) {
    std::cout << "-----------------Iteracion:" << i << "----------------\n";
    
    // update
    ptr_Grid->nextGeneration();
    
    ptr_Grid->print();
  }

  // Delete pointer
  delete ptr_Grid;
  return 0;
}
