/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:09:50 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/04 15:10:41 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"

int main() {
    // initialise le générateur aléatoire
    std::srand(std::time(0));
    
    //plusieurs tests : 
    for (int i = 0; i < 5; i++) {
        std::cout << "--- Test " << (i + 1) << " ---" << std::endl;
        
        Base* obj = generate();
        
        std::cout << "Identify class type by pointer:   ";
        identify(obj);
        
        std::cout << "Identify class type by reference: ";
        identify(*obj);
        
        delete obj;
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    // test avec pointeur null
    std::cout << "Testing NULL pointer:" << std::endl;
    std::cout << "Identify NULL pointer: ";
    identify(static_cast<Base*>(NULL));
    
    std::cout << std::endl;
    
    return 0;
}
