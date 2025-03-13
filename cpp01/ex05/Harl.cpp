/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:22:38 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/13 16:38:45 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    return;
}

void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return;
}

void Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return;
}

void Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return;
}
void Harl::complain(std::string level)
{
    void (Harl::*complaints[])(void) = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
    std::string levels[] = { "debug", "info", "warning", "error" };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*complaints[i])();
            return;
        }
    }
    std::cout << "Invalid level" << std::endl;
}