/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:11:27 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/18 08:42:38 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor." << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy constructor." << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor." << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern assign operator." << std::endl;
    return *this;
}


static AForm* createShrubberyCreation(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequest(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
    const std::string formNames[] = 
    {
        "Shrubbery Creation Form",
        "Robotomy Request Form",
        "Presidential Pardon Form"
    };
    
    AForm* (*formCreators[])(const std::string&) = 
    {
        createShrubberyCreation,
        createRobotomyRequest,
        createPresidentialPardon
    };
    
    for (size_t i = 0; i < 3; i++)
    {
        if (formNames[i] == form)
        {
            std::cout << "Intern creates " << form << std::endl;
            return formCreators[i](target);
        }
    }
    throw Intern::InvalidFormException();
    
    return (NULL);
}

const char* Intern::InvalidFormException::what() const throw()
{
    return ("Error: Invalid form name.");
}
