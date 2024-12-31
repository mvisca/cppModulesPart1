/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:48 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 18:38:46 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
    : ClapTrap()
{
    setLife(100);
    setEner(50);
    setAtta(20);
    std::cout << "+ ScavTrap default created." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    setLife(100);
    setEner(50);
    setAtta(20);
    std::cout << "+ ScavTrap param(\"" << name << "\") created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "+ ScavTrap param(ScavTrap::\"" << getName() << "\") created." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "- ScavTrap destructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (&other != this)
    {
        setLife(other.getLife());
        setEner(other.getEner());
        setAtta(other.getAtta());
        setName(other.getName());
        std::cout << "+ ScavTrap assign operator called." << std::endl;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (getEner() > 0)
    {
        setEner(getEner() - 1);
        std::cout << "* ScavTrap "<< getName() << " attacks " << target << " causing " << getAtta() << " points of damage." << std::endl;
    }
    else
    {
        std::cout << "* ScavTrap "<< getName() << " cannot attack " << target << " because is out of energy." << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (getLife() > 0 && getLife() <= amount)
    {
        setLife(0);
        std::cout << "* ScavTrap "<< getName() << " gets " << amount << " points of damages and is out of life." << std::endl;
    }
    else if (getLife() != 0)
    {
        setLife(getLife() - amount);
        std::cout << "* ScavTrap "<< getName() << " gets " << amount << " points of damages and now has " << getLife() << " points of life." << std::endl;
    }
    else
    {
        std::cout << "* ScavTrap "<< getName() << " cannot be repaired attacked because is already out of life." << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (getEner() > 0 && getLife() > 0)
    {
        setEner(getEner() - 1);
        setLife(getLife() + amount);
        std::cout << "* ScavTrap "<< getName() << " gets repaired by " << amount << " points of life." << std::endl;
    }
    else if (getLife() == 0)
    {
        std::cout << "* ScavTrap "<< getName() << " cannot be repaired because is already out of life." << std::endl;
    }
    else
    {
        std::cout << "* ScavTrap "<< getName() << " cannot be repaired because is out of energy." << std::endl;
    }
}

void ScavTrap::guardGate(void)
{
    if (getEner() > 0)
    {
    	std::cout << "! ScavTrap " << getName() << " switches to Guard Gate mode." << std::endl;    
    }
    else
    {
    	std::cout << "! ScavTrap " << getName() << " cannot enter Guard Gate mode because is out of energy." << std::endl;    
    }
}