/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:21:37 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/13 16:36:18 by aneumann         ###   ########.fr       */
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


    return 0;
}