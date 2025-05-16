#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &rhs) {
        Animal::operator=(rhs);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat sound : Meow" << std::endl;
}

