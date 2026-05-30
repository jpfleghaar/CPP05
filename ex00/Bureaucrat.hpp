/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:56:06 by jenne             #+#    #+#             */
/*   Updated: 2026/05/28 17:18:49 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAURCRAT_HPP
#define BUREAURCRAT_HHP

#include <string>
#include <iostream>
class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);

        std::string getName() const;
        int getGrade() const;

        void increaseGrade();
        void decreaseGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        Bureaucrat~();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif