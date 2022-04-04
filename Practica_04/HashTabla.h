template<class Key>
class HashTable {
    public:
        HashTable();
        ~HashTable();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const;  
};


template<class Key>
HashTable<Key>::HashTable(){}

template<class Key>
HashTable<Key>::~HashTable(){}

template<class Key>
bool HashTable<Key>::search(const Key& k) const {}

template<class Key>
bool HashTable<Key>::insert(const Key& k){}

template<class Key>
bool HashTable<Key>::isFull() const {}
