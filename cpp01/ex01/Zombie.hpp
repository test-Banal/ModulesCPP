/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:03:54 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/12 20:24:39 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    
    void	announce(void);
    void	setName(std::string name);

private:
    std::string _name;
};

#endif