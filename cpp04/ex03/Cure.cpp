/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:45:10 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:11 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
   //std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src) {
    //std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
   // std::cout << "Cure destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const & rhs) {
    //std::cout << "Cure assignment operator called" << std::endl;
    if (this != &rhs) {
        AMateria::operator=(rhs);
    }
    return *this;
}

// Clone - crée une nouvelle instance de Cure
AMateria* Cure::clone() const {
    return new Cure(*this);
}

// Utilisation spécifique pour Cure
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
