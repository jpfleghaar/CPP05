/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:34:55 by jenne             #+#    #+#             */
/*   Updated: 2026/05/30 19:01:53 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NomenNescio")
{
    std::cout << "default consturctor called" << std::endl;
    this->grade = 150;
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
        std::cout << "constructor called" << std::endl;
    if(grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName())
{
    std::cout << "copy assigment called" << std::endl;
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
		return (*this);
	this->grade = copy.getGrade();
	std::cout << "copy constructor called" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void Bureaucrat::increaseGrade()
{
    if(this->grade >= 150)
        throw(GradeTooLowException());
    this->grade += 1;
}

void Bureaucrat::decreaseGrade()
{
    if(this->grade <= 1)
        throw(GradeTooHighException());
    this->grade -= 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("There is no Higher grade than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("There is no Lower grade than 150");
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Deconstructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", Bureaucrat grade " << obj.getGrade() << std::endl;
    return(os);
}