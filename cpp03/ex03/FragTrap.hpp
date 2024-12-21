#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		//------- CONSTRUCTOR -------//
		FragTrap();
		FragTrap(const std::string& name);

		//------- FUNCTIONS -------//
		void attack(const std::string& target);
		void highFivesGuys(void);

		//------- DESTRUCTOR -------//
		~FragTrap();

		//------- GETTERS AND SETTERS -------//
		std::string getName(void) const;
		int getAttack(void) const;
		int getEnergy(void) const;
		int getLife(void) const;
		void setName(std::string name);
		void setAttack(int amount);
		void setEnergy(int amount);
		void setLife(int amount);
};

#endif