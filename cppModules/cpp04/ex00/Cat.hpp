/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:58:46 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 17:58:50 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:

		//----- Constructor -----//
		Cat();
		Cat(const Cat& other);

		//----- Destructor -----//
		~Cat();

		//----- Assign operator -----//
		Cat& operator=(const Cat& other);

		//----- Member function -----//
		void makeSound(void) const;
};

#endif