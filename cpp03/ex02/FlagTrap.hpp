#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
	public:
		FlagTrap(std::string name);

		void attack(const std::string& target);
		void guardGate(void);

		~FlagTrap();
};

#endif