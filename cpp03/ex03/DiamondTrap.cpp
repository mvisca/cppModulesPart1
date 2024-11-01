#include "DiamondTrap.hpp"

//------- CONSTRUCTORS -------//
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name(name) {
	std::cout << "Constructor con parámetro 'name' de DiamondTrap llamado." << std::endl;
}

//------- GETTER -------//
std::string& DiamondTrap::getName() {
	return _name;
}
		
//------- FUNCTIONS -------//
void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap whoAmI llamado: _name -> " << getName() << " | ClapTrap::_name -> " << ClapTrap::getName() << "." << std::endl; 
}

//------- DESTRUCTOR -------//
DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor de DiamondTrap llamado." << std::endl; 
}