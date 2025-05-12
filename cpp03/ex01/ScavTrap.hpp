/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:47:01 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/12 18:46:49 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(); // Constructeur par defaut
    ScavTrap(const std::string& name); // Constructeur avec nom
    ScavTrap(const ScavTrap& src); // Constructeur de copie
    ~ScavTrap(); // Destructeur

    ScavTrap& operator=(const ScavTrap& rhs); // Operateur d'assignation

    void attack(const std::string& target);
    void guardGate();
};

#endif