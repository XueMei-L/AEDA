// includes
#include <iostream>

#include "../include/AB.h"
#include "../include/ABE.h"

// Generic type Key is type int
using Key = int;


int main(int argc, char *argv[]) {
    std::cout<< u8"\033[2J\033[1;1H";
    std::cout << "=========================================\n"
              << "|     Welcome to Binary Tree program    |\n"
              << "=========================================\n"
              << ">> Wait a secund, we will genera your binary tree....\n";

    // puntero de la clase abstracta
    AB<Key>* ptr_AB;

    int choise;
    bool stop = false;
    while (!stop) {
        std::cout <<">> Witch operation do u wanna do?\n"
                << "[0] Exit\n"
                << "[1] Insert key\n"
                << "[2] Search key\n"
                << "[3] Show binary tree in disorder\n"
                << "Your option is:";
        std::cin  >> choise;
        switch (choise)
        {
        case 0:
            return 0;
            break;

        case 1:
            Key value;
            // Llamada a la funcion de insertar
            std::cout << "value:";
            std::cin >> value;
            std::cout << "key = value" << value;
            ptr_AB->insert(value);
            // ptr_AB->showAB();
            stop = true;
            break;
        case 2:
            stop = true;
            break;

        case 3:
            // ptr_AB->showAB();
            stop = true;
            break;

        default:
            // to clear console
            std::cout<< u8"\033[2J\033[1;1H";
            std::cout << ">> Error option, choose again with a valid option.\n";
            break;
        }
    }
}
