/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:25:45 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/17 16:40:42 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137), _target("default")
{
	std::cout << "Shrubbery default constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "Shrubbery default constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:  AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "Shrubbery params constructor." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery destructor." << std::endl;
};

void ShrubberyCreationForm::executeAction(const Bureaucrat& bureaucrat) const
{
    (void)bureaucrat;
	
	std::ifstream checkFile((_target + "_shrubbery").c_str());
	
	if (checkFile.is_open())
	{
		checkFile.close();
		throw std::runtime_error("Abort: The file already exists.");
	}

	std::ofstream newFile((_target + "_shrubbery").c_str());
	if (!newFile)
		throw std::runtime_error("Abort: Could not create the file.");
	
	newFile << " ██████  ██████  ██████  " << std::endl;
	newFile << "     ██      ██      ██  " << std::endl;
	newFile << "   ███     ███     ███   " << std::endl;
	newFile << "     ██      ██      ██  " << std::endl;
	newFile << " ██████  ██████  ██████  " << std::endl;

	newFile.close();
}

