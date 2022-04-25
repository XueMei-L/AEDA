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
std::vector<Key> ordenacionSeleccion(std::vector<Key> sec, int n) {
    std::cout << "Hello World";
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
        }
    }
    for(auto value: sec) {
        std::cout << "\nValue = " << value;
    }
    return sec;
}
// // ordenacionSeleccion----------------------------------------------------

// // ordenacionqQuickSort----------------------------------------------------
template<class Key>
std::vector<Key> ordenacionQuickSort(std::vector<Key>& v, int ini, int fin) {
    
    int i = ini;
    int f = fin;
    Key p = v[(i+f)/2];
    Key x;

    while( i <= f){
        while (v[i] < p) { i++; }
        while (v[f] > p) { f--; }
        if( i <= f ){
            x = v[i];
            v[i] = v[f];
            v[f] = x;
            i++;
            f--;
        }
    }
    
    if( ini < f ) ordenacionQuickSort(v,ini,f);
    if( i < fin ) ordenacionQuickSort(v,i,fin);
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
