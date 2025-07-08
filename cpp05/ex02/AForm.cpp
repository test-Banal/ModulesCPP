/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:46:19 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/30 16:15:54 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::~AForm() {
	// Destructor implementation can be empty if no dynamic memory is used
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

char const *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

char const *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

char const *AForm::FormNotSignedException::what() const throw() {
	return "Form not signed!";
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}


std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "Form Name: " << form.getName() 
	   << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
	   << ", Grade to Sign: " << form.getGradeToSign() 
	   << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_signed)
		throw GradeTooLowException(); // or a specific exception for unsigned forms
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	action();
}

void AForm::action() const {
	// This method should be overridden in derived classes to perform specific actions
	throw std::runtime_error("Action not implemented for this form.");
}