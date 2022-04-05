// includes
#include "dispersionFunction.h"
#include "explorationFunction.h"

#include "sequence.h"
#include "list.h"
#include "block.h"

#include <vector>
#include <iostream>

template<class Key>
class HashTable {
    private:
        int tableSize_;
        int blockSize;
        std::vector<Sequence<Key>*> vHashTable_; 
        DispersionFunction<Key>* fd_;
        ExplorationFunction<Key>* fe_;
        Sequence<Key>* ptr_seq_;

    public:
        HashTable(int, DispersionFunction<Key>*, ExplorationFunction<Key>* fe = nullptr, int blockSize = 0);
        ~HashTable();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const;
        void show() const;
};

template<class Key>
HashTable<Key>::HashTable(int tableSize, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, int blockSize) : tableSize_(tableSize) {

    if(fe == nullptr) {
        ptr_seq_ = new List<Key>();
    }

    if(fe != nullptr) {
        ptr_seq_ = new Block<Key>(blockSize);
    }

    for(int i = 0; i < tableSize;  i++) {
        vHashTable_.push_back(ptr_seq_);
    }
}

template<class Key>
HashTable<Key>::~HashTable()
{
    for(int i = 0; i < tableSize_; i++) {
        delete vHashTable_[i];
    }
}

template<class Key>
bool HashTable<Key>::search(const Key& k) const 
{
    // Buscar la posicion deberia encontrarse
    int pos = (*fd_)(k);
    if(vHashTable_[pos]->search(k)) {
        return true;
    }

    // Buscar en otra posicion (respecto a la funcion de exploracion)
    int i = 0;
    pos = ((*fd_)(k) + (*fe_)(k, i)) % tableSize_;
    i++;

    while (!vHashTable_[pos]->search(k))
    {
        pos = ((*fd_)(k) + (*fe_)(k, i)) % tableSize_;
        i++;
    }

    return true;
}

template<class Key>
bool HashTable<Key>::insert(const Key& k)
{ 
    std::cout << "Insertando...\n";
    int pos = (*fd_)(k);
    std::cout << "Clave " << k << " inseta en la pos " << pos << "\n";

    int i = 0;

    while(!vHashTable_[pos]->insert(k))
    {
        pos = ((*fd_)(k) + (*fe_)(k, i++)) % tableSize_;
        std::cout << "en la pos:" << pos << ", valor de i es:" << i << "\n";
    }
    return true; 
}

template<class Key>
void HashTable<Key>::show() const {
    for(int i = 0; i < tableSize_; i++) {
        std::cout << vHashTable_[i] << "|";
    }
    std::cout << "\n";
}