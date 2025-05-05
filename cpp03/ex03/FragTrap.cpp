/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:37:48 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 13:37:50 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
    
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << getName() << " enthusiastically requests high fives from everyone!" << std::endl;
}
