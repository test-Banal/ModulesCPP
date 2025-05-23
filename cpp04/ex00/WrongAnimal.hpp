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
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal(const std::string &type);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &rhs);

    void makeSound() const;
    std::string getType() const;
};

#endif