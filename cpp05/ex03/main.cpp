/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:48:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/08/27 20:21:01 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void testShrubbery() {
    std::cout << "\n=== Test ShrubberyCreationForm ===\n";

    Bureaucrat bob("Bob", 137);
    ShrubberyCreationForm shrub("garden");

    try {
        bob.executeForm(shrub); // Not signed yet
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << '\n';
    }

    try {
        bob.signForm(shrub);
        bob.executeForm(shrub); // Should succeed
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
    }
}

void testRobotomy() {
    std::cout << "\n=== Test RobotomyRequestForm ===\n";

    Bureaucrat alice("Alice", 45);
    RobotomyRequestForm robot("Bender");

    try {
        alice.executeForm(robot); // Not signed yet
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << '\n';
    }

    try {
        alice.signForm(robot);
        for (int i = 0; i < 5; ++i) {
            alice.executeForm(robot); // Try several times to see 50% chance
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
    }
}

void testPresidential() {
    std::cout << "\n=== Test PresidentialPardonForm ===\n";

    Bureaucrat president("Zaphod", 1);
    PresidentialPardonForm pardon("Ford Prefect");

    try {
        president.signForm(pardon);
        president.executeForm(pardon); // Should succeed
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
    }
}

void testLowGradeExecution() {
    std::cout << "\n=== Test Execution with Grade Too Low ===\n";

    Bureaucrat intern("Intern", 150);
    ShrubberyCreationForm shrub("park");

    try {
        intern.signForm(shrub); // Should fail
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << '\n';
    }

    try {
        shrub.beSigned(intern); // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << '\n';
    }
}

// ✅ Nouveau : Test de l’Intern
void testIntern() {
    std::cout << "\n=== Test Intern::makeForm ===\n";

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "backyard");
    AForm* form2 = someRandomIntern.makeForm("robotomy request", "Marvin");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm* form4 = someRandomIntern.makeForm("invalid form", "Nobody"); // Should fail

    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }
    if (form4) {
        delete form4; // Juste au cas où
    }
}

int main() {
    std::cout << "Starting tests ........................\n";

    testShrubbery();
    testRobotomy();
    testPresidential();
    testLowGradeExecution();
    testIntern(); // ✅ ajout pour exercice 03

    std::cout << "\n✅ All tests done.\n";
    return 0;
}
