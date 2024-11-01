#include <string>
#include <iostream>

class ClapTrap {

public:

	//------- CONSTRUCTOR -------//
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string &name, int life, int energy, int attack);

	//------- ASSIGN OPERATOR -------//
	ClapTrap &operator=(const ClapTrap &other);

	//------- GETTERS AND SETTERS -------//
	// std::string& ClapTrap::getName(void);
	// int getValue(std::string value);
	// void ClapTrap::setName(std::string name);
	// void ClapTrap::setValue(std::string value, int amount);

	//------- FUNCTIONS -------//
	void attack(const std::string target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//------- aaaa -------//
	~ClapTrap();

private:

	std::string _name;
	int _life;
	int _energy;
	int _attack;
};