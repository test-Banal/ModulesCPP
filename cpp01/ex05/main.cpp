/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:21:37 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/30 15:12:58 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() 
{
	Harl harl = Harl();
	std::cout << "DEBUG : ";
	harl.complain("debug");
	std::cout << std::endl << "INFO : ";
	harl.complain("info");
	std::cout << std::endl << "WARNING : ";
	harl.complain("warning");
	std::cout << std::endl << "ERROR : ";
	harl.complain("error");
	// std::cout << std::endl << "INVALID : ";
	// harl.complain("invalid");
	// std::cout << std::endl << "0 : ";
	// harl.complain("0");

    return 0;
}