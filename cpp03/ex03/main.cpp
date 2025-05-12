/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/12 18:07:36 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // Test constructeurs
    std::cout << "--- Creating Traps ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    FragTrap frag("FR4G-TP");
    DiamondTrap diamond("DI4M-TP");
    
    std::cout << "\n--- Testing basic functionality ---" << std::endl;
    clap.attack("Target");
    scav.attack("Enemy");
    frag.attack("Baddie");
    diamond.attack("Boss"); // Devrait utiliser l'attaque de ScavTrap
    
    std::cout << "\n--- Testing damage and repair ---" << std::endl;
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    
    std::cout << "\n--- Testing special abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    diamond.guardGate();      // Herite de ScavTrap
    diamond.highFivesGuys();  // Herite de FragTrap
    diamond.whoAmI();         // Capacité spéciale de DiamondTrap
    

    // Tester que les attributs de DiamondTrap sont biem initialisés    
    std::cout << "\nDiamondTrap " << diamond.getName() << " stats:" << std::endl;
    std::cout << "- Hit points: " << diamond.getHitPoints() << std::endl;
    std::cout << "- Energy points: " << diamond.getEnergyPoints() << std::endl;
    std::cout << "- Attack damage: " << diamond.getAttackDamage() << std::endl;
    
    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}