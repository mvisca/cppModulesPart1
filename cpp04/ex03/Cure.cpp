/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:20 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/05 23:17:05 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") 
{
    std::cout << "Cure AMateria def constructor llamado." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) 
{
    std::cout << "Cure AMateria copia constructor llamado." << std::endl;
}

Cure& Cure::operator=(const Cure& other) 
{
    if (this != &other) {
        AMateria::operator=(other); // Llama al operador de asignación de la clase base
    }
    std::cout << "Cure materia assigned." << std::endl;
    return *this;
}

Cure::~Cure() 
{
    std::cout << "Cure materia destroyed." << std::endl;
}

AMateria* Cure::clone() const 
{
    return new Cure(*this); // Devuelve una copia profunda.
}

void Cure::use(ICharacter& target) 
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}