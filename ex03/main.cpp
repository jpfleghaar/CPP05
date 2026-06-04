/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:00:22 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/04 13:22:30 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Inter.hpp"

static void printSeparator(const std::string &title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
    std::srand(std::time(0));
    Inter intern;

    // Test 1: create shrubbery creation form
    printSeparator("Intern creates Shrubbery Creation Form");
    try
    {
        Bureaucrat b("Alice", 1);
        AForm *form = intern.makeForm("shrubbery creation", "garden");
        if (form)
        {
            b.singForm(*form);
            b.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 2: create robotomy request form
    printSeparator("Intern creates Robotomy Request Form");
    try
    {
        Bureaucrat b("Bob", 1);
        AForm *form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            b.singForm(*form);
            b.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 3: create presidential pardon form
    printSeparator("Intern creates Presidential Pardon Form");
    try
    {
        Bureaucrat b("Charlie", 1);
        AForm *form = intern.makeForm("presidential pardon", "Marvin");
        if (form)
        {
            b.singForm(*form);
            b.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 4: unknown form name
    printSeparator("Intern creates unknown form");
    try
    {
        AForm *form = intern.makeForm("unknown", "target");
        if (!form)
            std::cout << "No form created" << std::endl;
        delete form;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    return (0);
}