/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:50:55 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/28 11:03:04 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string truncate(const std::string& str, size_t max_length)
{
    if (str.length() > max_length)
    {
        std::string truncated = str.substr(0, max_length - 1);
        truncated += '.';
        return truncated;
    }
    return str;
}

std::string get_input(const std::string& prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
            break;
        std::cout << "Cannot be empty, Please enter again." << std::endl;
    }
    return input;
}