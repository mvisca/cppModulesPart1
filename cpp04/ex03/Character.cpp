/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:59 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 22:05:39 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
    : _name("noName"),
      _amCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = 0;
    }
    std::cout << "Character def constructor llamado." << std::endl;
}

Character::Character(const Character& other)
    : _name(other.getName()),
      _amCount(other.getAMCount())
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = other._slots[i]->clone();
    }
    std::cout << "Character copia constructor llamado." << std::endl;
}

Character::Character(const std::string name)
    : _name(name),
      _amCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        _slots[i] = 0;
    }
    std::cout << "Character param(\"" << name << "\") constructor llamado." << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other.getName();
        this->_amCount = other.getAMCount();
        for (int i = 0; i < _amCount; i++)
        {
            delete _slots[i];
            _slots[i] = 0;
            if (other._slots[i]->clone())
                _slots[i] = other._slots[i]->clone();
        }
        std::cout << "Character operador asignación llamado." << std::endl;    
    }
}

const std::string& Character::getName() const {return _name;}
const AMateria* Character::getAM(int i) const {return _slots[i];}
int Character::getAMCount() const {return _amCount;}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}