#ifndef FD_BASE_H
#define FD_BASE_H

template<class Key>
class DispersionFunction {
    public:
        virtual unsigned operator() (const Key& k) const = 0;
};

#endif //FD_BASE_H