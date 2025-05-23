/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:45:17 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:18 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure(); 
    Cure(Cure const & src);
    virtual ~Cure();

    Cure & operator=(Cure const & rhs);

    // Méthodes héritées de AMateria
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
