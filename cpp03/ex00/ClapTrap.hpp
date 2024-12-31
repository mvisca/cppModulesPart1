/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:53:24 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 17:07:58 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
    private:
        std::string     _name;
        unsigned int    _life;
        unsigned int    _ener;
        unsigned int    _atta;
    public:
        ClapTrap(void);
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap(void);
        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        const std::string getName(void);
};

#endif