/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:53:24 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 18:04:59 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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

        const std::string getName(void) const;
        unsigned int getLife(void) const;
        unsigned int getEner(void) const;
        unsigned int getAtta(void) const;
        void setName(const std::string& name);
        void setLife(unsigned int amount);
        void setEner(unsigned int amount);
        void setAtta(unsigned int amount);
};