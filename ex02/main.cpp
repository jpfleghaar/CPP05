/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:50:08 by Jpflegha          #+#    #+#             */
/*   Updated: 2026/05/31 18:59:32 by Jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printSeparator(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
	// Test 1: valid form construction
	printSeparator("Valid Form construction");
	try
	{
		Form f("TaxForm", 50, 25);
		std::cout << f;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 2: form grade too high (0)
	printSeparator("Form grade 0 -> GradeTooHighException");
	try
	{
		Form f("GhostForm", 0, 25);
		std::cout << f;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 3: form grade too low (151)
	printSeparator("Form grade 151 -> GradeTooLowException");
	try
	{
		Form f("SlackerForm", 151, 25);
		std::cout << f;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 4: bureaucrat signs form successfully
	printSeparator("Bureaucrat signs form successfully");
	try
	{
		Bureaucrat b("Alice", 10);
		Form f("ContractForm", 50, 25);
		std::cout << f;
		b.singForm(f);
		std::cout << f;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 5: bureaucrat grade too low to sign
	printSeparator("Bureaucrat grade too low to sign -> GradeTooLowException");
	try
	{
		Bureaucrat b("Bob", 100);
		Form f("TopSecretForm", 10, 5);
		std::cout << f;
		b.singForm(f);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 6: signing already signed form -> FormIsSignedException
	printSeparator("Sign already signed form -> FormIsSignedException");
	try
	{
		Bureaucrat b("Charlie", 1);
		Form f("DoubleSignForm", 50, 25);
		b.singForm(f);
		b.singForm(f); // second sign should throw
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 7: bureaucrat signs exactly at required grade (boundary)
	printSeparator("Bureaucrat signs at exact required grade (boundary)");
	try
	{
		Bureaucrat b("Dana", 75);
		Form f("BoundaryForm", 75, 50);
		b.singForm(f);
		std::cout << f;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 8: singForm output message check
	printSeparator("singForm prints correct message");
	try
	{
		Bureaucrat b("Eve", 1);
		Form f("AllAccessForm", 1, 1);
		b.singForm(f);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 9: form copy constructor
	printSeparator("Form copy constructor");
	try
	{
		Form original("OriginalForm", 42, 10);
		Form copy(original);
		std::cout << original;
		std::cout << copy;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// Test 10: operator<< on bureaucrat and form together
	printSeparator("operator<< output");
	try
	{
		Bureaucrat b("Frank", 30);
		Form f("ReportForm", 30, 15);
		std::cout << b;
		std::cout << f;
		b.singForm(f);
		std::cout << f;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return (0);
}