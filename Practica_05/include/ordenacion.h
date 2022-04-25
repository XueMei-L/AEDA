#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>

template<class Key>
class Ordenacion {
    private:
        /* data */
    public:
        // Hay que implementarlo en la subclase
        virtual std::vector<Key> sort(const std::vector<Key>& seq, unsigned i) const = 0;
};

#endif //ORDENACION_H