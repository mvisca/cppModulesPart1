/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:00:00 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/07 13:07:55 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
    : AMateria("ice")
{
    // std::cout << "+ Ice llama a constructor _type de AMateria." << std::endl;
}

Ice::Ice(const Ice& other)
    : AMateria(other)
{
    // std::cout << "+ Ice llama a constructor &other de AMateria." << std::endl;
}

Ice::~Ice()
{
    // std::cout << "- Ice destructor llamado." << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        // std::cout << "= Ice operador asignación llamado." << std::endl;
    }
    return *this;
}

AMateria* Ice::clone() const
{
    // std::cout << "! Clone Ice llamado." << std::endl;
    return new Ice(*this);
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}