/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:01:13 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 18:01:16 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
    //----- Constructor -----//
    WrongCat();
    WrongCat(const WrongCat& other);

    //----- Destructor -----//
    ~WrongCat();

    WrongCat& operator=(const WrongCat& other);

    //----- Member function -----//
    void makeSound(void) const;

    //----- Getter -----//
    const std::string& getType(void) const; 
};

#endif