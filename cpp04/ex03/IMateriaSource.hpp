#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class AMateria;
class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual AMateria* createMateria(std::string const & type) = 0;
    virtual void learnMateria(AMateria* m) = 0;
};

#endif