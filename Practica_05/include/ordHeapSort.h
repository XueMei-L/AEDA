#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class HeapSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        HeapSort();
        ~HeapSort();
        // Hay que implementarlo en la subclase
        std::vector<Key> sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
HeapSort<Key>::HeapSort() {}

template<class Key>
HeapSort<Key>::~HeapSort() {}

template<class Key>
std::vector<Key> HeapSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de HeapSort...\n";
    ordenacionHeapSort(seq, i);
    for(auto value: seq) {
        std::cout << "\nValue = " << value;
    }
    return seq;
}

#endif //HEAPSORT_H