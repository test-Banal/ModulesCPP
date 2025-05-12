#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

class WrongAnimal
{
protected:
    std::string type;
public: 
    WrongAnimal(); // Default constructor
    WrongAnimal(const WrongAnimal &src); // Copy constructor
    WrongAnimal(const std::string &type); // Constructor with type
    virtual ~WrongAnimal(); // Destructor
    WrongAnimal &operator=(const WrongAnimal &rhs); // Assignment operator

    void makeSound() const; // Make sound method
    std::string getType() const; // Get type method
};

#endif

//CHECKER CONSTRUCTEUR PAR TYPE