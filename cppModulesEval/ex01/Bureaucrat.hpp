/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:34:56 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/15 23:00:05 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat(void);

        const std::string&  getName(void) const;
        int                getGrade(void) const;

        void              upGrade(void);
        void              downGrade(void);
        void              signForm(Form& form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string	_name;
        int					_grade;
        Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif