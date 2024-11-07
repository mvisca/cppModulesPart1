#include "WrongCat.hpp"

//----- Constructor -----// 
WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "Constructor de WrongCat llamado." << std::endl; 
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "Constructor por copia de WrongCat llamado." << std::endl;
}

//----- Assign operator -----//
WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "Operador de asignación ('=') de WrongCat llamado." << std::endl;
	return *this;
}

//----- Destructor -----//
WrongCat::~WrongCat() {
	std::cout << "Destructor de WrongCat llamado." << std::endl; 
}

//----- Member function -----//
void WrongCat::makeSound(void) const {
	std::cout << "WrongCat🐯: ¡Grrrggg!" << std::endl;
}
