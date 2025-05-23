#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>


class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &src); 
    Animal(const std::string &type); 
    virtual ~Animal();
    Animal &operator=(const Animal &rhs); 

    virtual void makeSound() const;
    std::string getType() const;
};

#endif