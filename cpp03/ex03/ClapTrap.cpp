#include "ClapTrap.hpp"
#include <iostream>

//------- CONSTRUCTORS -------//
ClapTrap::ClapTrap()
	: _name("noName"),
	  _life(10),
	  _energy(10),_attack(0)
{
	std::cout << "Constructor por defecto de ClapTrap llamado." << std::endl;
}

ClapTrap::ClapTrap(const std::string name )
	: _name(name),
	_life(10),
	_energy(10),
	_attack(0)
{
	std::cout << "Constructor con parámetro nombre de ClapTrap llamado." << std::endl;
 }

ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other._name),
	_life(other._life),
	_energy(other._energy),
	_attack(other._attack)
{
	std::cout << "Constructor de copia de ClapTrap llamado." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, int life, int energy, int attack)
	: _name(name),
	  _life(life),
	  _energy(energy),
	  _attack(attack)
{
	std::cout << "Constructor con parámetros de ClapTrap llamado." << std::endl;
}

//------- ASSIGN OPERATOR -------//
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Operador de asignación de ClapTrap llamado." << std::endl;
	_name = other._name;
	_life = other._life;
	_energy = other._energy;
	_attack = other._attack;
	return *this;
}

//------- GETTERS Y SETTERS -------//
const std::string& ClapTrap::getName(void) const {return _name;}
int ClapTrap::getAttack(void) const {return _attack;}
int ClapTrap::getEnergy(void) const {return _energy;}
int ClapTrap::getLife(void) const {	return _life;}
void ClapTrap::setName(std::string name) {_name = name;}
void ClapTrap::setAttack(int amount) {_attack = amount;}
void ClapTrap::setEnergy(int amount) {_energy = amount;}
void ClapTrap::setLife(int amount) {_life = amount;}

//------- FUNCTIONS -------//
void ClapTrap::attack(const std::string target) {
	if (_energy < 1)
	{
		std::cout << _name << " no tiene suficiente energía para atacar." << std::endl;
		return;
	} else if (_life < 1) {
		std::cout << _name << " no puede atacar porque ha sido derrotado." << std::endl;
		return;
	}
	std::cout << _name << " ataca a " << target << ", causando " << _attack << " puntos de daño!" << std::endl;
	_energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_life < 1) {
		std::cout << _name << " no puede recibir daño porque ha sido derrotado." << std::endl;
		return;
	}
	_life -= amount;
	std::cout << _name << " recibe daño por " << amount << " puntos de vida y queda en " << (_life < 1 ? 0 : _life) << "." << std::endl;
	if (_life < 1) {
		std::cout << _name << " ha sido derrotado." << std::endl;
		_life = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy < 1)
	{
		std::cout << _name << " no tiene suficiente energía para repararse." << std::endl;
		return;
	} else if (_life < 1) {
		std::cout << _name << " no puede repararse porque ha sido derrotado." << std::endl;
		return;
	}
	_energy -= 1;
	_life += amount;
	std::cout << _name << " ha sido reparado en " << amount << " puntos y tiene ahora " << _life << " puntos de vida." << std::endl;

}

//------- DESTRUCTOR -------//
ClapTrap::~ClapTrap() { 
	std::cout << "Destructor de ClapTrap llamado para " << ClapTrap::getName() << "." << std::endl;
}