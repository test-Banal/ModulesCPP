/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:44:50 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:44:51 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
   // std::cout << "Character constructor called with name: " << name << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const Character &src) : _name(src._name)
{
    //std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (src._inventory[i])
            _inventory[i] = src._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character::Character() : _name("Default")
{
   // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::~Character()
{
    //std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

Character &Character::operator=(const Character &rhs)
{
    //std::cout << "Character assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; ++i)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}
void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Cannot equip a null Materia." << std::endl;
        return;
    }

    for (int i = 0; i < _sizeInventory; ++i)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            std::cout << "Equipped " << m->getType() << " at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= _sizeInventory)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (_inventory[idx])
    {
        std::cout << "Unequipped " << _inventory[idx]->getType() << " from index " << idx << std::endl;
        _inventory[idx] = NULL;
    }
    else
        std::cout << "No materia to unequip at index " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= _sizeInventory)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (_inventory[idx])
    {
        std::cout << "Using " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
        _inventory[idx]->use(target);
    }
    else
        std::cout << "No materia to use at index " << idx << std::endl;
}

