#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}   

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}