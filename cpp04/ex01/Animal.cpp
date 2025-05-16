#include "Animal.hpp"


Animal::Animal() : type("Unknown") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
    std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
