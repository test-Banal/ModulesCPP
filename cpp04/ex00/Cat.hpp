/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:00:07 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/16 20:00:08 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP 

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat(); // Default constructor
    Cat(const Cat &src); // Copy constructor
    Cat &operator=(const Cat &rhs); // Assignment operator
    virtual ~Cat(); // Destructor

    void makeSound() const ; //override; // Override makeSound method
};

#endif
