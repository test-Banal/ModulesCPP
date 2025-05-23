/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:45:26 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:27 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
    //std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src) {
    //std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
    //std::cout << "Ice destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs) {
   // std::cout << "Ice assignment operator called" << std::endl;
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    return *this;
}

// Clone - crée une nouvelle instance d'Ice
AMateria* Ice::clone() const {
    return new Ice(*this);
}

// Utilisation spécifique pour Ice
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
