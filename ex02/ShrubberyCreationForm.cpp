/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:25:07 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/03 17:05:35 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
    std::cout << "Default Shrubbery Creation Form constructor called" << std::endl;
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
    std::cout << "Shrubbery Creation Form constructor called" << std::endl;
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "Shrubbery Creation Form assignment operator called" << std::endl;
    if(this != &copy)
        this->setTarget(copy.getTarget());
    return(*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &someone) const
{
    this->checkExecute(someone);
    std::ofstream file((this->getTarget() + "_shrubbery").c_str());
    if(!file.is_open())
        throw std::runtime_error("Could not open file");
    file << "       *        " << std::endl;
    file << "      ***       " << std::endl;
    file << "     *****      " << std::endl;
    file << "    *******     " << std::endl;
    file << "   *********    " << std::endl;
    file << "      |||       " << std::endl;
    file << "      |||       " << std::endl;
    file.close();
    std::cout << this->getTarget() << "_shrubbery file created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}