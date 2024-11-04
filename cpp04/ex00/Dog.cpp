#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

//----- Constructor -----// 
Dog::Dog() : Animal() {
    _type = "Dog";
	std::cout << "Constructor de Dog llamado." << std::endl; 
}

void Dog::makeSound(void) const {
    std::cout << "Dog🐶: ¡Guau guau!" << std::endl;
}

//----- Destructor -----//
Dog::~Dog() {
	std::cout << "Destructor de Dog llamado." << std::endl; 
}