/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:00:59 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/18 20:46:33 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public : 
	// Constructors and Destructor	
		virtual ~AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm();
	// Copy constructor and assignment operator
		AForm (const AForm &src);
		AForm &operator=(const AForm &rhs);
	
		
	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
	
	// Member functions
	void beSigned(const Bureaucrat &bureaucrat);
	//int checkGrade(const Bureaucrat &bureaucrat) const; // not used in this context, but can be useful for checking grades	
	//virtual void execute(const Bureaucrat &executor) const = 0; // pure virtual function
    void execute(const Bureaucrat &executor) const;
    virtual void action() const = 0;
	
	// Getters
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
