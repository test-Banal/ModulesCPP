/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:48:31 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/05 14:56:56 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()    {
    try {
        Bureaucrat bureaucrat("John Doe", 50);
        std::cout << bureaucrat << std::endl;

        Form form("Form A", 45, 10);
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << form << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}