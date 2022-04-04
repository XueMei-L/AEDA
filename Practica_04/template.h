template<class Key>

class DispersionFunction
{
private:
    /* data */
public:
    DispersionFunction(/* args */);
    ~DispersionFunction();

    // Hay que implementarlo en la subclase
    unsigned operator() {const Key& k} const = 0;
};

// DispersionFunction::DispersionFunction(/* args */)
// {
// }

// ~DispersionFunction::~DispersionFunction()
// {
// }
