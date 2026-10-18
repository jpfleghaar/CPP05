/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:19:16 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/04 13:16:43 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

//Intern has no variables, so (void)copy
Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

AForm *Intern::makeForm(std::string FName, std::string target)
{
    int index = -1;
    std::string Forms[3] =
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    for(int i = 0; i < 3; i++)
    {
        if(FName == Forms[i])
            index = i;
    }
    switch(index)
    {
        case 0:
            std::cout << "Intern creates " << FName << " form" << std::endl;
            return(new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates " << FName << " form" << std::endl;
            return(new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << FName << " form" << std::endl;
            return(new PresidentialPardonForm(target));
        default:
            std::cout << "Intern can't create " << FName << " form" << std::endl;
            return(NULL);
    }
}

Intern::~Intern()
{
    std::cout << "Intern deconstructor called" << std::endl;
}