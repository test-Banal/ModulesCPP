/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:58:30 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:57 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed const &src);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();

        Fixed &operator=(Fixed const &rhs);

        float toFloat(void) const;
        int toInt(void) const; 
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _value;
        int const static _fractional_bits = 8;
        
    friend std::ostream &operator<<(std::ostream &os, Fixed const &rhs);
};

#endif