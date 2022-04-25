#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

#include "./ordenacion.h"
#include "./ordSeleccion.h"
#include "./ordQuickSort.h"
#include "./ordHeapSort.h"

template<class Key>
class Sort
{
    private:
        std::vector<Key>& _seq;
        std::vector<Key>& _seqCopy;
        int _seqSize;
        // void copyOrdSeq(std::vector<Key>&);
        // DispersionFunction<Key>* fd_;
        Ordenacion<Key>* ptr_sort_;

    public:
        Sort();
        Sort(std::vector<Key>& seq, int n);
        ~Sort();
        void SetMethod(Ordenacion<Key>*); 
        // void SetMethod(int); 
};

template<class Key>
Sort<Key>::Sort() {}

template<class Key>
Sort<Key>::Sort(std::vector<Key>& seq, int n): _seq(seq), _seqCopy(seq), _seqSize(n) {}

// template<class Key>
// void Sort<Key>::SetMethod(int option) {
//     _seqCopy = _seq;
//     for(auto value: _seqCopy) {
//         std::cout << "\nCOPIA Value = " << value;
//     }
//     // ptr_sort_ = new Seleccion<Key>();
//     // ptr_sort_->sort(_seqCopy, _seqSize);
//     ptr_sort_ = new QuickSort<Key>();
//     ptr_sort_->sort(_seqCopy, _seqSize);
    // switch (option)
    // {
    // case 1:
    //     ptr_sort_->sort(_seqCopy, _seqSize);
    //     break;
    // case 2:
    //     ptr_sort_ = new QuickSort<Key>();
    //     ptr_sort_->sort(_seqCopy, _seqSize);
    //     break;

    // default:
    //     break;
    // }
// }

template<class Key>
void Sort<Key>::SetMethod(Ordenacion<Key>* pointer) {
    _seqCopy = _seq;
    for(auto value: _seqCopy) {
        std::cout << "\nCopia = " << value;
    }
    ptr_sort_ = new Seleccion<Key>();
    ptr_sort_->sort(_seqCopy, _seqSize);

    // switch (&pointer)
    // {
    // case 
    //     ptr_sort_ = new List<Key>();
    //     break;
    
    // default:
    //     break;
    // }
}

template<class Key>
Sort<Key>::~Sort() {}

#endif //SORT_H