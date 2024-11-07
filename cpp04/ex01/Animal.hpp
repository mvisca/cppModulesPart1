#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	public:
		//----- Constructor -----//
		Animal();
		Animal(const Animal& other);

		//----- Assign operator -----//
		Animal& operator=(const Animal& other);

		//----- Destructor -----//
		virtual ~Animal();

		//----- Member function -----//
		virtual void makeSound(void) const;

		//-----Getter -----//
		std::string getType(void) const;


	protected:
		//----- Member -----//
		std::string _type;
};

#endif
