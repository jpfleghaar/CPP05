/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:19:16 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/04 13:16:43 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inter.hpp"

Inter::Inter()
{
    std::cout << "Default Inter constructor called" << std::endl;
}

Inter::Inter(const Inter &copy)
{
    std::cout << "Inter copy constructor called" << std::endl;
    *this = copy;
}

//Inter has no variables, so (void)copy
Inter &Inter::operator=(const Inter &copy)
{
    (void)copy;
    return (*this);
}

AForm *Inter::makeForm(std::string FName, std::string target)
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
            std::cout << "Inter creates " << FName << " form" << std::endl;
            return(new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Inter creates " << FName << " form" << std::endl;
            return(new RobotomyRequestForm(target));
        case 2:
            std::cout << "Inter creates " << FName << " form" << std::endl;
            return(new PresidentialPardonForm(target));
        default:
            std::cout << "Inter can't create " << FName << " form" << std::endl;
            return(NULL);
    }
}

Inter::~Inter()
{
    std::cout << "Inter deconstructor called" << std::endl;
}