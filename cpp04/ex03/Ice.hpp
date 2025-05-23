/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:45:35 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:37 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice const & src);
    virtual ~Ice();

    Ice & operator=(Ice const & rhs);

    // Méthodes héritées de AMateria
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
