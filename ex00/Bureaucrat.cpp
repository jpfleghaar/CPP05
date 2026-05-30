/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:34:55 by jenne             #+#    #+#             */
/*   Updated: 2026/05/28 17:20:12 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureacrut::Bureaucrat() : name("NomenNescio")
{
    this->grade = 150;
}
Bureacrut::Bureaucrat(const std::string name, int grade) : name(name)
{
    if(grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
    this->grade = grade;
}