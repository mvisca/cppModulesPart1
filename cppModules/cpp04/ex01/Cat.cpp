/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:58:34 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 13:24:57 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

//----- Constructor -----// 
Cat::Cat()
    : Animal()
{
    _type = "Cat";
    _ideas = new Brain();
    std::cout << "Constructor default Cat llamado." << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other)
{
    _ideas = new Brain(*other._ideas);
    std::cout << "Constructor copia Cat llamado." << std::endl;
}

//----- Destructor -----//
Cat::~Cat()
{
    delete _ideas;
	std::cout << "Destructor Cat llamado." << std::endl; 
}

//----- Assign operator -----//
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        
        if (_ideas)
        {
            delete _ideas;
        }
        _ideas = new Brain(*other._ideas);
    }
    std::cout << "Operador asignación Cat llamado." << std::endl;
    return *this;
}

//----- Member function-----//
void Cat::makeSound(void) const
{
    std::cout << "🐱: ¡Miauuuuu!" << std::endl;
}
