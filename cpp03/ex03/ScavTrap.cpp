#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {
	std::cout << "Constructor default de ScavTrap llamado." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "Constructor con parámetro 'name' = " << getName() << " de ScavTrap llamado." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.getName(), other.getLife(), other.getEnergy(), other.getAttack()) {
	std::cout << "Constructor con parámetro 'name' = " << getName() << " de ScavTrap llamado." << std::endl;
}

ScavTrap& ScavTrap:: operator = (const ScavTrap& other){
	if (this != &other)
	{
		setName(other.getName());
		setLife(other.getLife());
		setEnergy(other.getEnergy());
		setAttack(other.getAttack());
	}
	std::cout << "Operador de asignación de ScavTrap llamado." << std::endl;
	return (*this);
}

//------- FUNCTIONS -------//
void ScavTrap::attack(const std::string& target) {
	if (getEnergy() < 1)
	{
		std::cout << "ScavTrap " << getName() << " no tiene suficiente energía para atacar." << std::endl;
		return;
	} else if (getLife() < 1) {
		std::cout << "ScavTrap " << getName() << " no puede atacar porque ha sido derrotado." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << getName() << " ataca a " << target << ", causando " << getAttack() << " puntos de daño!" << std::endl;
	int temp = getEnergy();
	setEnergy(temp - 1);
}

void ScavTrap::guardGate(void) {
     std::cout << "¡ScavTrap " << getName() << " ha activado el modo Gatekeeper!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor de ScavTrap llamado para " << getName() << "." << std::endl;
}