// includes
#include "dispersionFunction.h"
#include "explorationFunction.h"

#include "sequence.h"
#include "list.h"
#include "block.h"

template<class Key>
class HashTable {
    private:
        int tableSize_;
        int blockSize;
        DispersionFunction<Key>* fd_;
        ExplorationFunction<Key>* fe_;

    public:
        HashTable(int, DispersionFunction<Key>*, ExplorationFunction<Key>* fe = nullptr, int blockSize = 0);
        ~HashTable();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const;  
};

template<class Key>
HashTable<Key>::HashTable(int tableSize, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, int blockSize) : tableSize_(tableSize) {

    if(fe == nullptr) {
        Sequence<Key>* ptr_seq = new List<Key>();
    }

    if(fe != nullptr) {
        Sequence<Key>* ptr_seq = new Block<Key>(blockSize);
    }
}

template<class Key>
HashTable<Key>::~HashTable(){}

template<class Key>
bool HashTable<Key>::search(const Key& k) const { return true; }

template<class Key>
bool HashTable<Key>::insert(const Key& k){ return true; }
