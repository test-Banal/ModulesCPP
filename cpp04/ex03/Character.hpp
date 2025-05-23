/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:44:59 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 18:45:00 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
public:
    Character(std::string name);
    Character(const Character &src);
    Character();
    virtual ~Character();
    Character &operator=(const Character &rhs);

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
private:
    std::string _name;
    AMateria* _inventory[4];
    static const int _sizeInventory = 4;
};

#endif
