#include <iostream>

class Persona
{
private:
    /* data */
    long int dni_;
    
public:
    Persona(void);
    Persona(long int dni);
    ~Persona();
};


Persona::Persona(void)
{
}

Persona::Persona(long int dni)
{
    dni_ = dni;
}

Persona::~Persona()
{

}
