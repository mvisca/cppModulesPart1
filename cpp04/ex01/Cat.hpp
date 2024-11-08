#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	public:

		//----- Constructor -----//
		Cat();
		Cat(const Cat& other);

		//----- Assign operator -----//
		Cat& operator=(const Cat& other);

		//----- Destructor -----//
		~Cat();
		
		//----- Member function -----//
		void makeSound(void) const;

	private:
		//----- Member _____//
		Brain _brain;

};

#endif
