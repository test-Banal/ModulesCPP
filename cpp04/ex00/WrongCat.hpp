#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat(); // Default constructor
    WrongCat(const WrongCat &src); // Copy constructor
    WrongCat &operator=(const WrongCat &rhs); // Assignment operator
    virtual ~WrongCat(); // Destructor

    void makeSound() const; // Override makeSound method
};

#endif