#ifndef FD_BASE
#define FD_BASE

template<class Key>
class DispersionFunction {
    public:
        DispersionFunction();
        ~DispersionFunction();
        
        unsigned operator() (const Key& k) const = 0;
};

template<class Key>
DispersionFunction<Key>::DispersionFunction():DispersionFunction(){}


template<class Key>
DispersionFunction<Key>::~DispersionFunction(){}

#endif //FD_BASE