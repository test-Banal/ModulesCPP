/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:55:42 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/20 16:12:21 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value) : _value(value << _fractional_bits)
{
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractional_bits)))
{
}

Fixed::Fixed(Fixed const &src) : _value(src._value)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->_value >> _fractional_bits;
}


//min max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    return a > b ? a : b;
}

//operator arithmetic
Fixed Fixed::operator+(Fixed const &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

//operator increment
Fixed &Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

//comparison operators
bool Fixed::operator>(Fixed const &rhs) const
{
    return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(Fixed const &rhs) const
{
    return this->toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return this->toFloat() != rhs.toFloat();
}

//output operator
std::ostream &operator<<(std::ostream &os, Fixed const &rhs)
{
    os << rhs.toFloat();
    return os;
}

