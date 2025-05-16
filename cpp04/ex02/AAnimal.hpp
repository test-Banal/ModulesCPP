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
    Animal(); //constructeur par défaut
    Animal(const Animal &src); //constructeur de recopie
    Animal(const std::string &type); //constructeur avec type
    virtual ~Animal(); //destructeur
    Animal &operator=(const Animal &rhs); //opérateur d'affectation

    virtual void makeSound() const = 0; //méthode virtuelle pure
    std::string getType() const;
};

#endif