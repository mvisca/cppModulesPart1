/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:03:47 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 15:23:32 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap("nn_clap_name"),
      ScavTrap(),
      FragTrap()
{
    _name = "nn_diamond_name";
    _life = 100;
    _ener = 50;
    _atta = 30;
    std::cout << "+ DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name(name)
{
    _life = 100;
    _ener = 50;
    _atta = 30;
    std::cout << "+ DiamondTrap param(\"" << _name << "\") constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Name " << _name << std::endl;
    std::cout << "Clap Name " << ClapTrap::getName() << std::endl;
    std::cout << "Life " << _life << std::endl;
    std::cout << "Energy " << _ener << std::endl;
    std::cout << "Attack " << _atta << std::endl;
}