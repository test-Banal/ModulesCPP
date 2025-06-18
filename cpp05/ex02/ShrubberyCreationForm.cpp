/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:57:25 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/18 20:51:44 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::action() const {
    std::ofstream out((_target + "_shrubbery").c_str());

    if (!out) {
        std::cerr << "Error: could not create file" << std::endl;
        return;
    }                                                  
    out << "                                          .         ;        \n"; 
    out << "             .              .              ;%     ;;         \n";
    out << "               ,           ,                :;%  %;          \n";
    out << "                :         ;                   :;%;'     .,   \n";
    out << "       ,.        %;     %;            ;        %;'    ,;     \n";
    out << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'      \n";
    out << "          %;       %;%;      ,  ;       %;  ;%;   ,%;'       \n";
    out << "           ;%;      %;        ;%;        % ;%;  ,%;'         \n";
    out << "            `%;.     ;%;     %;'         `;%%;.%;'           \n";
    out << "             `:;%.    ;%%. %@;        %; ;@%;%'              \n";
    out << "                `:%;.  :;bd%;          %;@%;'                \n";
    out << "                  `@%:.  :;%.         ;@@%;'                 \n";
    out << "                    `@%.  `;@%.      ;@@%;                   \n";
    out << "                      `@%%. `@%%    ;@@%;                    \n";
    out << "                        ;@%. :@%%  %@@%;                     \n";
    out << "                          %@bd%%%bd%%:;                      \n";
    out << "                            #@%%%%%:;;                       \n";    
    out << "                            %@@%%%::;                        \n";
    out << "                           %@@@%(o);  . '                    \n"; 
    out << "                            %@@@o%;:(.,'                     \n";
    out << "                        `.. %@@@o%::;                        \n";
    out << "                          `)@@@o%::;                         \n";    
    out << "                           %@@(o)::;                         \n";
    out << "                          .%@@@@%::;                         \n";
    out << "                           ;%@@@@%::;.                       \n";
    out << "                          ;%@@@@%%:;;;.                      \n";  
    out << "                     ...;%@@@@@%%:;;;;,..                    \n";
    out.close();
}

#include <stdexcept>