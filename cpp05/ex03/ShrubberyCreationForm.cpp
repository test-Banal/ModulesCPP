/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:57:25 by aneumann          #+#    #+#             */
/*   Updated: 2025/08/26 17:49:59 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

//constructeur par défaut
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {
}

//constructeur avec 
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {
}
//Constructeur avec target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

//destructeur
ShrubberyCreationForm::~ShrubberyCreationForm() {
}

//surcharge de l'opérateur d'affectation
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