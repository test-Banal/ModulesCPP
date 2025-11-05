/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:59:24 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 17:25:25 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}



// int main() {
 
//     std::cout << "=== Test constructeur vide ===" << std::endl;
// Array<int> empty;
// std::cout << "empty.size() = " << empty.size() << std::endl;

// try {
//     std::cout << "Accessing element 0 in empty array: ";
//     std::cout << empty[0] << std::endl;
// } catch (std::exception &e) {
//     std::cerr << "Caught exception: " << e.what() << std::endl;
// }

//     std::cout << "=== Test constructeur ===" << std::endl;


//     try {

//         Array<int> a(5);
//         for (unsigned int i = 0; i < a.size(); i++)
//             a[i] = i * 2;

//         std::cout << "Array a: ";
//         for (unsigned int i = 0; i < a.size(); i++)
//             std::cout << a[i] << " ";
//         std::cout << std::endl;

        
//         const Array<int> c(a);
//         std::cout << "Creation array c : c.size() = " << c.size() << std::endl;
        
//         // for (unsigned int i = 0; i < c.size(); i++) //test lecture et affichage
//         //     std::cout << c[i] << " ";
//         // std::cout << std::endl;
        
//         // Écriture interdite (doit provoquer une erreur de compilation si décommenté)
//         // c[0] = 123; // <- NE DOIT PAS compiler car c en const

//         std::cout << "\n=== Test copie d'un Array B ===" << std::endl;
//         Array<int> b = a; //"copie initialisation"
//         b[0] = 99;

//         std::cout << "Array a after modifying b: ";
//         for (unsigned int i = 0; i < a.size(); i++)
//             std::cout << a[i] << " ";
//         std::cout << std::endl;

//         std::cout << "Array b: ";
//         for (unsigned int i = 0; i < b.size(); i++)
//             std::cout << b[i] << " ";
//         std::cout << std::endl;

//         std::cout << "TEst out of bounds..." << std::endl;
//         std::cout << a[42] << std::endl;

//     } catch (std::exception& e) {
//         std::cerr << "Caught exception: " << e.what() << std::endl;
//     }

//     std::cout << std::endl;

//     return 0;
// }
