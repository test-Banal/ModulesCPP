/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:04:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/21 13:36:19 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(Point const &src);
        Point(float const x, float const y);
        ~Point();

        Point &operator=(Point const &rhs);

        Fixed getX(void) const;
        Fixed getY(void) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &o, Point const &rhs);

#endif