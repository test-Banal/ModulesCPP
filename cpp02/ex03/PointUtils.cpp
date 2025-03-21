/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PointUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:47 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/21 13:40:56 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Determines if a point is inside a triangle using the barycentric coordinate method.
 * 
 * This function checks if a given point lies within the triangle formed by three other points.
 * It uses the cross product to determine the relative position of the point with respect to the triangle's edges.
 * 
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to be checked.
 * @return true if the point is inside the triangle, false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed x = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed y = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed z = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
    return (x >= 0 && y >= 0 && z >= 0) || (x <= 0 && y <= 0 && z <= 0);
}
