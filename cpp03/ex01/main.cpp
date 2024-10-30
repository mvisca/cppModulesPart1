#include <iostream>
#include "ScavTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

int main() {
    std::cout << RED << "Creando ScavTrap rojo" << RESET << std::endl;
    ScavTrap redScav("RedScav");
    redScav.attack("enemy");
    redScav.guardGate();

    std::cout << GREEN << "\nCreando ScavTrap verde" << RESET << std::endl;
    ScavTrap greenScav("GreenScav");
    greenScav.attack("enemy");
    greenScav.takeDamage(30);
    greenScav.beRepaired(20);

    std::cout << BLUE << "\nCreando ScavTrap azul" << RESET << std::endl;
    ScavTrap blueScav("BlueScav");
    blueScav.attack("enemy");
    blueScav.takeDamage(110);
}