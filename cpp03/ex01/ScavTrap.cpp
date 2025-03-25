/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:46:38 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 18:02:11 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <cstdlib>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << this->_name << " is born!" << std::endl;
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "ScavTrap " << this->_name << " is born by copy!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    ClapTrap::operator=(rhs);
    return *this;
}

void ScavTrap::challengeNewcomer(void)
{
    std::string challenges[5] = {
        "Eat a spoonful of cinnamon!",
        "Try not to laugh!",
        "Try not to cry!",
        "Try not to cringe!",
        "Try not to get angry!"
    };
    std::cout << "ScavTrap " << this->_name << " challenges you to: " << challenges[rand() % 5] << std::endl;
}

