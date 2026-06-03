/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:12:08 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/03 17:02:21 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int exceGrade;
        std::string target;
        
    public:
        AForm();
        AForm(const std::string FName, const int sGrade, const int eGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);

        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSign() const;
        void setSign(bool sign);
        void beSigned(Bureaucrat &B);
        std::string getTarget() const;
        void		setTarget(std::string target);
        void checkExecute(const Bureaucrat &copy) const;
        virtual void execute(Bureaucrat const &someone) const = 0;
        
        class AFormIsSignedException : public std::exception
        {
          public:
            const char *what() const throw();  
        };
        class AFormIsNotSignedException: public std::exception
		{
			const char *what() const throw();
		};
        
        virtual ~AForm();
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif