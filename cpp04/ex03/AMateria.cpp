/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:15:55 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/05 23:13:11 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
    : _type("a_materia")
{
    std::cout << "AMateria def constructor llamado." << std::endl;
}

AMateria::AMateria(const AMateria& other)
    : _type(other._type)
{
    std::cout << "AMateria copia constructor llamado." << std::endl;
}

AMateria::AMateria(const std::string& type)
    : _type(type)
{
    std::cout << "AMateria param(\"" << type << "\") constructor llamado." << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor llamado." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        _type = other._type;
        std::cout << "AMateria operador asignación llamado." << std::endl;
    }
    return *this;
}

const std::string& AMateria::getType() const {return _type;}