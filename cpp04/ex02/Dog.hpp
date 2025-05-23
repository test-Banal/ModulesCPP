#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;
public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs); 
    virtual ~Dog();

    void makeSound() const;
    Brain *getBrain() const;
};

#endif