/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:15:55 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/07 13:17:36 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria* AMateria::_all[100] = { 0 };

AMateria::AMateria()
    : _type("just_materia")
{
    bool stored = false;
    for (int i = 0; i < 100; i++)
    {
        if (_all[i] == NULL)
        {
            _all[i] = this;
            stored = true;
            // std::cout << "+ AMateria def constructor: Almacenada en _all[" << i << "]." << std::endl;
            break;
        }   
    }

    if (!stored)
    {
        throw std::runtime_error("Error: No hay espacio en _all para AMateria (def constructor)");
    }
}

AMateria::AMateria(const std::string& type)
    : _type(type)
{
    bool stored = false;
    for (int i = 0; i < 100; i++)
    {
        if (_all[i] == NULL)
        {
            _all[i] = this;
            stored = true;
            // std::cout << "+ AMateria param(\"" << type << "\") constructor: Almacenada en _all[" << i << "]." << std::endl;
            break;
        }
    }

    if (!stored)
    {
        throw std::runtime_error("Error: No hay espacio en _all para AMateria (param constructor)");
    }
}


AMateria::AMateria(const AMateria& other)
    : _type(other._type)
{
    bool stored = false;
    for (int i = 0; i < 100; i++)
    {
        if (_all[i] == NULL)
        {
            _all[i] = this;
            stored = true;
            // std::cout << "+ AMateria copia constructor: Copiada desde [" << other._type << "], almacenada en _all[" << i << "]." << std::endl;
            break;
        }
    }

    if (!stored)
    {
        throw std::runtime_error("Error: No hay espacio en _all para AMateria (copia constructor)");
    }
}

AMateria::~AMateria()
{
    bool removed = false;
    for (int i = 0; i < 100; i++)
    {
        if (_all[i] == this)
        {
            _all[i] = NULL;
            removed = true;
            // std::cout << "- AMateria destructor: Instancia [" << _type << "] eliminada de _all[" << i << "]." << std::endl;
            break;
        }
    }

    if (!removed)
    {
        std::cout << "! Advertencia: AMateria [" << _type << "] no estaba en _all al momento de la destrucción." << std::endl;
    }
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        _type = other._type;
        // std::cout << "= AMateria operador asignación llamado." << std::endl;
    }
    return *this;
}

const std::string& AMateria::getType() const {return _type;}

void AMateria::use(ICharacter& target)
{
    std::cout << "Use Materia llamado para " << target.getName() << ", este no debería verse porque es un metodo virtual puro." << std::endl;
}

bool AMateria::storedInAll(AMateria* m)
{
    for (int i = 0; i < 100; i++)
    {
        if (_all[i] == m) {
            std::cout << "Materia ya almacenada." << std::endl;
            return true;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (_all[i] == NULL)
        {
            _all[i] = m;
            std::cout << "AMateria almacenada en _all[" << i << "]" << std::endl;
            return true;
        }
    }
    throw std::runtime_error("Límite de AMateria _all alcanzado");
}

void AMateria::clearAll(void)
{
    for (int i = 0; i < 100; i++)
    {
        if (_all[i])
        {
            delete _all[i];
            _all[i] = NULL;
        }
    }
    std::cout << "- AMateria::clearAll: Todas las materias han sido eliminadas." << std::endl;
}