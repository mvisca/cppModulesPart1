/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:10:39 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/17 16:36:34 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
    AForm("Robotomy Request Form", 72, 45),
    _target("default")
{
	std::cout << "Robotomy default constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
    AForm(other),
    _target(other._target)
{	
	std::cout << "Robotomy copy constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
    AForm("Robotomy Request Form", 72, 45),
    _target(target)
{
	std::cout << "Robotomy params constructor." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy destructor." << std::endl;
}

void RobotomyRequestForm::executeAction(const Bureaucrat& bureaucrat) const
{
    (void)bureaucrat;

    if (!_initialized)
    {
        std::srand(std::time(NULL));
        _initialized = true;
    }

    std::cout << "Drilling noise detected..." << std::endl;


    if (std::rand() % 2 == 0)
        std::cout << "Failure: " << _target << " robotomization failed!" << std::endl;
    else
        std::cout << "Success: " << _target << " has been robotomized!" << std::endl;
}
