/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:48:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/30 16:19:03 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
            alice.executeForm(robot); // Try 5 times to see 50% chance
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

int main() {
    std::cout << "🧪 Starting tests for Exercise 02...\n";

    testShrubbery();
    
    testRobotomy();
    testPresidential();
    testLowGradeExecution();

    std::cout << "\n✅ All tests done.\n";
    return 0;
}