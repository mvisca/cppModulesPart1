/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:59:02 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 13:57:40 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

//----- Constructor -----// 
Dog::Dog() : Animal()
{
    _type = "Dog";
    _ideas = new Brain();
	std::cout << "Constructor default Dog llamado." << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other)
{
    _ideas = new Brain(*other._ideas);
	std::cout << "Constructor copia Dog llamado." << std::endl;
}

//----- Destructor -----//
Dog::~Dog()
{
    delete _ideas;
	std::cout << "Destructor Dog llamado." << std::endl; 
}

//----- Assign operator -----//
Dog& Dog::operator=(const Dog& other)
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
    std::cout << "Operador asignación ('=') Dog llamado." << std::endl;
    return *this;
}

//----- Member function -----//
void Dog::makeSound(void) const
{
    std::cout << "🐶: ¡Guau guau!" << std::endl;
}

Brain& Dog::getBrain(void)
{
    return *this->_ideas;
}
