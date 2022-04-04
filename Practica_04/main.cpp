#include <iostream>

int main(int argc, char *argv[]) {

    int typeFuncDispersion;
    int nTable;

    std::cout << "Introduzca el tamaño de la tabla:";
    std::cin >> nTable;

    std::cout << "Elijas una funcion de dispersion:" 
              << "\n1. Modulo"
              << "\n2. Basada en la suma"
              << "\n3. Pseudoaleatorio"
              << "\nYour choice is:"; 
    std::cin >> typeFuncDispersion;
    return 0;
}