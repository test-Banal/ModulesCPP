#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(); // Default constructor
    Dog(const Dog &src); // Copy constructor
    Dog &operator=(const Dog &rhs); // Assignment operator
    virtual ~Dog(); // Destructor

    void makeSound() const; //override; // Override makeSound method
};

#endif