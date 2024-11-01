#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		//------- CONSTRUCTOR -------//
		DiamondTrap(const std::string& name);

        //------- GETTER -------//
        std::string& getName();

		//------- FUNCTIONS -------//
		void whoAmI();

		//------- DESTRUCTOR -------//
		~DiamondTrap();

    private:
        std::string _name;
};

#endif