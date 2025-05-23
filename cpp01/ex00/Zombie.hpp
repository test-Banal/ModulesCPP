/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:03:54 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/30 14:46:03 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie(std::string name);
    ~Zombie(void);
    void	announce(void);

private:
    std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif