/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:16 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 13:34:01 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &rhs) {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't attack. No energy or hit points left!" << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " damage and is destroyed!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " damage! Remaining hit points: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " can't repair itself. No energy or hit points left!" << std::endl;
        return;
    }
    
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
              << " hit points! Current hit points: " << _hitPoints << std::endl;
}

std::string ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}