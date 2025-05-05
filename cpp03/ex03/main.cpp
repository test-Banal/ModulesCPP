/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 14:19:30 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // Test constructors
    std::cout << "--- Creating Traps ---" << std::endl;
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    FragTrap frag("FR4G-TP");
    DiamondTrap diamond("DI4M-TP");
    
    std::cout << "\n--- Testing basic functionality ---" << std::endl;
    clap.attack("Target");
    scav.attack("Enemy");
    frag.attack("Baddie");
    diamond.attack("Boss"); // Should use ScavTrap's attack
    
    std::cout << "\n--- Testing damage and repair ---" << std::endl;
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    
    std::cout << "\n--- Testing special abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    diamond.guardGate();      // Inherited from ScavTrap
    diamond.highFivesGuys();  // Inherited from FragTrap
    diamond.whoAmI();         // DiamondTrap's special ability
    
    // Test that DiamondTrap's attributes are properly initialized
    std::cout << "\nDiamondTrap " << diamond.getName() << " stats:" << std::endl;
    std::cout << "- Hit points: " << diamond.getHitPoints() << std::endl;
    std::cout << "- Energy points: " << diamond.getEnergyPoints() << std::endl;
    std::cout << "- Attack damage: " << diamond.getAttackDamage() << std::endl;
    
    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}