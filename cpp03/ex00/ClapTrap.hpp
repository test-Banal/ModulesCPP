/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:13 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 15:19:26 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap();

        ClapTrap        &operator=(ClapTrap const &rhs);
        void			attack(std::string const &target);
        void			takeDamage(unsigned int amount);
        void			beRepaired(unsigned int amount);
        

    private:
        std::string		_name;
        int				_hitpoints;
        int				_energyPoints;
        int				_attackDamage;
};

#endif