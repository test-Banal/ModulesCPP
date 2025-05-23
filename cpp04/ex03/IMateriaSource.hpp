/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:45:52 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:53 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class AMateria;
class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual AMateria* createMateria(std::string const & type) = 0;
    virtual void learnMateria(AMateria* m) = 0;
};

#endif
