/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:00:07 by aneumann          #+#    #+#             */
/*   Updated: 2025/05/23 15:26:35 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP 

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
    virtual ~Cat();

    void makeSound() const ;
};

#endif
