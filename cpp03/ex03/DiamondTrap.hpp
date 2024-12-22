#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
	public:
		//------- CONSTRUCTOR -------//
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);

		//------- OPERADOR DE ASIGNACION ------//
		DiamondTrap& operator = (const DiamondTrap& other);

		//------- DESTRUCTOR -------//
		~DiamondTrap();

        //------- GETTER -------//
        std::string& getName();

		//------- FUNCTIONS -------//
		void whoAmI();
		using ScavTrap::attack;


    private:
        std::string _name;
};

#endif