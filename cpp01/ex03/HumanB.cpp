/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:29:58 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/30 14:55:30 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    return;
}

HumanB::~HumanB()
{
    return;
}

void HumanB::attack()
{
    if (this->weapon != NULL)
    {
            std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->name << " has no weapon to attack with" << std::endl;
    }
    return;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
    return;
}
