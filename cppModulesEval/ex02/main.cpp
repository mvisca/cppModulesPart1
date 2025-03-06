/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:32:20 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/17 16:38:25 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

bool RobotomyRequestForm::_initialized = false;

void testAllSuccessful()
{
    std::cout << "\n===== TEST TODO OK =====\n";
    try
    {
        Bureaucrat bureaucrat("John", 1);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Criminal");

        std::cout << "\n--- Shrubbery Form ---\n";
        bureaucrat.signForm(shrub);
        bureaucrat.executeForm(shrub);

        std::cout << "\n--- Robotomy Form ---\n";
        bureaucrat.signForm(robot);
        int i = 0;
        while (i < 10)
        {
            bureaucrat.executeForm(robot);
            i++;            
        }

        std::cout << "\n--- Presidential Pardon Form ---\n";
        bureaucrat.signForm(pardon);
        bureaucrat.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testExecutionFailure()
{
    std::cout << "\n===== TEST FALLO EN EJECUCIÓN =====\n";
    try
    {
        Bureaucrat lowRank("Bob", 140); // Muy bajo para ejecutar formularios

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Wall-E");
        PresidentialPardonForm pardon("Villain");

        std::cout << "\n--- Intento de firmar y ejecutar Shrubbery Form ---\n";
        lowRank.signForm(shrub);
        lowRank.executeForm(shrub);

        std::cout << "\n--- Intento de firmar y ejecutar Robotomy Form ---\n";
        lowRank.signForm(robot);
        lowRank.executeForm(robot);

        std::cout << "\n--- Intento de firmar y ejecutar Presidential Pardon Form ---\n";
        lowRank.signForm(pardon);
        lowRank.executeForm(pardon);

        std::cout << std::endl << "Destructores:" <<std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testAllSuccessful();
    testExecutionFailure();
    return 0;
}
