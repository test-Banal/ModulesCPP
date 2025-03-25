/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:48:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 17:49:14 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	bob = ClapTrap("Bob");

	ClapTrap	bib = bob;
	ClapTrap	bubs[3];

	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");
	bob.attack("a worm");

	bob.takeDamage(9);
	bob.attack("a worm");
	bob.takeDamage(1);
	bob.attack("a worm"); // No more life
	bob.attack("a worm"); // If have one more life, will not have enought energy
}
// int main() {
//     ClapTrap claptrap("ClapTrap1");
//     ClapTrap claptrap2("ClapTrap2");
//     ClapTrap claptrap3("ClapTrap3");

//     claptrap.attack("target");
//     claptrap.takeDamage(5);
//     claptrap.beRepaired(3);

//     claptrap2.attack("target");
//     claptrap2.takeDamage(6);
//     claptrap2.beRepaired(2);

//     claptrap3.attack("target");
//     claptrap3.takeDamage(9);
//     claptrap3.attack("target");
//     claptrap3.attack("target");    
// //    claptrap3.beRepaired(1);

//     return 0;
// }


//pourquoi 	ClapTrap	bib = bob; appelle copy constructor et assignation operator
//pourquoi     ClapTrap	bubs[3]; appelle default constructor 3 fois 
// copilot peut expliquer avec la fonction "explain"