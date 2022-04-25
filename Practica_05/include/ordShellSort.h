#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <vector>
#include "ordenacion.h"
// #include "MetodoOrdenacion.h"

template<class Key>
class ShellSort: public Ordenacion<Key>
{
    private:
        /* data */
    public:
        ShellSort();
        ~ShellSort();
        // Hay que implementarlo en la subclase
        void sort(const std::vector<Key>& seq, unsigned i) const;
};

template<class Key>
ShellSort<Key>::ShellSort() {}

template<class Key>
ShellSort<Key>::~ShellSort() {}

template<class Key>
void ShellSort<Key>::sort(const std::vector<Key>& seq, unsigned i) const {
    std::cout << "\nMetodo de ShellSort...\n";
    ordenacionShellSort(seq, i);
}

#endif //SHELLSORT_H