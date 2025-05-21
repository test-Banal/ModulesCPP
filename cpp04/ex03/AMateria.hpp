/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:58:52 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/21 16:56:47 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type); //Constructeur avec parametre
		AMateria(); //Constructeur par defaut
		AMateria(AMateria const & src); //Constructeur de copie
		virtual ~AMateria(); //Destructeur
		AMateria & operator=(AMateria const & rhs); //Operateur d'affectation
		
		

		std::string const & getType() const; //Retourne le type de Materia
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
