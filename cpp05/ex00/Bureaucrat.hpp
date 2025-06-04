#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

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

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif