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
        std::vector<Sequence<Key>*> vHashTable; 
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
        vHashTable.push_back(ptr_seq_);
    }
}

template<class Key>
HashTable<Key>::~HashTable(){}

template<class Key>
bool HashTable<Key>::search(const Key& k) const { return true; }

template<class Key>
bool HashTable<Key>::insert(const Key& k){ return true; }

template<class Key>
void HashTable<Key>::show() const {
    for(int i = 0; i < tableSize_; i++) {
        std::cout << vHashTable.at(i) << "|";
    }
    std::cout << "\n";
}