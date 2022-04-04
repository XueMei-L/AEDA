#ifndef EXPLORATION_FUNCTION_BASE
#define EXPLORATION_FUNCTION_BASE

template<class Key>
class ExplorationFunction
{
private:
    /* data */
public:
    ExplorationFunction();
    ~ExplorationFunction();

    // Hay que implementarlo en la subclase
    unsigned operator() {const Key& k, unsigned i} const = 0;
};

#endif //EXPLORATION_FUNCTION_BASE