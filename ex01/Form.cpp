/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:42:07 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/05/31 19:02:35 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), signGrade(150), exceGrade(150)
{
    this->sign = false;
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string FName, const int sGrade, const int eGrade) : name(FName), signGrade(sGrade), exceGrade(eGrade) 
{
    this->sign = false;
    std::cout << "Form constructor called" << std::endl;
    if(signGrade < 1 || exceGrade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if(signGrade > 150 || exceGrade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

Form::Form(const Form &copy) : name(copy.getName()), signGrade(copy.getSignGrade()), exceGrade(copy.getExecGrade())
{
    std::cout << "Form copy assigment constructor called" << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &copy)
{
    if(this == &copy)
        return(*this);
    this->sign = copy.getSign();
    std::cout << "Form copy constructor called" << std::endl;
    return(*this);
}

std::string Form::getName() const
{
    return(this->name);
}

int Form::getExecGrade() const
{
    return(this->exceGrade);
}

int Form::getSignGrade() const
{
    return(this->signGrade);
}

bool Form::getSign() const
{
    return(this->sign);
}

void    Form::setSign(bool sign)
{
    this->sign = sign;
}

void Form::beSigned(Bureaucrat &B)
{
    if(this->sign)
        throw(FormIsSignedException());
    else if(B.getGrade() > this->signGrade)
        throw(Bureaucrat::GradeTooLowException());
    else
    {
        this->setSign(true);
        std::cout << "Bureaucrat: " << B.getName() << " signed the Form" << std::endl;
    }
}
const char* Form::FormIsSignedException::what() const throw()
{
        return("Form is already singed");     
}

Form::~Form()
{
    std::cout << "Form Deconstructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << " need a sign grad of: " <<form.getSignGrade() << " and a execute grade of: " << form.getExecGrade()
    << " sign status is: " << form.getSign() << std::endl;
    return(os);    
}



