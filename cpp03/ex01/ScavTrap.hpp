/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:47:01 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 19:10:03 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &src);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap const &rhs);

    void			attack(std::string const &target);
    void			guardGate();
    bool const      guardGateMode();
    
private :
    bool _guardGateMode;
};

#endif