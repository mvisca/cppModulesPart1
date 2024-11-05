#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

//----- Constructor -----//
WrongAnimal::WrongAnimal() : _type("WrongGaira") {
	std::cout << "Construtor de WrongAnimal llamado." << std::endl; 
}

//----- Member function -----//
void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal🐷: ¡Oinc oinc!" << std::endl;
}

//----- Getter -----//
std::string WrongAnimal::getType(void) const {
	return _type;
}

//----- Desctructor -----//
WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor de WrongAnimal llamado." << std::endl; 
}