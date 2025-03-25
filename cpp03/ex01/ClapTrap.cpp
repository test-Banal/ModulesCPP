/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:16 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 17:39:42 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("newname"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitpoints = rhs._hitpoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    if (_hitpoints <= 0) 
    {
        std::cout << "ClapTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already defeated!" << std::endl;
        return;
    }
    _hitpoints -= amount;
    if (_hitpoints < 0) _hitpoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Hit points remaining: " << _hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitpoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit points left to repair!" << std::endl;
        return;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left to repair!" << std::endl;
        return;
    }
    _hitpoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Hit points now: " << _hitpoints << std::endl;
}