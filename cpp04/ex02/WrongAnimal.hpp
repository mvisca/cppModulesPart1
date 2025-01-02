/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:00:47 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 18:00:51 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

	public:
		//----- Constructor -----//
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);

		//----- Destructor -----//
		~WrongAnimal();

		//----- Assign operator -----//
		WrongAnimal& operator=(const WrongAnimal& other);

		//----- Member function -----//
		void makeSound(void) const;

		//-----Getter -----//
		std::string getType(void) const;

	protected:
		//----- Member -----//
		std::string _type;
};

#endif
