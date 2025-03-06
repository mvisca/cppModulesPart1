/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:23:07 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/14 00:19:48 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(const Form& other);
        Form(std::string name, int gradeToSign);
        ~Form(void);

        const std::string&  getName(void) const;
        bool               getSigned(void) const;
        int               getGradeToSign(void) const;

        void              beSigned(const Bureaucrat& bureaucrat);

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
        bool				_signed;
        const int			_gradeToSign;
        Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif