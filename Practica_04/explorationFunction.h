#ifndef EXPLORATION_FUNCTION
#define EXPLORATION_FUNCTION

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

#endif //EXPLORATION_FUNCTION