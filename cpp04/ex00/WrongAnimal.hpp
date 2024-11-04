#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

	public:
		//----- Constructor -----//
		WrongAnimal();

		//----- Member function -----//
		void makeSound(void) const;

		//-----Getter -----//
		std::string getType(void) const;

		//----- Destructor -----//
		~WrongAnimal();

	protected:
		//----- Member -----//
		std::string _type;
};

#endif
