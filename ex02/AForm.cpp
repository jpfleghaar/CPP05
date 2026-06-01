/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:42:07 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/05/31 19:02:35 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), signGrade(150), exceGrade(150)
{
    this->sign = false;
    this->target = "default target";
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string FName, const int sGrade, const int eGrade) : name(FName), signGrade(sGrade), exceGrade(eGrade) 
{
    this->sign = false;
    this->target = "default target";
    std::cout << "AForm constructor called" << std::endl;
    if(signGrade < 1 || exceGrade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if(signGrade > 150 || exceGrade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

AForm::AForm(const AForm &copy) : name(copy.getName()), signGrade(copy.getSignGrade()), exceGrade(copy.getExecGrade())
{
    std::cout << "AForm copy assigment constructor called" << std::endl;
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
    if(this == &copy)
        return(*this);
    this->sign = copy.getSign();
    std::cout << "AForm copy constructor called" << std::endl;
    return(*this);
}

std::string AForm::getName() const
{
    return(this->name);
}

int AForm::getExecGrade() const
{
    return(this->exceGrade);
}

int AForm::getSignGrade() const
{
    return(this->signGrade);
}

bool AForm::getSign() const
{
    return(this->sign);
}

void    AForm::setSign(bool sign)
{
    this->sign = sign;
}

std::string AForm::getTarget() const
{
    return(this->target);
}

void    AForm::setTarget(std::string NewTarget)
{
    this->target = NewTarget;
}

void AForm::beSigned(Bureaucrat &B)
{
    if(this->sign)
        throw(AFormIsSignedException());
    else if(B.getGrade() > this->signGrade)
        throw(Bureaucrat::GradeTooLowException());
    else
    {
        this->setSign(true);
        std::cout << "Bureaucrat: " << B.getName() << " signed the AForm" << std::endl;
    }
}
const char* AForm::AFormIsSignedException::what() const throw()
{
    return("AForm is already singed");     
}

const char* AForm::AFormIsNotSignedException::what() const throw()
{
    return("AForm is not signed jet");
}

AForm::~AForm()
{
    std::cout << "AForm Deconstructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
    os << Aform.getName() << " need a sign grad of: " <<Aform.getSignGrade() << " and a execute grade of: " << Aform.getExecGrade()
    << " sign status is: " << Aform.getSign() << std::endl;
    return(os);    
}



