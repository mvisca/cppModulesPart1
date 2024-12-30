#include "DiamondTrap.hpp"

//------- CONSTRUCTORS -------//
// Default
DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name"),
	  ScavTrap("default_clap_name"),
	  FragTrap("defa_clap_nameult"),
	  _name("default")
{
	this->setLife(FragTrap::getLife());
	FragTrap::setLife(FragTrap::getLife());
	ScavTrap::setLife(FragTrap::getLife());
	setEnergy(ScavTrap::getEnergy());
	setAttack(FragTrap::getAttack());
	std::cout << "Constructor default de DiamondTrap llamado." << std::endl;
}

// Name
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(name),
	  FragTrap(name),
	  _name(name)
{
	setLife(FragTrap::getLife());
	setEnergy(ScavTrap::getEnergy());
	setAttack(FragTrap::getAttack());
	std::cout << "Constructor con parámetro 'name' de DiamondTrap llamado." << std::endl;
}

// Copia
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other),
	  _name(other._name)
{
	std::cout << "Constructor por copia de DiamondTrap llamado." << std::endl;
}

//------- CONSTRUCTORS -------//
DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other) {
	if (this != &other)
	{
		ClapTrap::operator = (other);
		ScavTrap::operator = (other);
		FragTrap::operator = (other);
		_name = other._name;
		setLife(other.getLife());
		setEnergy(other.getEnergy());
		setAttack(other.getAttack());
	}
	return *this;
}

//------- GETTER -------//
std::string& DiamondTrap::getName() {
	return _name;
}
		
//------- FUNCTIONS -------//
void DiamondTrap::whoAmI() {
	std::cout << std::endl;
	std::cout << "DiamondTrap whoAmI llamado:" << std::endl;
	std::cout << "DiamondTrap _name -> " << getName() << std::endl;
	std::cout << "ClapTrap _name -> " << ClapTrap::getName() << std::endl;
	std::cout << "_life -> " << FragTrap::getLife() << std::endl;
	std::cout << "_energy -> " << ScavTrap::getEnergy() << std::endl;
	std::cout << "_attack -> " << FragTrap::getAttack() << std::endl;
	std::cout << std::endl;
}

//------- DESTRUCTOR -------//
DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor de DiamondTrap llamado." << std::endl; 
}