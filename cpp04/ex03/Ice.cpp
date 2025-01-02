/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:00 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 18:17:50 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
    : AMateria("ice")
{
    std::cout << "Ice def constructor llamado." << std::endl;
}

Ice::Ice(const Ice& other)
    : AMateria(other)
{
    std::cout << "Ice copia constructor llamado." << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "Ice operador asignación llamado." << std::endl;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor llamado." << std::endl;  
}

AMateria* Ice::clone() const
{
    std::cout << "Ice clone llamado." << std::endl;  
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}