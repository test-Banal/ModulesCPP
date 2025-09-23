/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:49:13 by aneumann          #+#    #+#             */
/*   Updated: 2025/09/23 21:51:55 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

       Bureaucrat alice("Alice", 1);
       std::cout << alice << std::endl;

        alice.incrementGrade();

        Bureaucrat georges("Georges", 150);
        std::cout << georges << std::endl;
        georges.decrementGrade();
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    

    return 0;
}

//si je veux que aller a georges je dois faire un try catch , en gros apres chaque appel 
//de increment ou decrement je dois faire un try catch, car sinon le programme ne va pas au bout

// int main() {
//     try {
//         Bureaucrat bob("Bob", 50);
//         std::cout << bob << std::endl;

//         bob.incrementGrade();
//         std::cout << "After increment: " << bob << std::endl;

//         bob.decrementGrade();
//         std::cout << "After decrement: " << bob << std::endl;
//     } catch (const std::exception &e) {
//         std::cerr << "Exception with Bob: " << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat alice("Alice", 1);
//         std::cout << alice << std::endl;

//         alice.incrementGrade();  // devrait lancer une exception
//     } catch (const std::exception &e) {
//         std::cerr << "Exception with Alice: " << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat georges("Georges", 150);
//         std::cout << georges << std::endl;

//         georges.decrementGrade();  // devrait lancer une exception
//     } catch (const std::exception &e) {
//         std::cerr << "Exception with Georges: " << e.what() << std::endl;
//     }

//     return 0;
// }
