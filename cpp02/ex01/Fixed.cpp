/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:55:42 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 17:52:54 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int value) : _value(value << _fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractional_bits)))
{
    std::cout << "Float constructor called" << std::endl;
    return;
}
Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called " << std::endl; 
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::Fixed(Fixed const &src) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src; 
    
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (float)(1 << this->_fractional_bits);
}

int Fixed::toInt(void) const
{
    return roundf(this->_value / (1 << this->_fractional_bits)); 
    // return this->_value >> _fractional_bits; cf Precision
}

std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
    os << rhs.toFloat();
    return os;
}
    //Precision
    //Cette version convertit la valeur en float, puis divise par 2fractional_bits2fractional_bits pour obtenir la valeur réelle, et ensuite l'arrondit à l'entier le plus proche.
    //C'est plus précis
    // return this->_value >> _fractional_bits;  Cette version utilise un décalage binaire à droite (>>), ce qui correspond à une division entière par 2fractional_bits2fractional_bits. 
    //C’est une méthode plus rapide, mais elle tronque vers zéro (ne fait pas d’arrondi). 
    // Si vous voulez un arrondi, utilisez la méthode de la division entière (roundf).