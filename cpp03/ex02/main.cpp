/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/12 18:05:46 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- Creating Traps ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    FragTrap frag("FR4G-TP");
    
    std::cout << "\n--- Testing basic functionality ---" << std::endl;
    clap.attack("Target");
    scav.attack("Enemy");
    frag.attack("Baddie");
    
    std::cout << "\n--- Testing damage and repair ---" << std::endl;
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.takeDamage(30);
    scav.beRepaired(15);
    
    frag.takeDamage(40);
    frag.beRepaired(20);
    
    std::cout << "\n--- Testing special abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    
    // Tester que les attributs de FragTrap sont correctement initialisés    std::cout << "\nFragTrap " << frag.getName() << " stats:" << std::endl;
    std::cout << "- Hit points: " << frag.getHitPoints() << std::endl;
    std::cout << "- Energy points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "- Attack damage: " << frag.getAttackDamage() << std::endl;
    
    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}