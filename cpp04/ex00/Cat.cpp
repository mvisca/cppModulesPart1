#include "Cat.hpp"

//----- Constructor -----// 
Cat::Cat() : Animal() {
    _type = "Cat";
	std::cout << "Constructor default de Cat llamado." << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Constructor por copia de Cat llamado." << std::endl;
}

//----- Assign operator -----//
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Operador de asignación de Cat llamado." << std::endl;
    return *this;
}

//----- Destructor -----//
Cat::~Cat() {
	std::cout << "Destructor de Cat llamado." << std::endl; 
}

//----- Member function-----//
void Cat::makeSound(void) const {
    std::cout << "Cat🐱: ¡Miauuuuu!" << std::endl;
}
