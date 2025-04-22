/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:46:38 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 19:12:59 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <cstdlib>

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor" << std::endl;
    _guardGateMode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor" << std::endl;
    _guardGateMode = false;
    //possiblement rajouter hitpoint, energy point etc
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    std::cout << "ScavTrap assignation operator" << std::endl;
    if (this != &rhs) {
        _name = rhs._name;
        _hitpoints = rhs._hitpoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    if (_energyPoints < 1) {
        std::cout << "ScavTrap " << _name << " has no energy points" << std::endl;
        return;
    }
    else 
    {
        std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
}

void ScavTrap::guardGate() {
    _guardGateMode = !_guardGateMode;
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}

bool const ScavTrap::guardGateMode() {
    return _guardGateMode;
}

