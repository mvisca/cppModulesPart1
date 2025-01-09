/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:04:59 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/03 19:55:42 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        ~MateriaSource();

        MateriaSource& operator=(const MateriaSource& other);

        void learnMateria(AMateria* m);
        AMateria* createMateria(const std::string& type);
};

#endif