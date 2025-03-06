/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:32:20 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/18 09:03:41 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

bool RobotomyRequestForm::_initialized = false;

int main()
{
    std::cout << "================== Make INTERN ==================" << std::endl;
    Intern intern;
    
    std::cout << std::endl << "================== Make BUREAUCRAT ==================" << std::endl;
    Bureaucrat bureaucrat("Pepe", 5);

    std::cout << std::endl << "================== Make FORMS ==================" << std::endl;
    
    AForm* robot = intern.makeForm("Robotomy Request Form", "Robot");
    AForm* presi = intern.makeForm("Presidential Pardon Form", "Guil");
    AForm* shru = intern.makeForm("Shrubbery Creation Form", "Rooftop");

    AForm* fail = NULL;
    try
    {
        fail = intern.makeForm("Non Existing Form", "Rooftop");
    }
    catch (Intern::InvalidFormException& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "================== Make SIGN ==================" << std::endl;

    bureaucrat.Bureaucrat::signForm(*robot);
    bureaucrat.Bureaucrat::signForm(*shru);
    bureaucrat.Bureaucrat::signForm(*presi);

    if (fail)
    {
        delete fail;
    }

    delete robot;
    delete shru;
    delete presi;

    return 0;
}
