/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:06:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 14:25:02 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "Default";
    
    // Inherit attributes from parent classes
    _hitPoints = FragTrap::_hitPoints;       // 100 from FragTrap
    _energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
    _attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
    _name = name;
    
    // Inherit attributes from parent classes
    _hitPoints = FragTrap::_hitPoints;       // 100 from FragTrap
    _energyPoints = ScavTrap::_energyPoints; // 50 from ScavTrap
    _attackDamage = FragTrap::_attackDamage; // 30 from FragTrap
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& src) 
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = src;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        _name = rhs._name;
    }
    return *this;
}

// Use ScavTrap's attack method
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

// Special ability for DiamondTrap
void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << ", also known as ClapTrap " 
              << ClapTrap::_name << "!" << std::endl;
}