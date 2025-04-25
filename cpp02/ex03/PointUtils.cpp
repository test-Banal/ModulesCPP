/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PointUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:08:47 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 17:52:08 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed x = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed y = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed z = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
    return (x > 0 && y > 0 && z > 0) || (x < 0 && y < 0 && z < 0);
}

// technique géométrique appelée produit vectoriel en 2D pour déterminer la position relative du point par rapport aux côtés du triangle
//i tous les produits vectoriels ont le même signe, ça veut dire que le point est du même côté de chaque segment formant le triangle => donc il est à l’intérieur ou sur le bord