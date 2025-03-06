/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:34:41 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/14 00:23:44 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("Default form"), _signed(false), _gradeToSign(150)
{
	std::cout << "Form default constructor." << std::endl;
}

Form::Form(const Form& other)
	:   _name(other._name),
		_signed(other._signed),
		_gradeToSign(other._gradeToSign)
{
	std::cout << "Form copy constructor." << std::endl;
}

Form::Form(std::string name, int gradeToSign)
	:	_name(name),
		_signed(false),
		_gradeToSign(gradeToSign)
{
	std::cout << "Form params constructor." << std::endl;
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor." << std::endl;
}

const std::string& Form::getName(void) const { return _name; }
bool Form::getSigned(void) const { return _signed; }
int Form::getGradeToSign(void) const { return _gradeToSign; }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low.";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high.";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form " << form.getName() 
		<< ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", grade required to sign: " << form.getGradeToSign();
	return out;
}
