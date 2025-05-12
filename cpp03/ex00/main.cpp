/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/12 18:31:27 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    // Test constructeurs
    std::cout << "--- Creating ClapTraps ---" << std::endl;
    ClapTrap defaultTrap;
    ClapTrap c1("C1");
    ClapTrap c2("C2");
    ClapTrap c3(c1);
    
    std::cout << "\n--- Testing basic functionality ---" << std::endl;
    
	// attack test
    c1.attack("Target Dummy");
    
    // damage test 
    std::cout << "\nHit points before damage: " << c1.getHitPoints() << std::endl;
    c1.takeDamage(5);
    
    // repair test
    std::cout << "\nHit points before repair: " << c1.getHitPoints() << std::endl;
    c1.beRepaired(2);
    std::cout << "\n--- Testing energy depletion ---" << std::endl;
    
    // test epuisement d'énergie
    for (int i = 0; i < 9; i++) {
        std::cout << "Attack " << i + 1 << ": ";
        c2.attack("Energy_Tester");
    }
    
    // normalement , plus d'énergie
    std::cout << std::endl;
    std::cout << "Hit points before attacks: " << c2.getHitPoints() << std::endl;
    c2.attack("Energy_Tester");
    std::cout << "Hits points before repaired himslef: " << c2.getHitPoints() << std::endl;
    c2.beRepaired(5);
    
    std::cout << "\n--- Testing hit points depletion ---" << std::endl;
    // test epuisement de points de vie
    c3.takeDamage(15); // + de points de vie
    c3.attack("Dead Target"); // Ne doit pas fonctionner
    c3.beRepaired(5);  // Ne doit pas fonctionner
    
    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}