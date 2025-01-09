/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:06:07 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 13:42:23 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	protected:
		//----- Member -----//
		std::string _type;

	public:
		//----- Constructor -----//
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		//----- Assign operator -----//
		Animal& operator=(const Animal& other);

		//----- Member function -----//
		virtual void makeSound(void) const;

		//-----Getter -----//
		std::string getType(void) const;
};

#endif
