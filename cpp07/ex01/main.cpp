/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:56 by aneumann          #+#    #+#             */
/*   Updated: 2025/10/30 15:46:57 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


int main() {
    int array[] = {1, 2, 3, 4, 5};
    ::iter(array, 2, printElement);

    std::cout << "-----\n" << std::endl;
    std::string strArray[] = {"hello", "world", "42"};
    ::iter(strArray, 3, printElement);

    return 0;
}
