/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:21:37 by aneumann          #+#    #+#             */
/*   Updated: 2025/03/25 14:24:16 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) 
{
	Harl harl = Harl();
	

	if (argc >= 2)
		harl.complain(argv[1]);
	else
		harl.complain("");
    return 0;
}