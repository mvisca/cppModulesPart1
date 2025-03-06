/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:56:08 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/15 22:43:04 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:	_name("Juan Nada"),
		_grade(150)
{
	std::cout << "Bureaucrat default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	_name(other._name),
		_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name),
		_grade(grade)
{
	std::cout << "Bureaucrat params constructor." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor." << std::endl;
}

const std::string&	Bureaucrat::getName(void) const {return _name;}
int Bureaucrat::getGrade(void) const {return _grade;}

void Bureaucrat::upGrade(void)
{
	std::cout << "Bureaucrat upGrade" << std::endl;
	if (_grade <= 1)
		throw GradeTooHighException(); 
	_grade--;
}

void Bureaucrat::signForm(Form& form)
{
	std::cout << "Bureaucrat signForm" << std::endl;
	try
	{
		form.beSigned(*this);
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName();
		std::cout << " because " << e.what() << "." << std::endl;
		return;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::downGrade(void)
{
	std::cout << "Bureaucrat downGrade" << std::endl;
	if (_grade >= 150)
		throw GradeTooLowException(); 
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low.";
}

std::ostream& operator<<(std::ostream& dest, const Bureaucrat& src)
{
	dest << src.getName();
	dest << ", bureaucrat grade ";
	dest << src.getGrade();
	dest << ".";
	return dest;
}