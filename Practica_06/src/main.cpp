// includes
#include<iostream>


// Generic type Key is type int
using Key = int;


int main(int argc, char *argv[]) {

    std::cout << ">> Welcome to Binary Tree program\n" 
              << ">> Wait a secund, we will genera your binary tree....\n";


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
            stop = true;
            break;
        
        case 2:
            break;
        
        case 3:
            break;
        
        default:
            // to clear console
            std::cout<< u8"\033[2J\033[1;1H"; 
            std::cout << ">> Error option, choose again with a valid option.\n";
            break;
        }
    }    
}
