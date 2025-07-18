/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:46:32 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/18 20:48:14 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
    // Copy constructor
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
    // Assignment operator
}

Bureaucrat::~Bureaucrat() {
    // Destructor
}

const std::string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
        std::cout << _name << " cannot sign " << form.getName() 
                  << " because their grade is too low." << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    } catch (const AForm::GradeTooLowException &e) {
        std::cout << _name << " cannot execute " << form.getName() 
                  << " because their grade is too low." << std::endl;
    } catch (const AForm::FormNotSignedException &e) {
        std::cout << _name << " cannot execute " << form.getName() 
                  << " because it is not signed." << std::endl;
    }
}

// Removed duplicate non-member signForm function with invalid const qualifier