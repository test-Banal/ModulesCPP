#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria constructor called with type: " << type << std::endl;
}

AMateria::AMateria() : _type("default")
{
    std::cout << "AMateria default constructor called" << std::endl;    
}

AMateria::AMateria(AMateria const & src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}   
AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}

