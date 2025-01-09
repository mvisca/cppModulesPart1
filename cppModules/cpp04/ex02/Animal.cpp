/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:06:00 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 14:32:33 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//----- Constructor -----//
Animal::Animal()
	: _type("Animal")
{
	std::cout << "+ Construtor default Animal llamado." << std::endl; 
}

Animal::Animal(const Animal& other)
	: _type(other._type)
{
	std::cout << "+ Construtor copia Animal llamado." << std::endl; 
}

//----- Desctructor -----//
Animal::~Animal()
{
	std::cout << "- Destructor Animal llamado." << std::endl; 
}

//----- Assign operator -----//
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "= Operador asignación Animal llamado." << std::endl;
	return *this;
}

//----- Getter -----//
std::string Animal::getType(void) const {return _type;}