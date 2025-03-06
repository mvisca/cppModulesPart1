/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:34:41 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/15 22:38:42 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) 
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor." << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), 
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), 
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm params constructor." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor." << std::endl;
}

const std::string& AForm::getName(void) const
{
	return _name;
}

bool AForm::getSigned(void) const
{
	return _signed;
}

int AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& bureaucrat) const
{
	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	executeAction(bureaucrat);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form not signed.";
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Form " << form.getName() 
		<< ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}
