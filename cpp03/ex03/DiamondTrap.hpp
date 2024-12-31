/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:50:27 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 21:36:12 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap(void);
        DiamondTrap(const std::string& name);
        DiamondTrap(DiamondTrap& other);
        ~DiamondTrap(void);

        using ClapTrap::operator=;
        using ScavTrap::attack;

        void whoAmI(void);

};

#endif