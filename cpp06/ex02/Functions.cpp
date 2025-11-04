/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:09:19 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/04 20:36:20 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


// Base* generate(void) {
//     int random = rand() % 3;
//     if (random == 0) {
//         return new A();
//     } else if (random == 1) {
//         return new B();
//     } else {
//         return new C();
//     }
// }

Base* generate(void) {
    int random = rand() % 3;
    switch (random) {
        case 0 : return new A;
        case 1 : return new B;
        default : return new C;
    }
}

void identify(Base* p) {
    if (!p) {
        std::cout << "Unknow type" << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// void identify(Base& p) {
//     try {
//         A& a = dynamic_cast<A&>(p);
//         std::cout <<"A" << std::endl;
//         (void)a;
//         return;
//     } catch (std::bad_cast&) {}
    
//     try { 
//         B& b = dynamic_cast<B&>(p);
//         std::cout << "B" << std::endl;
//         (void)b;
//         return;
//     } catch (std::bad_cast&) {}
    
//     try {
//         C& c = dynamic_cast<C&>(p);
//         std::cout << "C" << std::endl;
//         (void)c;
//         return;
//     } catch(std::bad_cast&) {}
    
//     std::cout << " Unknowm type\n";
// }

void identify(Base& p) {
    try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; } catch (...) {}
    try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; } catch (...) {}
    try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; } catch (...) {}
    std::cout << "Unknown type\n";
}
