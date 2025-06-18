/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:46:42 by aneumann          #+#    #+#             */
/*   Updated: 2025/06/18 20:48:58 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm; 

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    virtual ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade(); //tend vers 1 = highest grade
    void decrementGrade(); //tend vers 150 = lowest grade
	void signForm(AForm &form) const; 

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
    
    void executeForm(const AForm &form) const;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif
