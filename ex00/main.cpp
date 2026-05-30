/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:50:08 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/05/30 19:06:59 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

static void printSeparator(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	// Test 1: valid construction and grade display
	printSeparator("Valid construction");
	try
	{
		Bureaucrat b("Alice", 75);
		std::cout << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 2: grade 1 (highest allowed)
	printSeparator("Grade 1 (highest)");
	try
	{
		Bureaucrat b("TopDog", 1);
		std::cout << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 3: grade 150 (lowest allowed)
	printSeparator("Grade 150 (lowest)");
	try
	{
		Bureaucrat b("Intern", 150);
		std::cout << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 4: grade 0 -> too high exception
	printSeparator("Grade 0 -> GradeTooHighException");
	try
	{
		Bureaucrat b("Ghost", 0);
		std::cout << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 5: grade 151 -> too low exception
	printSeparator("Grade 151 -> GradeTooLowException");
	try
	{
		Bureaucrat b("Slacker", 151);
		std::cout << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 6: increaseGrade past 1 -> too high exception
	printSeparator("increaseGrade past 1 -> GradeTooHighException");
	try
	{
		Bureaucrat b("Climber", 1);
		std::cout << b;
		b.increaseGrade();
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 7: decreaseGrade past 150 -> too low exception
	printSeparator("decreaseGrade past 150 -> GradeTooLowException");
	try
	{
		Bureaucrat b("Faller", 150);
		std::cout << b;
		b.decreaseGrade();
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 8: multiple increases and decreases
	printSeparator("Multiple grade changes");
	try
	{
		Bureaucrat b("Middleman", 5);
		std::cout << b;
		b.decreaseGrade();
		std::cout << b;
		b.decreaseGrade();
		std::cout << b;
		b.increaseGrade();
		std::cout << b;
        b.increaseGrade();
		std::cout << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 9: copy constructor
	printSeparator("Copy constructor");
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << original;
		std::cout << copy;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 10: assignment operator
	printSeparator("Assignment operator");
	try
	{
		Bureaucrat a("Alpha", 10);
		Bureaucrat b("Beta", 99);
		std::cout << "Before: " << a;
		b = a;
		std::cout << "After:  " << b;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return (0);
}