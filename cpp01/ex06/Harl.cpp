/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:22:38 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/30 15:01:45 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    return;
}

void Harl::_debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    return;
}

void Harl::_info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    return;
}

void Harl::_warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return;
}

void Harl::_error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    return;
}
void Harl::complain(std::string level)
{
	std::string	complaintLevels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int			filter_level = -1;

	for (int cur = 0; cur < 4; cur++)
	{
		if (level == complaintLevels[cur])
		{
			filter_level = cur;
			break;
		}
	}

	switch (filter_level)
	{
	case 0:
		_debug();
        //fallthrough
	case 1:
		_info();
        //fallthrough
    case 2:
		_warning();
       //fallthrough
	case 3:
		_error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return;
}

//fallthrough is a feature in C++ that allows the flow of control to pass from one case of a switch statement to the next one.
//fallthrough is used to execute multiple cases in a single case block. sinon rajouter un break; pour stopper le switch