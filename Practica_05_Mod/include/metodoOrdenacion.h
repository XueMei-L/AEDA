/********************************************************************
* AUTOR: XueMei Lin
* EMAIL: alu0101225845@ull.edu.es
* UNIVERSIDAD: Universidad de La Laguna
* ASIGNATURA: Algoritmos y estructura de datos avanzadas
* VERSION: 1.0
* PRACTICA: 05
* TITUTLO: Practica 05 Ordenacion
* DESCRIPTION: Fichero que implementa distintos algoritmos
* COMPILACION: make
*              make clean (para eliminar)
* *****************************************************************/

#define X

#include <iostream>
#include <vector>

template<class Key>
void swap(Key& a, Key& b)
{
    Key aux = a;
    a = b;
    b = aux;
}

template<class Key>
void print(std::vector<Key> v)
{
    for(auto value: v) {
        std::cout << "\t" << value;
    }
}

template<class Key>
void printSwap(Key& a, Key& b)
{
    std::cout << "\t\e[34m" << a << "\e[31m <-> \e[32m" << b << std::endl;
    std::cout << "\e[0m";
}

// ----------------------- ordenacionSeleccion -------------------------
template<class Key>
void ordenacionSeleccion(std::vector<Key> sec, int n) {
    int min;
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(sec[j] < sec[min]) {
                min = j;
            }
        }

        # ifdef X
            // std::cout << "\n>>> Iteracion:" << i+1 << "-------------------------------";
            // std::cout << "\nMinimo de la subsecuencia: \e[34m" << sec[min] << std::endl;
            std::cout << "\t\e[34m" << sec[min] << "\e[31m <-> \e[32m" << sec[i] << std::endl;
            std::cout << "\e[0m";
        # endif

        //Intercambio
        swap(sec[min], sec[i]);

        # ifdef X
            print(sec);
        # endif
    }
}

// ----------------------- ordenacionQuickSort -------------------------
template<class Key>
void ordenacionQuickSort(std::vector<Key> sec, int ini, int fin) {
    int i = ini;
    int f = fin;

    // Pivote
    Key p = sec[(i+f)/2];
    Key x;

    while( i <= f ) {
        # ifdef X
            std::cout << "\tPivote:" << p;
        # endif
        // comparacion con pivote
        while (sec[i] < p) { i++; }
        while (sec[f] > p) { f--; }
        if( i <= f ) {
            # ifdef X
                printSwap(sec[i], sec[f]);
            # endif

            swap(sec[i], sec[f]);
            i++;
            f--;

        }
        # ifdef X
            print(sec);
        # endif
    }
    if( ini < f ) ordenacionQuickSort(sec, ini, f);
    if( i < fin ) ordenacionQuickSort(sec, i, fin);
}

// ----------------------- ordenacionShellSort -------------------------
template<class Key>
void deltasort(int delta, std::vector<Key>& sec, int n)
{
    for(int i = delta; i < n; i++)
    {
        Key x = sec[i];
        int j = i;
        while((j >= delta) && (x < sec[j-delta]))
        {
            sec[j] = sec[j-delta];
            j = j - delta;
        }
        sec[j] = x;
        # ifdef X
            std::cout << "\n";
            print(sec);
        # endif
    }
}

template<class Key>
void ordenacionShellSort(std::vector<Key> sec, int n, double alfa)
{
    int delta = n * alfa;
    while (delta > 1) {
        delta = delta * alfa;
        deltasort(delta, sec, n);
    } ;
}

// ----------------------- ordenacionHeapSort -------------------------
template<class Key>
void baja(int i, std::vector<Key>& sec, int n)
{
    int dad = i;
    int son = dad * 2 + 1;
    while( son <= n)
    {
        if (son + 1 <= n && sec[son] < sec[son + 1])
            son++;
        if (sec[dad] > sec[son])
            return;
        else {

            # ifdef X
                printSwap(sec[dad], sec[son]);
            # endif

            swap(sec[dad], sec[son]);
            
            # ifdef X
                print(sec);
            # endif
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template<class Key>
void ordenacionHeapSort(std::vector<Key> sec, int n) {
    // Meter valor a 
    for (int i = n/2-1; i >= 0; i--) {
        baja(i, sec, n-1);
    }
    for (int i = n-1; i > 0; i--) {

        # ifdef X
            printSwap(sec[0], sec[i]);
        # endif

        swap(sec[0], sec[i]);

        # ifdef X
            print(sec);
        # endif

        baja(0, sec, i-1);
    }
}

// ----------------------- ordenacionRadiaSort -------------------------
template<class Key>
void countSort(std::vector<Key> sec, int n, int exp) 
{ 
    int output[n]; // output array 
    int count[10] = { 0 };
    // std::vector<int> count(0, 10);
  
    // Store values in count[]
    for (int i = 0; i < n; i++) {
        // std::cout << "\n(sec[i] / exp) % 10 = " << (sec[i] / exp) % 10;
        count[(sec[i] / exp) % 10]++; 
    }
    
    // Calculating their cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Insert value to output according to the digit
    for (int i = n - 1; i >= 0; i--) { 
        output[count[(sec[i] / exp) % 10] - 1] = sec[i]; 
        count[(sec[i] / exp) % 10]--; 
    } 
  
    for (int i = 0; i < n; i++) {
        sec[i] = output[i]; 
    }

    # ifdef X
        std::cout << std::endl;
        print(sec);
    # endif
} 

template<class Key>
void ordenacionRadixSort(std::vector<Key> sec, int n) {
    // Obtener valor maximo
	int max = sec[0];
	for (int i = 1; i < n; i++)
		if (sec[i] > max)
			max = sec[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
		countSort(sec, n, exp);
}

template<class Key>
void ordenacionInsercion(std::vector<Key> sec, int n) {
        // Desde izq - derecha
        // int j;
        // for (int i = 0; i < n; ++i) {
        //         Key aux = sec[i];
        //         j = i-1;
        //         while((j >= 0) && (sec[j] > aux)) {
        //                 printSwap(sec[j+1], sec[j]);
        //                 sec[j + 1] = sec[j];
        //                 j--;
        //         }
        //         sec[j+1] = aux;
        //     # ifdef X
        //         std::cout << std::endl;
        //         print(sec);
        //     # endif
        // }

        // Desde derecha - izquierda
        int j;
        for (int i = n-1; i >= 0; --i) {
            Key aux = sec[i];
            j = i+1;
            while( j < n && sec[j] < aux) {
                sec[j - 1] = sec[j];
                j++;
            }
            sec[j-1] = aux;
            # ifdef X
                std::cout << std::endl;
                print(sec);
            # endif
        }
}