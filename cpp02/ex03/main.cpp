/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:11:20 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/21 13:38:09 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Point a(0, 0);
    Point b(5, 5);
    Point c(4, 1);

    Point p1(4, 3);
    Point p2(3.5, 2);
    Point p3(6, 4);
    Point p4(7, 6);
    Point p5(4.5, 3.1);

 
    std::cout << "Point a: " << a << std::endl;
    std::cout << "Point b: " << b << std::endl;
    std::cout << "Point c: " << c << std::endl;

    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;
    std::cout << "Point p3: " << p3 << std::endl;
    std::cout << "Point p4: " << p4 << std::endl;
    std::cout << "Point p5: " << p5 << std::endl;

    std::cout << "bsp(a, b, c, p1): " << bsp(a, b, c, p1) << std::endl;
    std::cout << "bsp(a, b, c, p2): " << bsp(a, b, c, p2) << std::endl;
    std::cout << "bsp(a, b, c, p3): " << bsp(a, b, c, p3) << std::endl;
    std::cout << "bsp(a, b, c, p4): " << bsp(a, b, c, p4) << std::endl;
    std::cout << "bsp(a, b, c, p5): " << bsp(a, b, c, p5) << std::endl;

    return 0;
}