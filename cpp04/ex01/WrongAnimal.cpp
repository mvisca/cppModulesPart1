#include "WrongAnimal.hpp"

//----- Constructor -----//
WrongAnimal::WrongAnimal() : _type("WrongGaira") {
	std::cout << "Construtor default de WrongAnimal llamado." << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "Construtor por copia de WrongAnimal llamado." << std::endl; 
}

//----- Assign operator  -----//
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << "Operador de asignación ('=') de WrongAnimal llamado." << std::endl; 
	return *this;
}

//----- Desctructor -----//
WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor de WrongAnimal llamado." << std::endl; 
}

//----- Member function -----//
void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal🐷: ¡Oinc oinc!" << std::endl;
}

//----- Getter -----//
std::string WrongAnimal::getType(void) const {
	return _type;
}
