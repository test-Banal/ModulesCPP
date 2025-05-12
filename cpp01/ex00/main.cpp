/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:03:09 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/06 18:57:48 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "Creating a classic Zombie on the stack called ZombieHeap" << std::endl;
    Zombie zombieHeap = Zombie("ZombieHeap");
    zombieHeap.announce();
    std::cout << "\n";
    
    std::cout << "Creating a new Zombie on the heap called ZombieNew" << std::endl;
    Zombie *zombieNew = newZombie("ZombieNew");
    zombieNew->announce();
    delete zombieNew;
    std::cout << "\n";

    std::cout << "Creating a new random Zombie on the stack called ZombieStack" << std::endl;
    randomChump("ZombieStack");
    std::cout << "\n";

	return 0;    
}
