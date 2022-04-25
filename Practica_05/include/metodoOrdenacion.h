//             << "\n1. Seleccion"
//             << "\n2. QuickSort"
//             << "\n3. ShellSort"
//             << "\n3. HeapSort"
//             << "\n3. RadixSort"

// void () {
// # ifdef x
// 		cout << xxx;
// # endif
// }

#include <iostream>
#include <vector>

// FUNCIONA
// ordenacionSeleccion----------------------------------------------------
template<class Key>
void ordenacionSeleccion(std::vector<Key> sec, int n) {
    int min;
    Key x;

    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(sec[j] < sec[min]) {
                min = j;
            }
            x = sec[min];
            sec[min] = sec[i];
            sec[i] = x;
            for(auto value: sec) {
            std::cout << "\t" << value;
            }
            std::cout << "\n";
        }
    }
}
// // ordenacionSeleccion----------------------------------------------------

// // ordenacionqQuickSort----------------------------------------------------
template<class Clave>
void print(std::vector<Clave>& sec, int ini, int fin, Clave pivote)
{
    //Codigo de Colores
    //Red: 31 - Green: 32 - Blue: 34
    std::cout << " Pivote: " << pivote << "\t";
    for(int i = 0; i < sec.size(); i++)
    {
    if(i == ini)
        std::cout << "\e[34m" << sec[i] << " ";
    else if(i == fin)
        std::cout << "\e[32m" << sec[i] << " ";
    else
        std::cout << "\e[0m" << sec[i] << " ";
    std::cout << "\e[0m";
    }
    std::cout << "\n";
}

template<class Key>
std::vector<Key> ordenacionQuickSort(std::vector<Key> sec, int ini, int fin) {
    
    int i = ini;
    int f = fin;
    Key p = sec[(i+f)/2];
    Key x;

    while( i <= f){
        while (sec[i] < p) { i++; }
        while (sec[f] > p) { f--; }
        if( i <= f ){
            x = sec[i];
            sec[i] = sec[f];
            sec[f] = x;
            i++;
            f--;
        }
    }
    
    if( ini < f ) ordenacionQuickSort(sec,ini,f);
    if( i < fin ) ordenacionQuickSort(sec,i,fin);
    return sec;
}
// ordenacionqQuickSort----------------------------------------------------

// // ShellSort----------------------------------------------------
// template<class Key>
// std::vector<Key> ordenacionShellSort(std::vector<Key> sec, int n)
// {
//     std::cout << "ShellSort...";
//     int delta = n ;
//     while (delta > 1){
//         delta = delta / 2 ;
//         deltasort(delta, sec, n);
//     } ;
//     return sec;
// }

// template<class Key>
// void deltasort(int delta, std::vector<Key>& sec, int n)
// {
//     for(int i = delta; i < n; i++)
//     {
//         Key x = sec[i];
//         int j = i;
//         while((j >= delta) && (x < sec[j-delta]))
//         {
//             sec[j] = sec[j-delta];
//             j = j - delta;
//         }
//         sec[j] = x;
//     }
// }
// // ShellSort----------------------------------------------------


// // HeapSort----------------------------------------------------
template<class Key>
void swap(Key& a, Key& b)
{
    //Intercambiar valores
    Key aux = a;
    a = b;
    b = aux;
}

template<class Key>
void baja(int i, std::vector<Key>& sec, int n)
{
    int h;
    while( 2 * i <= n)
    {
        int h1 = 2 * 1;
        int h2 = h1 + 1;
        if (h1 == n) {
            h = h1;
        } else if ( sec[h1] > sec[h2] ) {
            h = h1;
        } else {
            h = h2;
        }
        if(sec[h] <= sec[i]) break;
        else {
            swap(sec[i], sec[h]);
            i = h;
        }
    }
}

template<class Key>
std::vector<Key> ordenacionHeapSort(std::vector<Key> sec, int n) {
    std::cout << "Hello World";

    for (int i = n/2-1; i >= 0; i--) {
        baja(i, sec, n);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(sec[0], sec[i]);
        baja(0, sec, i);
    }
    for(auto value: sec) {
        std::cout << "\nOrdenar HEAPSORT DENTRO Value = " << value;
    }
    
    return sec;
}

// // HeapSort----------------------------------------------------
