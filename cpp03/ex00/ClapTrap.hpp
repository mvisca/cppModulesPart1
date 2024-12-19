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
	ClapTrap(const ClapTrap &other);
	ClapTrap(const std::string &name, int life, int energy, int attack);

	//------- ASSIGN OPERATOR -------//
	ClapTrap &operator=(const ClapTrap &other);

	//------- FUNCTIONS -------//
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//------- DESTRUCTOR -------//
	~ClapTrap();
};