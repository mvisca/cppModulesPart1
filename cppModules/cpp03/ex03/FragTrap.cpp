/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:28:24 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 15:21:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
    : ClapTrap()
{
    _life = 100;
    _ener = 100;
    _atta = 30;
    std::cout << "+ FragTrap default created." << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    setLife(100);
    setEner(100);
    setAtta(30);
    std::cout << "+ FragTrap param(\"" << name << "\") created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "+ FragTrap param(FragTrap::\"" << getName() << "\") created." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "- FragTrap destructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (&other != this)
    {
        setLife(other.getLife());
        setEner(other.getEner());
        setAtta(other.getAtta());
        setName(other.getName());
        std::cout << "+ FragTrap assign operator called." << std::endl;
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (getEner() > 0)
    {
        setEner(getEner() - 1);
        std::cout << "* FragTrap "<< getName() << " attacks " << target << " causing " << getAtta() << " points of damage." << std::endl;
    }
    else
    {
        std::cout << "* FragTrap "<< getName() << " cannot attack " << target << " because is out of energy." << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (getLife() > 0 && getLife() <= amount)
    {
        setLife(0);
        std::cout << "* FragTrap "<< getName() << " gets " << amount << " points of damages and is out of life." << std::endl;
    }
    else if (getLife() != 0)
    {
        setLife(getLife() - amount);
        std::cout << "* FragTrap "<< getName() << " gets " << amount << " points of damages and now has " << getLife() << " points of life." << std::endl;
    }
    else
    {
        std::cout << "* FragTrap "<< getName() << " cannot be repaired attacked because is already out of life." << std::endl;
    }
}


void FragTrap::beRepaired(unsigned int amount)
{
    if (getEner() > 0 && getLife() > 0)
    {
        setEner(getEner() - 1);
        setLife(getLife() + amount);
        std::cout << "* FragTrap "<< getName() << " gets repaired by " << amount << " points of life." << std::endl;
    }
    else if (getLife() == 0)
    {
        std::cout << "* FragTrap "<< getName() << " cannot be repaired because is already out of life." << std::endl;
    }
    else
    {
        std::cout << "* FragTrap "<< getName() << " cannot be repaired because is out of energy." << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    if (getEner() > 0)
    {
    	std::cout << "! FragTrap " << getName() << " says High Five Guys!" << std::endl;    
    }
    else
    {
    	std::cout << "! FragTrap " << getName() << " cannot say High Five Guys because is out of energy." << std::endl;    
    }
}