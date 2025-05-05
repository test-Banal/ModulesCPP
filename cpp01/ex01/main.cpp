/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:03:09 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/30 14:53:12 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    std::cout << "Creating a new Zombie on the stack called zombieHeap" << std::endl;
    Zombie zombieHeap = Zombie("zombieHeap");
    zombieHeap.announce();
    std::cout << "\n";
    
    std::cout << "Creating a horde of Zombies on the heap called Zombitruc" << std::endl;
    Zombie *zombitruc = zombieHorde(5, "Zombitruc");
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Zombie #" << i + 1 << ": ";
        zombitruc[i].announce();
    }
    delete [] zombitruc;
    std::cout << "\n";
    return 0;
    
}