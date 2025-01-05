/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:59 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/05 23:41:47 by mvisca           ###   ########.fr       */
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
    for (int i = 0; i < 100; i++)
    {
        _unequiped[i] = NULL;
    }
    std::cout << "+ Character def constructor llamado." << std::endl;
}

Character::Character(const Character& other)
    : _name(other.getName())
{
    for (int i = 0; i < 4; i++)
    {
        if (other._slots[i])
        {
            _slots[i] = other._slots[i]->clone();
        }
    }
    for (int i = 0; i < 100; i++)
    {
        _unequiped[i] = NULL;
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
    for (int i = 0; i < 100; i++)
    {
        _unequiped[i] = NULL;
    }
    std::cout << "+ Character param(\"" << name << "\") constructor llamado." << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) {
        if (_slots[i]) {
            delete _slots[i];
            _slots[i] = NULL; // Evitar accesos posteriores inválidos
        }
    }

    for (int i = 0; i < 100; i++) {
        if (_unequiped[i]) {
            delete _unequiped[i];
            _unequiped[i] = NULL; // Evitar accesos posteriores inválidos
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
            if (_slots[i])
            {
                delete _slots[i];
            }
            _slots[i] = NULL; // Evitar basura
        }

        for (int i = 0; i < 4; i++)
        {
            if (other._slots[i])
            {
                _slots[i] = other._slots[i]->clone();
            }
        }

        for (int i = 0; i < 100; i++)
        {
            _unequiped[i] = NULL;
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
    // busca repetidos, si hay termina
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i] == m)
        {
            std::cout << "Fallo: Character \"" << _name << " ya tiene Materia [" << m->getType() << "] en el Slot [" << i << "]" << std::endl;
            return;
        }
    }

    // se podría hacer en un mismo bucle pero es confiar que siempre se guardarán materias desde el indice 0 al 3 de forma ascendente. Al separarlos en dos procesos es más autónomo y confiable.

    // busca vacío, si encuentra no hay repetidos, equipa y termina
    for (int i = 0; i < 4; i++)
    {
        if (!_slots[i])
        {
            _slots[i] = m;
            std::cout << "Exito: Character \"" << _name << "\" ha equipado Materia [" << m->getType() << "] en el Slot [" << i << "]" << std::endl;
            return;
        }
    }

    // ni repetidos, ni vacíos
    std::cout << "Fallo: Character \"" << _name << "\" tiene el inventario lleno" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i])
        {
            std::cout << "Materia: " << _slots[i]->getType() << ". Address: " << _slots[i] << std::endl;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !_slots[idx])
    {
        std::cout << "Fallo Unequip: índice inválido." << std::endl;
        return;
    }

    for (int i = 0; i < 100; i++) {
        if (!_unequiped[i])
        {
            _unequiped[i] = _slots[idx];
            _slots[idx] = NULL;
            std::cout << "Materia movida a _unequiped." << std::endl;
            return;
        }
    }

    std::cout << "Fallo Unequip: Sin espacio en _unequiped." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (_slots[idx] != 0)
        {
            _slots[idx]->use(target);
            std::cout << "Exito Use: " << _slots[idx]->getType() << " usado por " << getName() << std::endl;
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