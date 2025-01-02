/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:58:34 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 17:58:37 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//----- Constructor -----// 
Cat::Cat()
    : Animal()
{
    _type = "Cat";
    std::cout << "Constructor default Cat llamado." << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Constructor copia Cat llamado." << std::endl;
}

//----- Destructor -----//
Cat::~Cat()
{
	std::cout << "Destructor Cat llamado." << std::endl; 
}

//----- Assign operator -----//
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Operador asignación Cat llamado." << std::endl;
    return *this;
}

//----- Member function-----//
void Cat::makeSound(void) const
{
    std::cout << "🐱: ¡Miauuuuu!" << std::endl;
}
