/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:56 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 15:54:39 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


int main() {
    int array[] = {1, 2, 3, 4, 5};
    ::iter(array, 2, printElement<int>);
    ::iter(array, 5, increment<int>);
    std::cout<< "\n";
    ::iter(array, 5, printElement<int>);


    std::cout << std::endl;
    std::string strArray[] = {"hello", "world", "42"};
    ::iter(strArray, 3, printElement<std::string>);

    return 0;
}