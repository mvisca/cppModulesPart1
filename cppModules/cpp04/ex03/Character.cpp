/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:59 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/07 13:50:21 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
    : _name("noName")
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = 0;
    }
    std::cout << "+ Character def constructor llamado." << std::endl;
}

Character::Character(const Character& other)
    : _name(other.getName())
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = 0;
        if (other._slots[i])
        {
            _slots[i] = other._slots[i]->clone();
        }
    }
    std::cout << "+ Character copia constructor llamado." << std::endl;
}

Character::Character(const std::string name)
    : _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = 0;
    }
    std::cout << "+ Character param(\"" << name << "\") constructor llamado." << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) {
        if (_slots[i]) {
            delete _slots[i];
            _slots[i] = NULL;
        }
    }

    std::cout << "- Character destructor llamado." << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;

        for (int i = 0; i < 4; i++)
        {
            // if (_slots[i])
            // {
            //     delete _slots[i];
            // }
            _slots[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (other._slots[i])
            {
                _slots[i] = other._slots[i]->clone();
            }
        }
    }

    std::cout << "= Character operador asignación llamado." << std::endl;
    return *this;
}

const std::string& Character::getName() const {return _name;}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Fallo Equip: materia parámetro vacía" << std::endl;
        return;
    }

    int emptySlot = -1;
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == m)
        {
            std::cout << "Fallo: Character \"" << _name << " ya tiene Materia [" << m->getType() << "] en el Slot [" << i << "]" << std::endl;
            return;
        }
        if (_slots[i] == 0 && emptySlot == -1)
        {
            emptySlot = i;
        }
    }
    
    if (emptySlot == -1)
    {
        std::cout << "Fallo: Character \"" << _name << "\" tiene el inventario lleno" << std::endl;
        return;    
    }

    _slots[emptySlot] = m;
    std::cout << "Exito Equip: Character \"" << _name << "\" ha equipado Materia [" << m->getType() << "] en el Slot [" << emptySlot << "]" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !_slots[idx])
    {
        std::cout << "Fallo Unequip: índice inválido." << std::endl;
        return;
    }
    std::cout << "Exito Unequip: Materia " << _slots[idx]->getType() << std::endl;
    _slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (_slots[idx] != 0)
        {
            _slots[idx]->use(target);
            // std::cout << "Exito Use: " << _slots[idx]->getType() << " usado por " << getName() << std::endl;
        }
        else
        {
            std::cout << "Fallo Use: no hay Materia en inventario con idx " << idx << " para " << getName() << std::endl;
        }
    }
    else
    {
        std::cout << "Fallo Use: idx fuera de rango (0..3)" << std::endl;
    }
}