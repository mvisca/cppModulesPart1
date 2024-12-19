#include "ClapTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    // Inicialización de los ClapTraps
    ClapTrap claptrap0;
    ClapTrap claptrap1base("Fighter1", 10, 10, 3);
    ClapTrap claptrap1(claptrap1base); // Creación de claptrap3 como copia de claptrap1
    ClapTrap claptrap2("Fighter2", 10, 10, 5);
    ClapTrap claptrap3("Fighter3", 10, 10, 8);

    int attack1 = 3;
    int attack2 = 5;

    // Primera batalla entre claptrap1 y claptrap2
    std::cout << BOLD << CYAN << "\n--- Primera Batalla: Fighter1 vs Fighter2 ---\n" << RESET << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << BOLD << MAGENTA << "\n--- Ronda " << (i + 1) << " ---" << RESET << std::endl;
        
        std::cout << GREEN;
        claptrap1.attack("Fighter2");
        std::cout << RESET;
        std::cout << RED;
        claptrap2.takeDamage(attack1);
        std::cout << RESET;
        
        std::cout << RED;
        claptrap2.attack("Fighter1");
        std::cout << RESET;
        std::cout << GREEN;
        claptrap1.takeDamage(attack2);
        std::cout << RESET;
    }

    // Reparación de los luchadores después de las batallas
    std::cout << BOLD << CYAN << "\n--- Reparación de los Luchadores ---\n" << RESET << std::endl;
    
    std::cout << GREEN;
    claptrap1.beRepaired(5);
    std::cout << RESET;
    
    std::cout << RED;
    claptrap2.beRepaired(5);
    std::cout << RESET;

    // Segunda batalla entre claptrap3 y claptrap2
    std::cout << BOLD << CYAN << "\n--- Segunda Batalla: Fighter3 (copia de Fighter1) vs Fighter2 ---\n" << RESET << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << BOLD << MAGENTA << "\n--- Ronda " << (i + 1) << " ---" << RESET << std::endl;
        
        std::cout << BLUE;
        claptrap3.attack("Fighter2");
        std::cout << RESET;
        std::cout << RED;
        claptrap2.takeDamage(attack1);
        std::cout << RESET;

        std::cout << RED;
        claptrap2.attack("Fighter3");
        std::cout << RESET;
        std::cout << BLUE;
        claptrap3.takeDamage(attack2);
        std::cout << RESET;
    }

    return 0;
}
