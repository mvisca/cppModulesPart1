/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:23 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 19:26:14 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();

        Cure(const Cure& other);

        Cure& operator=(const Cure& other);

        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
