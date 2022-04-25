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
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
HeapSort<Key>::HeapSort() {}

template<class Key>
HeapSort<Key>::~HeapSort() {}

template<class Key>
void HeapSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de HeapSort...\n";
    ordenacionHeapSort(seq, i);
}

#endif //HEAPSORT_H