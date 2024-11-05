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

		//----- Assign operator -----//
		WrongAnimal& operator=(const WrongAnimal& other);

		//----- Destructor -----//
		// En este caso se implementa 'virtual' para evitar fugas de memoria
		// a pesar de que se busca con esta clase dar el ejemplo de una mala
		// implementación de polimorfismo.
		// Para habilitar la completa implementción erronea comentar la 
		// siguiente línea y descomentar la posterior.
		virtual ~WrongAnimal();
		//~WrongAnimal();


		//----- Member function -----//
		void makeSound(void) const;

		//-----Getter -----//
		std::string getType(void) const;

	protected:
		//----- Member -----//
		std::string _type;
};

#endif
