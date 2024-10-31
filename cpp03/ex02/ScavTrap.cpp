#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    setLife(100);
    setEnergy(50);
    setAttack(20);
	std::cout << "Constructor con parámetro 'name' de ScavTrap llamado." << std::endl;
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