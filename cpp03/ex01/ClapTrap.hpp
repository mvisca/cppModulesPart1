#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

private:
	std::string _name;
	int _life;
	int _energy;
	int _attack;

public:
	//------- CONSTRUCTOR -------//
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string &name, int life, int energy, int attack);

	//------- ASSIGN OPERATOR -------//
	ClapTrap& operator= (const ClapTrap &other);

	//------- FUNCTIONS -------//
	void attack(const std::string target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//------- DESTRUCTOR -------//
	~ClapTrap();

	//------- GETTERS AND SETTERS -------//
	const std::string getName(void) const;
	int getAttack(void) const;
	int getEnergy(void) const;
	int getLife(void) const;
	void setName(std::string name);
	void setAttack(int amount);
	void setEnergy(int amount);
	void setLife(int amount);
};

#endif