/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:02:03 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/12 20:34:56 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}

//        Zombie* zombieHorde(int N, const std::string names[]);
//        horde[i].setName(names[i]);
// dans main:
//        std::string names[] = {"Zombi1", "Zombi2", "Zombi3", "Zombi4", "Zombi5"};