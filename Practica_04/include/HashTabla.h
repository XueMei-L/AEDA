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
        int blockSize_;
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
        fd_ = fd;
        ptr_seq_ = new List<Key>();
    }

    if(fe != nullptr) {
        fd_ = fd;
        fe_ = fe;
        blockSize_ = blockSize; 
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
    int pos = fd_->operator()(k);
    if(vHashTable_[pos]->search(k)) {
        return true;
    }

    return true;
}

template<class Key>
bool HashTable<Key>::insert(const Key& k)
{ 
    std::cout << "Insertando...\n";

    //obtener la posicion con funcion de dispersion

    int pos = fd_->operator()(k);

    std::cout << "Clave: " << k << " - POS: " << pos << "\n";
    
    int i = 0;    
    //Numero de Intentos de exploracion
    //Comprobamos si hay espacio para insertar la clave
    while(!vHashTable_[pos]->insert(k))
    {
        //Aplicamos la funcion de exploracion
        pos = (fd_->operator()(k) + fe_->operator()(k,i++)) % tableSize_;
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