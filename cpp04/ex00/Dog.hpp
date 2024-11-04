#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {

	public:

		//----- Constructor -----//
		Dog();

		//----- Member function -----//
		void makeSound(void) const;
	
		//----- Destructor -----//
		~Dog();
};

#endif