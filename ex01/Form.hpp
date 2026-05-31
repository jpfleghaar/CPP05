/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:08 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/05/31 18:40:20 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>


class Form
{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int exceGrade;
        
    public:
        Form();
        Form(const std::string FName, const int sGrade, const int eGrade);
        Form(const Form &copy);
        Form &operator=(const Form &copy);

        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSign() const;
        void setSign(bool sign);
        void beSigned(Bureaucrat &B);

        class FormIsSignedException : public std::exception
        {
          public:
            const char *what() const throw();  
        };

        ~Form();
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif