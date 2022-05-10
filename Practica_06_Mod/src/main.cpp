// includes
#include <iostream>

#include "../include/AB.h"
#include "../include/ABE.h"

// Generic type Key is type int
// using Key = int;
using Key = std::pair<int, unsigned>;
// std::pair <std::string,double> product1;


int main(int argc, char *argv[]) {
    std::cout<< u8"\033[2J\033[1;1H";
    std::cout << "=========================================\n"
              << "|     Welcome to Binary Tree program    |\n"
              << "=========================================\n"
              << ">> Wait a secund, we will genera your binary tree....\n";

    // puntero de la clase abstracta
    AB<Key>* ptr_AB;
    ptr_AB = new ABE<Key>();

    int choise;
    bool stop = false;
    while (!stop) {
        std::cout <<">> Witch operation do u wanna do?\n"
                << ">> [0] Exit\n"
                << ">> [1] Insert a key\n"
                << ">> [2] Search a key\n"
                << ">> [3] Remove a key\n"
                << ">> [4] Show binary tree in disorder\n"
                << ">> Your option is:";
        std::cin >> choise;
        switch (choise)
        {
        case 0:
            delete ptr_AB;
            std::cout << "=========================================\n"
                      << "|    Finished the Binary Tree program   |\n"
                      << "=========================================\n";
            return 0;
            break;

        case 1: {
            bool stop1 = false;
            Key value = {0 , 0};
            std::string insertAgain;
            while(!stop1) {
            
                std::cout << ">> Enter a key:";
                std::cin >> value.first;
                std::cout << ">> Enter a dato:";
                std::cin >> value.second;
                std::cout << std::endl;
                value = {value.first, value.second};
                std::cout << ">> Successfully to add value [" << value.first << value.second << "] to the Binary Tree.\n";
                ptr_AB->insert(value);
                // ptr_AB->operator[](value);
                // Llamada a la funcion de insertar
                // if(ptr_AB->insert(value)) {
                //     std::cout << ">> Successfully to add value [" << value.first << value.second << "] to the Binary Tree.\n";
                // } else {
                //     std::cout << ">> Can not add the value [" << value.first << value.second << "] to the Binary Tree.\n";
                // }
                // ptr_AB->showAB();
                std::cout << ">> Do u wanna insert more value? (y/n):";
                std::cin >> insertAgain;
                if (insertAgain == "n" || insertAgain == "N") {
                    stop1 = true;
                }
            }
        }
            break;

        case 2: {

            Key searchKey;
            std::cout << ">> Enter a key:";
            std::cin >> searchKey.first;
            std::cout << ">> Enter a dato:";
            std::cin >> searchKey.second;
            ptr_AB->operator[](searchKey);
        }
            break;

        case 3:
            // Key removeValue;
            std::cout << ">> Enter a key:";
            // std::cin >> removeValue;
            // ptr_AB->remove(removeValue);
            break;

        case 4:
            // ptr_AB->inorden();
            break;

        default:
            // to clear console
            std::cout<< u8"\033[2J\033[1;1H";
            std::cout << ">> Error option, choose again with a valid option.\n";
            break;
        }
    }
}
