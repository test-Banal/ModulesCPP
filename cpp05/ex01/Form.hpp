/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:00:59 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/04 18:22:55 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class : Form
{
	private :
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public : 	
		virtual ~Form();
		Form &operator=(const Form &rhs);
		Form (const Form &src);
	
	class GradeTooHighException : public std::execption
	{
		virtual const char *what() cont throw();
	}
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() cont throw();
	}
	
	void beSigned(const Bureaucrat &bureaucrat);

}
