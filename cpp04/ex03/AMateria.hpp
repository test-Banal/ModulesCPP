/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:58:52 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:42:36 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter; // Forward declaration : pour éviter les inclusions cycliques

class AMateria {
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const & src);
    virtual ~AMateria();

    AMateria & operator=(AMateria const & rhs);

    std::string const & getType() const; // Retourne le type de la materia
    
    virtual AMateria* clone() const = 0; // Méthode pure virtuelle (classe abstraite)
    virtual void use(ICharacter& target); // Utilisation de la materia sur une cible
};

#endif