/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/13 11:42:44 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "--- Creating Traps ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    ScavTrap scavCopy("SC4V-TP-Copy");
    
    std::cout << "\n\n--- Testing ClapTrap functionality ---" << std::endl;
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\n\n--- Testing ScavTrap functionality ---" << std::endl;
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    std::cout << "\n\n--- Testing inheritance chain ---" << std::endl;
    // Test que ScavTrap herite des methodes de ClapTrap
    scavCopy.takeDamage(25);
    scavCopy.beRepaired(10);
    
    // Test que ScavTrap herite des methodes de ClapTrap
    std::cout << "\n\nScavTrap " << scav.getName() << " stats:" << std::endl;
    std::cout << "- Hit points: " << scav.getHitPoints() << std::endl;
    std::cout << "- Energy points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "- Attack damage: " << scav.getAttackDamage() << std::endl;
    
    std::cout << "\n\n--- End of tests ---" << std::endl;
    return 0;
}