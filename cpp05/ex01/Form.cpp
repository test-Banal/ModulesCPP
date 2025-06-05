/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:46:19 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/05 14:39:27 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::~Form() {
	// Destructor implementation can be empty if no dynamic memory is used
}

Form::Form(const Form &src) 
	: _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

char const *Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

char const *Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::string Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form Name: " << form.getName() 
	   << ", Signed: " << (form.isSigned() ? "Yes" : "No") 
	   << ", Grade to Sign: " << form.getGradeToSign() 
	   << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}
