#include "FragTrap.hpp"

//------- CONSTRUCTORS -------//
FragTrap::FragTrap() : ClapTrap("noName", 100, 100, 30) {
	std::cout << "Constructor por defecto de FragTrap llamado." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "Constructor con parámetro 'name' de FragTrap llamado." << std::endl;
}

//------- FUNCTIONS -------//
void FragTrap::attack(const std::string& target) {
	if (getEnergy() < 1)
	{
		std::cout << "FragTrap " << getName() << " no tiene suficiente energía para atacar." << std::endl;
		return;
	} else if (getLife() < 1) {
		std::cout << "FragTrap " << getName() << " no puede atacar porque ha sido derrotado." << std::endl;
		return;
	}
	std::cout << "¡FragTrap " << getName() << " ataca a " << target << ", causando " << getAttack() << " puntos de daño!" << std::endl;
	int temp = getEnergy();
	setEnergy(temp - 1);
}

void FragTrap::highFivesGuys(void) {
     std::cout << "¡FragTrap " << getName() << " está pidiendo un High Five!" << std::endl;
}

//------- DESTRUCTOR -------//
FragTrap::~FragTrap() {
	std::cout << "Destructor de FragTrap llamado para " << getName() << "." << std::endl;
}

//------- GETTERS Y SETTERS -------//
std::string FragTrap::getName(void) const {
	return getName();
}

int FragTrap::getAttack(void) const {
	return getAttack();
}

int FragTrap::getEnergy(void) const {
	return getEnergy();
}

int FragTrap::getLife(void) const {
	return getLife();
}

void FragTrap::setName(std::string name) {
	setName(name);
}

void FragTrap::setAttack(int amount) {
	setAttack(amount);
}

void FragTrap::setEnergy(int amount) {
	setEnergy(amount);
}

void FragTrap::setLife(int amount) {
	setLife(amount);
}