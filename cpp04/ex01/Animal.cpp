#include "Animal.hpp"

//----- Constructor -----//
Animal::Animal() : _type("Gaira") {
	std::cout << "Construtor default de Animal llamado." << std::endl; 
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Construtor por copia de Animal llamado." << std::endl; 
}

//----- Assign operator -----//
Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Operador de asignación ('=') Animal usado." << std::endl;
	return *this;
}

//----- Desctructor -----//
Animal::~Animal() {
	std::cout << "Destructor de Animal llamado." << std::endl; 
}

//----- Member function -----//
void Animal::makeSound(void) const {
	std::cout << "Animal🐵: ¡Uhhh uhhh uhhh!" << std::endl;
}

//----- Getter -----//
std::string Animal::getType(void) const {
	return _type;
}

