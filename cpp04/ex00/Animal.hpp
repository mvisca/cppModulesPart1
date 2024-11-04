#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	public:
		//----- Constructor -----//
		Animal();

		//----- Member function -----//
		virtual void makeSound(void) const;

		//-----Getter -----//
		std::string getType(void) const;

		//----- Destructor -----//
		virtual ~Animal();

	protected:
		//----- Member -----//
		std::string _type;
};

#endif
