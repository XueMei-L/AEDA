#ifndef ORDENACION_H
#define ORDENACION_H

template<class Key>
class Ordenacion {
    private:
        /* data */
    public:
        // Hay que implementarlo en la subclase
        virtual unsigned sort(const Key& k, unsigned i) const = 0;
};

#endif //ORDENACION_H