/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:48:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/09/23 22:06:53 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// int main ()    {
//     try {
//         Bureaucrat bureaucrat("John Doe", 50);
//         std::cout << bureaucrat << std::endl;

//         Form form("Form A", 45, 10);
//         std::cout << form << std::endl;

//         bureaucrat.signForm(form);
//         std::cout << form << std::endl;

//         bureaucrat.incrementGrade();
//         std::cout << bureaucrat << std::endl;

//         bureaucrat.signForm(form);
//     } catch (const std::exception &e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }

int main() {
    std::cout << "=== TEST 1: Création et affichage basique ===" << std::endl;
    try {
        Bureaucrat john("John", 50);
        Form formA("Tax Form", 45, 30);
        
        std::cout << john << std::endl;
        std::cout << formA << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Signature réussie ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);  // Grade suffisant
        Form formB("License Application", 45, 25);
        
        std::cout << "Avant signature:" << std::endl;
        std::cout << alice << std::endl;
        std::cout << formB << std::endl;
        
        alice.signForm(formB);  // Devrait réussir
        
        std::cout << "Après signature:" << std::endl;
        std::cout << formB << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Signature échouée (grade insuffisant) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);  // Grade trop bas
        Form formC("Top Secret", 50, 20);  // Nécessite grade 50
        
        std::cout << "Avant tentative de signature:" << std::endl;
        std::cout << bob << std::endl;
        std::cout << formC << std::endl;
        
        bob.signForm(formC);  // Devrait échouer
        
        std::cout << "Après tentative:" << std::endl;
        std::cout << formC << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Tentative de re-signature ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 30);
        Form formD("Contract", 35, 15);
        
        charlie.signForm(formD);  // Première signature
        std::cout << "Première signature:" << std::endl;
        std::cout << formD << std::endl;
        
        charlie.signForm(formD);  // Tentative de re-signature
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Création de Form avec grades invalides ===" << std::endl;
    try {
        Form invalidForm1("Invalid1", 0, 50);  // Grade trop haut
    } catch (const std::exception &e) {
        std::cerr << "Exception Form grade 0: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid2", 50, 151);  // Grade trop bas
    } catch (const std::exception &e) {
        std::cerr << "Exception Form grade 151: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Cas limites (grades 1 et 150) ===" << std::endl;
    try {
        Bureaucrat vip("VIP", 1);  // Grade maximum
        Form easyForm("Easy Task", 150, 150);  // Grade minimum
        
        std::cout << vip << std::endl;
        std::cout << easyForm << std::endl;
        
        vip.signForm(easyForm);  // Devrait réussir facilement
        std::cout << easyForm << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat intern("Intern", 150);  // Grade minimum
        Form hardForm("Impossible Task", 1, 1);  // Grade maximum requis
        
        std::cout << intern << std::endl;
        std::cout << hardForm << std::endl;
        
        intern.signForm(hardForm);  // Devrait échouer
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== FIN DES TESTS ===" << std::endl;
    return 0;
}