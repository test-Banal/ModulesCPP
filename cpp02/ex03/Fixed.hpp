/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:58:30 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/20 15:57:26 by aneumann         ###   ########.fr       */
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
        
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(Fixed const &a, Fixed const &b);
        static const Fixed &max(Fixed const &a, Fixed const &b);

        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;

        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

    private:
        int _value;
        int const static _fractional_bits = 8;
        
    friend std::ostream &operator<<(std::ostream &os, Fixed const &rhs);
};

#endif