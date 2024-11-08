#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain _brain;

	public:

		//----- Constructor -----//
		Dog();
		Dog(const Dog& other);

		//----- Assign operator -----//
		Dog& operator=(const Dog& other);
	
		//----- Destructor -----//
		~Dog();

		//----- Member function -----//
		void makeSound(void) const;
};

#endif
