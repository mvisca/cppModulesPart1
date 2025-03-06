/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:53:55 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/18 08:41:39 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        ~Intern(void);

        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& form, const std::string& target);

        class InvalidFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        typedef AForm* (*FormCreator)(std::string const &);
};

#endif