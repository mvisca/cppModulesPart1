/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:23:07 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/15 23:33:54 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(const AForm& other);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm(void);

        const std::string&  getName(void) const;
        bool               getSigned(void) const;
        int               getGradeToSign(void) const;
        int               getGradeToExecute(void) const;

        void              beSigned(const Bureaucrat& bureaucrat);
        void              execute(Bureaucrat const & executor) const;

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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    protected:
        virtual void      executeAction(Bureaucrat const & executor) const = 0;

    private:
        const std::string	_name;
        bool				_signed;
        const int			_gradeToSign;
        const int			_gradeToExecute;
        AForm& operator=(const AForm& other);
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif