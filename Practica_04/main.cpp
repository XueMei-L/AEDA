//Cabecera

// includes
#include <iostream>

// programa principal
int main(int argc, char *argv[]) {

    // Preguntar el tañamo de la tabla
    int nTable;
    std::cout << "Introduzca el tamaño de la tabla:";
    std::cin >> nTable;

    // Preguntar que tipo de funcion dispersion desea
    int typeFuncDispersion;
    std::cout << "Elijas una funcion de dispersion:" 
              << "\n1. Modulo"
              << "\n2. Basada en la suma"
              << "\n3. Pseudoaleatorio"
              << "\nTu elección es:"; 
    std::cin >> typeFuncDispersion;
    
    int techniqueDispersion;
    std::cout << "Qué tecnica de dispersion desea:"
              << "\n1. Dispersion abierta"
              << "\n2. Dispersion cerrada"
              << "\nTu elección es:"; 
    std::cin >> techniqueDispersion;

    switch (techniqueDispersion)
    {
    case 1:
        /* code */
        break;
    
    case 2:
        int strategyExplo;
        std::cout << "Qué estrategia de exploración desea:"
                  << "\n1. Exploración lineal"
                  << "\n2. Exploración cuarática"
                  << "\n3. Doble dispersión"
                  << "\n4. Redispersión";
        std::cin >> strategyExplo;
        break;
    
    default:
        std::cout << "No es una opción valida, vuelva a ejecutar el programa." << std::endl;
        break;
    }

    return 0;
}