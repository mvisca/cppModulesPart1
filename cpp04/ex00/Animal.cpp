#include "Animal.hpp"
#include <iostream>
#include <string>

//----- Constructor -----//
Animal::Animal() : _type("Gaira") {
	std::cout << "Construtor de Animal llamado." << std::endl; 
}

//----- Member function -----//
void Animal::makeSound(void) const {
	std::cout << "Animal🐵: ¡Uhhh uhhh uhhh!" << std::endl;
}

//----- Getter -----//
std::string Animal::getType(void) const {
	return _type;
}

//----- Desctructor -----//
Animal::~Animal() {
	std::cout << "Destructor de Animal llamado." << std::endl; 
}

