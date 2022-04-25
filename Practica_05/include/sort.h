#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

#include "./ordenacion.h"
#include "./ordSeleccion.h"
#include "./ordQuickSort.h"
#include "./ordHeapSort.h"
#include "./ordShellSort.h"

template<class Key>
class Sort
{
    private:
        std::vector<Key>& _seq;
        std::vector<Key>& _seqCopy;
        int _seqSize;
        Ordenacion<Key>* ptr_sort_;

    public:
        Sort();
        Sort(std::vector<Key>& seq, int n);
        ~Sort();
        void SetMethod(Ordenacion<Key>*);
        void SortSeq();
};

template<class Key>
Sort<Key>::Sort() {}

template<class Key>
Sort<Key>::Sort(std::vector<Key>& seq, int n): _seq(seq), _seqCopy(seq), _seqSize(n) {}

template<class Key>
Sort<Key>::~Sort() {}

template<class Key>
void Sort<Key>::SetMethod(Ordenacion<Key>* pointer) {
    if(ptr_sort_ == nullptr) {
        std::cout << "Null";
        ptr_sort_ = pointer;
    } else {
        std::cout << "delete";
        delete ptr_sort_;
        ptr_sort_ = pointer;
    }
}

template<class Key>
void Sort<Key>::SortSeq() {
    _seqCopy = _seq;
    ptr_sort_->sort(_seqCopy, _seqSize);
}

#endif //SORT_H