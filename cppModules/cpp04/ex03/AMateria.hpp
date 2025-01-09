/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:57:52 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/07 13:16:36 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        AMateria();
        static AMateria* _all[100];

    public:
        AMateria(const std::string& type);
        AMateria(const AMateria& other);

        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        const std::string& getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        static bool storedInAll(AMateria* m);
        static void clearAll(void);
};

#endif