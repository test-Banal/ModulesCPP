/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:12:00 by aneumann          #+#    #+#             */
/*   Updated: 2025/12/22 20:35:04 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        long result = RPN::evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        (void)e;
        std::cerr << "Error" << std::endl; 
        return 1;
    }

    return 0;
}
