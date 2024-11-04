#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

//----- Constructor -----// 
Cat::Cat() : Animal() {
    _type = "Cat";
	std::cout << "Constructor de Cat llamado." << std::endl; 
}

void Cat::makeSound(void) const {
    std::cout << "Cat🐱: ¡Miauuuuu!" << std::endl;
}

//----- Destructor -----//
Cat::~Cat() {
	std::cout << "Destructor de Cat llamado." << std::endl; 
}