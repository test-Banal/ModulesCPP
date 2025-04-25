/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:55 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/25 18:39:12 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string truncate(const std::string& str, size_t max_length)
{
    if (str.length() > max_length)
        return str.substr(0, max_length - 1) + ".";
    return str;
}

std::string get_input()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}