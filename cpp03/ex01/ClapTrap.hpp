#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

public:

	//------- CONSTRUCTOR -------//
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string &name, int life, int energy, int attack);

	//------- ASSIGN OPERATOR -------//
	ClapTrap &operator=(const ClapTrap &other);

	//------- GETTERS AND SETTERS -------//
	std::string& getName(void);
	int getAttack(void);
	int getEnergy(void);
	int getLife(void);
	void setName(std::string name);
	void setAttack(int amount);
	void setEnergy(int amount);
	void setLife(int amount);

	//------- FUNCTIONS -------//
	void attack(const std::string target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//------- DESTRUCTOR -------//
	~ClapTrap();

private:

	std::string _name;
	int _life;
	int _energy;
	int _attack;
};

#endif