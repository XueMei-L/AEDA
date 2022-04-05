#ifndef EXPLORATION_FUNCTION_BASE_H
#define EXPLORATION_FUNCTION_BASE_H

template<class Key>
class ExplorationFunction  {
    private:
        /* data */
    public:
        // Hay que implementarlo en la subclase
        virtual unsigned operator() (const Key& k, unsigned i) const = 0;
};

#endif //EXPLORATION_FUNCTION_BASE_H