#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {

	public:

		//----- Constructor -----//
		Cat();

		//----- Member function -----//
		void makeSound(void) const;
	
		//----- Destructor -----//
		~Cat();
};

#endif