// Cabecera

// includes
#include <iostream>

#include "../include/dispersionFunction.h"
#include "../include/explorationFunction.h"

#include "../include/fdModule.h"
#include "../include/fdSum.h"
#include "../include/fdPseudoaleatorio.h"

#include "../include/feLineal.h"
#include "../include/feCuadratica.h"
#include "../include/feDoble.h"
#include "../include/feReDispersion.h"

#include "../include/HashTabla.h"

#include "../include/persona.h"


// programa principal
int main(int argc, char *argv[]) {

    DispersionFunction<Persona>* ptr_fd;
    HashTable<Persona>* ptr_hashtabla;

    // Preguntar el tañamo de la tabla
    int nTable;
    std::cout << "Introduzca el tamaño de la tabla:";
    std::cin >> nTable;

    // Preguntar que tipo de funcion dispersion desea
    int typeFuncDispersion;
    std::cout << "\nElijas una funcion de dispersion:" 
              << "\n1. Modulo"
              << "\n2. Basada en la suma"
              << "\n3. Pseudoaleatorio"
              << "\nTu elección es:"; 
    std::cin >> typeFuncDispersion;


    switch (typeFuncDispersion)
    {
    case 1:
        ptr_fd = new fdModule<Persona>(nTable);
        break;
    case 2:
        ptr_fd = new fdSum<Persona>(nTable);
        break;
    case 3:
        ptr_fd = new fdPseudorandom<Persona>(nTable);
        break;
    default:
        std::cout << "No es una opción valida, vuelva a ejecutar el programa." << std::endl;
        break;
    }
        
    int techniqueDispersion;
    std::cout << "\nQué tecnica de dispersion desea:"
              << "\n1. Dispersion abierta"
              << "\n2. Dispersion cerrada"
              << "\nTu elección es:"; 
    std::cin >> techniqueDispersion;

    switch (techniqueDispersion)
    {
    case 1: 
    {
        ptr_hashtabla = new HashTable<Persona>(nTable, ptr_fd);
    }
    break;

    case 2: {

        int funcExploracion;
        std::cout << "\nQué tecnica de dispersion desea:"
                  << "\n1. Exploración Lineal"
                  << "\n2. Exploración Cuadratica"
                  << "\n3. Doble exploración"
                  << "\n4. Exploración Redispersion"
                  << "\nTu elección es:"; 
        std::cin >> funcExploracion;

        int blockSize;
        std::cout << "\nQué tamaño de bloque deseas:";
        std::cin >> blockSize;       

        ExplorationFunction<Persona>* ptr_fe;

        switch (funcExploracion)
            {
            case 1:
            {
                ptr_fe = new feLineal<Persona>();
            }
            break;
            case 2:
            {
                ptr_fe = new feCuadratica<Persona>();
            }
            break;
            case 3:
            {
                ptr_fe = new feDoble<Persona>(blockSize);
            }
            break;
            case 4:
            {
                ptr_fe = new feRedispersion<Persona>(blockSize);
            }
            default:
                std::cout << "No es una opcion correcta, vuelva a indicar" << std::endl;
                break;
            }
            ptr_hashtabla = new HashTable<Persona>(nTable, ptr_fd, ptr_fe, blockSize);

            // default:
            //     std::cout << "No es una opcion correcta, vuelva a indicar" << std::endl;
            // break;

        // break;
    }
    }

    // Menu:
    bool stop = false;
    while (stop == false)
    {
        int choise;
        std::cout << "\nQué operacion deseas realizar:"
                  << "\n1. Buscar()"
                  << "\n2. Insertar()"
                  << "\n3. Mostrar()"                  
                  << "\n4. Salir del programa"
                  << "\nTu seleccion:";
        std::cin >> choise;
        switch (choise)
        {
        case 1: 
        {
            unsigned long int k;
            std::cout << "Qué clave deseas buscar:";
            std::cin >> k;
            if(ptr_hashtabla->search(k)) {
                std::cout << "La clave " << k << " está dentro de la secuencia.";
            }else{
                std::cout << "La clave " << k << " no está dentro de la secuencia.";
            }
        }
        break;
        case 2:
        {
            unsigned long int k;
            std::cout << "Qué clave deseas insertar:";
            std::cin >> k;
            ptr_hashtabla->insert(k);
        }
        break;
        case 3:
        {
            std::cout << "----------------Mostrado la tabla Hash---------------" << std::endl;
            ptr_hashtabla->show();
        }
        break;
        case 4:
            std::cout << "----------------Terminando el programa---------------" << std::endl;
            delete ptr_fd;
            delete ptr_hashtabla;
            stop = true;
            break;
        default:
            std::cout << "No es una opcion correcta, vuelva a elegir una opcion." << std::endl;
            break;
        } 
    }
    return 0;
}