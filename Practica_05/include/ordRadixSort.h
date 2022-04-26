#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class RadixSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        RadixSort();
        ~RadixSort();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
RadixSort<Key>::RadixSort() {}

template<class Key>
RadixSort<Key>::~RadixSort() {}

template<class Key>
void RadixSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de RadixSort...\n";
    std::cout << "\nSeq: \e[31m";
        for(auto value: seq) {
            std::cout << "\t" << value;
        }
    std::cout << "\e[0m";
    ordenacionRadixSort(seq, i);
}

#endif //RADIX_SORT_H