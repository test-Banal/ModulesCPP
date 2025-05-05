/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/05 13:33:10 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    // Test constructors
    std::cout << "--- Creating ClapTraps ---" << std::endl;
    ClapTrap defaultTrap;
    ClapTrap c1("C1");
    ClapTrap c2("C2");
    ClapTrap c3(c1);
    
    std::cout << "\n--- Testing basic functionality ---" << std::endl;
    
	// Test attack
    c1.attack("Target Dummy");
    
    // Test taking damage
    c1.takeDamage(5);
    
    // Test repair
    c1.beRepaired(2);
    
    std::cout << "\n--- Testing energy depletion ---" << std::endl;
    // Test energy depletion
    for (int i = 0; i < 9; i++) {
        std::cout << "Attack " << i + 1 << ": ";
        c2.attack("Energy Tester");
    }
    
    // Should be out of energy now
    c2.attack("Energy Tester");
    c2.beRepaired(5);
    
    std::cout << "\n--- Testing hit points depletion ---" << std::endl;
    // Test hit points depletion
    c3.takeDamage(15); // More than max hit points
    c3.attack("Dead Target"); // Should not work
    c3.beRepaired(5);  // Should not work
    
    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}