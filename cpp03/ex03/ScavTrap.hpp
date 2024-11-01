#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		//------- CONSTRUCTOR -------//
		ScavTrap();
		ScavTrap(const std::string& name);

		//------- FUNCTIONS -------//
		void attack(const std::string& target);
		void guardGate(void);

		//------- DESTRUCTOR -------//
		~ScavTrap();
};

#endif