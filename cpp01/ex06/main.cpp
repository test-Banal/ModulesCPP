/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:21:37 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/13 16:52:31 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) 
{
	// Harl harl=Harl();
	
	// if (argc != 2)
	// {
	// 	std::cout << "Usage: ./complain [debug/info/warning/error]" << std::endl;
	// 	return 1;
	// }

	// harl.complain(argv[1]);
    // return 0;
	Harl harl;

    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <log_level>" << std::endl;
        return 1;
    }

    harl.complain(argv[1]);
    return 0;
}