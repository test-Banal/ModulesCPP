/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:07 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 17:55:38 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(Point const &src) : _x(src._x), _y(src._y)
{
}

Point::~Point()
{
}

Point &Point::operator=(Point const &rhs)
{
    (void)rhs;
    return *this;
}

Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}

std::ostream &operator<<(std::ostream &o, Point const &rhs)
{
    o << "Point(" << rhs.getX() << ", " << rhs.getY() << ")";
    return o;
}