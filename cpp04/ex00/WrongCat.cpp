#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &rhs) {
        WrongAnimal::operator=(rhs);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongMeow" << std::endl;
}
