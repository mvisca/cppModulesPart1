/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:29:02 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 20:22:13 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _slots[4];
        int _amCount;
        
    public:
        Character();
        Character(const Character& other);
        Character(const std::string name);
        ~Character();

        Character& operator=(const Character& other);
        
        const std::string& getName() const;
        const AMateria* getAM(int i) const;
        int Character::getAMCount() const;
        
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif