#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Materia.hpp"
#include <iostream>

class Character
{
public:
    Character(std::string name);
    Character(const Character &src);
    ~Character();
    Character &operator=(const Character &rhs);

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
private:
    std::string _name;
    AMateria* _inventory[4];
};

#endif