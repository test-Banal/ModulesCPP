#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), _brain(new Brain(*src._brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        delete _brain; // Free the old brain pour eviter leaks
        _brain = new Brain(*rhs._brain); // Deep copy
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain; // Free the brain
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return _brain;
}

