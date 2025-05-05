/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:06:47 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 14:24:23 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& src);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& rhs);

    void attack(const std::string& target);
    void whoAmI();
    
    std::string getName() const { return _name; }
    unsigned int getHitPoints() const { return _hitPoints; }
    unsigned int getEnergyPoints() const { return _energyPoints; }
    unsigned int getAttackDamage() const { return _attackDamage; }
private:
    std::string _name; 
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};
#endif

