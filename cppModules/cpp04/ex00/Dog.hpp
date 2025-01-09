/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:59:13 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 17:59:16 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:

		//----- Constructor -----//
		Dog();
		Dog(const Dog& other);

		//----- Destructor -----//
		~Dog();

		//----- Assign operator -----//
		Dog& operator=(const Dog& other);

		//----- Member function -----//
		void makeSound(void) const;
};

#endif