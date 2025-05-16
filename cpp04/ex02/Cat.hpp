#ifndef CAT_HPP
#define CAT_HPP 

#include "AAnimal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
private:
    Brain *_brain;
public:
    Cat(); // Default constructor
    Cat(const Cat &src); // Copy constructor
    Cat &operator=(const Cat &rhs); // Assignment operator
    virtual ~Cat(); // Destructor

    void makeSound() const ; //override; // Override makeSound method
    Brain *getBrain() const; // Getter for Brain pointer
};

#endif