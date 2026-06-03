/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:00:22 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/06/03 17:07:21 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void printSeparator(const std::string &title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	std::srand(std::time(0));
    // Test 1: sign and execute ShrubberyCreationForm
    printSeparator("Shrubbery Creation Form");
    try
    {
        Bureaucrat b("Alice", 1);
        ShrubberyCreationForm f("home");
        b.singForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 2: sign and execute RobotomyRequestForm
    printSeparator("Robotomy Request Form");
    try
    {
        Bureaucrat b("Bob", 1);
        RobotomyRequestForm f("Bender");
        b.singForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 3: sign and execute PresidentialPardonForm
    printSeparator("Presidential Pardon Form");
    try
    {
        Bureaucrat b("Charlie", 1);
        PresidentialPardonForm f("Marvin");
        b.singForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 4: execute without signing
    printSeparator("Execute without signing");
    try
    {
        Bureaucrat b("Dave", 1);
        RobotomyRequestForm f("R2D2");
        b.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 5: grade too low to sign
    printSeparator("Grade too low to sign");
    try
    {
        Bureaucrat b("Eve", 150);
        RobotomyRequestForm f("C3PO");
        b.singForm(f);
        b.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 6: grade too low to execute
    printSeparator("Grade too low to execute");
    try
    {
        Bureaucrat signer("Frank", 1);
        Bureaucrat executor("Greg", 150);
        RobotomyRequestForm f("HAL");
        signer.singForm(f);
        executor.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    // Test 7: robotomy 50/50 - run multiple times
    printSeparator("Robotomy 50/50 test x5");
    try
    {
        Bureaucrat b("Henry", 1);
        RobotomyRequestForm f("Target");
        b.singForm(f);
        for (int i = 0; i < 5; i++)
            b.executeForm(f);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }

    return (0);
}