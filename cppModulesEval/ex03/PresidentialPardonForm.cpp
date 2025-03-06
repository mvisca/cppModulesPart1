/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:25:30 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/16 00:06:51 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", 25, 5), _target("default")
{
    std::cout << "Presidential default constructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << "Presidential copy constructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << "Presidential params constructor." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Presidential destructor." << std::endl;
}

void PresidentialPardonForm::executeAction(const Bureaucrat& bureaucrat) const
{
    (void)bureaucrat;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

