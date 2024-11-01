#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		//------- CONSTRUCTOR -------//
		FragTrap(const std::string& name);

		//------- FUNCTIONS -------//
		void attack(const std::string& target);
		void highFivesGuys(void);

		//------- DESTRUCTOR -------//
		~FragTrap();
};

#endif