#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain; // Pointer to Brain object
public:
    Dog(); // Default constructor
    Dog(const Dog &src); // Copy constructor
    Dog &operator=(const Dog &rhs); // Assignment operator
    virtual ~Dog(); // Destructor

    void makeSound() const; //override; // Override makeSound method
    Brain *getBrain() const; // Getter for Brain
};

#endif