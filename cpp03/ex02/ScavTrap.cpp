/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:46:38 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 13:34:36 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (getEnergyPoints() == 0 || getHitPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " can't attack. No energy or hit points left!" << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << "ScavTrap " << getName() << " savagely attacks " << target 
              << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}