/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:59:55 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 18:05:31 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("none"),
      _life(10),
      _ener(10),
      _atta(0)
{
    std::cout << "+ ClapTrap default called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _life(10),
      _ener(10),
      _atta(0)
{
    std::cout << "+ ClapTrap param(name) constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _life(other._life),
      _ener(other._ener),
      _atta(other._atta)
{
    std::cout << "+ ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "- ClapTrap destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _life = other._life;
        _ener = other._ener;
        _atta = other._atta;
        std::cout << "= ClapTrap assign operator called." << std::endl;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_ener > 0)
    {
        _ener -= 1;
        std::cout << "* ClapTrap "<< _name << " attacks " << target << " causing " << _atta << " points of damage." << std::endl;
    }
    else
    {
        std::cout << "* ClapTrap "<< _name << " cannot attack " << target << " because is out of energy." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_life > 0 && _life <= amount)
    {
        _life = 0;
        std::cout << "* ClapTrap "<< _name << " gets " << amount << " points of damages and is out of life." << std::endl;
    }
    else if (_life != 0)
    {
        _life -= amount;
        std::cout << "* ClapTrap "<< _name << " gets " << amount << " points of damages and now has " << _life << " points of life." << std::endl;
    }
    else
    {
        std::cout << "* ClapTrap "<< _name << " cannot be repaired attacked because is already out of life." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_ener > 0 && _life > 0)
    {
        _ener -= 1;
        _life += amount;
        std::cout << "* ClapTrap "<< _name << " gets repaired by " << amount << " points of life." << std::endl;
    }
    else if (_life == 0)
    {
        std::cout << "* ClapTrap "<< _name << " cannot be repaired because is already out of life." << std::endl;
    }
    else
    {
        std::cout << "* ClapTrap "<< _name << " cannot be repaired because is out of energy." << std::endl;
    }
}

const std::string ClapTrap::getName(void) const {return _name;}
unsigned int ClapTrap::getLife(void) const {return _life;}
unsigned int ClapTrap::getEner(void) const {return _ener;}
unsigned int ClapTrap::getAtta(void) const {return _atta;}
void ClapTrap::setName(const std::string& name) {_name = name;}
void ClapTrap::setLife(unsigned int amount) {_life = amount;}
void ClapTrap::setEner(unsigned int amount) {_ener = amount;}
void ClapTrap::setAtta(unsigned int amount) {_atta = amount;}