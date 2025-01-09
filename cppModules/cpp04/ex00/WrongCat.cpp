/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:01:02 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 18:01:05 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//----- Constructor -----// 
WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "Constructor de WrongCat llamado." << std::endl; 
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "Constructor por copia de WrongCat llamado." << std::endl;
}

//----- Assign operator -----//
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "Operador de asignación ('=') de WrongCat llamado." << std::endl;
	return *this;
}

//----- Destructor -----//
WrongCat::~WrongCat()
{
	std::cout << "Destructor de WrongCat llamado." << std::endl; 
}

//----- Member function -----//
void WrongCat::makeSound(void) const
{
	std::cout << "🐯: ¡Grrrggg!" << std::endl;
}

//----- Getter -----//
const std::string& WrongCat::getType(void) const {return _type;}
