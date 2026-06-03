/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:44:21 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/03 16:49:13 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
    std::cout << "Default Presidential Pardon Form constructor called" << std::endl;
	this->setTarget("default Presidential Pardon Form Target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
    std::cout << "Presidential Pardon Form constructor called" << std::endl;
	if(!(target.empty()))
		this->setTarget(target);
	this->setSign(this->getSign());
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
    std::cout << "Presidential Pardon Form copy assignment constructor called" << std::endl;
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
    if(this == &copy)
        return(*this);
    this->setSign(copy.getSign());
    this->setTarget(copy.getTarget());
    return(*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &someone) const
{
    this->checkExecute(someone);
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Pardon Form deconstructor called" << std::endl;
}