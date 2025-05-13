/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:06:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/13 13:31:17 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "Default";
    
    // Herite des attributs des classes parentes
    _hitPoints = FragTrap::_hitPoints;       // 100 de FragTrap
    _energyPoints = ScavTrap::_energyPoints; // 50 de ScavTrap
    _attackDamage = FragTrap::_attackDamage; // 30 de FragTrap
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
    _name = name;
    
    // Idem Herite des attributs des classes parentes
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) 
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        _name = rhs._name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target); //utilise la methode attack de ScavTrap
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << ", also known as ClapTrap " 
              << ClapTrap::_name << "!" << std::endl;
}