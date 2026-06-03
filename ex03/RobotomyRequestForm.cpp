/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:15:01 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/03 17:07:49 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
    std::cout << "Default Robotomy Request Form constructor called" << std::endl;
    this->setTarget("default Robotomy Request Form target"); 
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
    std::cout << "Robotomy Request Form constructor called" << std::endl;
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    std::cout << "Robotomy Request Form copy called" << std::endl;
    *this = copy; 
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "Robotomy Request Form assignment operator called" << std::endl;
    if(this != &copy)
        this->setTarget(copy.getTarget());
    return(*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat &someone) const
{
    this->checkExecute(someone);
    // std::srand(std::time(0));
    std::cout << " BEEP BEEP BOOP BEEP " << std::endl;
    if(std::rand() % 2)
        std::cout << this->getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << this->getTarget() << " Failed to robotomized" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy Request Form destructor called" << std::endl;
}