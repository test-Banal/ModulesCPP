/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:06:49 by aneumann          #+#    #+#             */
/*   Updated: 2025/10/27 19:06:52 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <climits>
#include <cctype>
#include <cstdlib>

class ScalarConverter {
    private:
        ScalarConverter(); 
        ScalarConverter(const ScalarConverter &src); 
        ~ScalarConverter(); 
        ScalarConverter &operator=(const ScalarConverter &rhs); 

    public:
        static void convert(const std::string &literal);
};   

#endif
