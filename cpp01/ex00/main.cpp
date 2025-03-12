/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:03:09 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/12 19:29:17 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "Creating a new Zombie on the stack called Zombidule" << std::endl;
    Zombie zombidule = Zombie("Zombidule");
    zombidule.announce();
    std::cout << "\n";
    
    std::cout << "Creating a new Zombie on the heap called Zombitruc" << std::endl;
    Zombie *zombitruc = newZombie("Zombitruc");
    zombitruc->announce();
    delete zombitruc;
    std::cout << "\n";

    std::cout << "Creating a new random Zombie on the stack called Zombimachin" << std::endl;
    randomChump("Zombimachin");
    std::cout << "\n";
    
}