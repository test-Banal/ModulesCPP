/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:27:40 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/12 20:27:06 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return;
}

Zombie::Zombie(std::string name) : _name(name)
{
    return;
}

Zombie::~Zombie()
{
    std::cout << this->_name <<" is destroyed" << std::endl;
    return;
}

void	Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

void	Zombie::setName(std::string name)
{
    this->_name = name;
    return;
}