#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

//----- Constructor -----// 
WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
	std::cout << "Constructor de WrongCat llamado." << std::endl; 
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongCat🐯: ¡Grrrggg!" << std::endl;
}

//----- Destructor -----//
WrongCat::~WrongCat() {
	std::cout << "Destructor de WrongCat llamado." << std::endl; 
}