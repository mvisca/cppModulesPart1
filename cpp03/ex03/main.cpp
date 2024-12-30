#include "DiamondTrap.hpp"

// Colores ANSI
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"
 
int main() {

    std::cout << GREEN;
    
    DiamondTrap first("First");

    std::cout << MAGENTA;
    DiamondTrap second("Second");

    std::cout << GREEN;
    DiamondTrap third;

    third = second;

    first.whoAmI();

    std::cout << MAGENTA;
    second.whoAmI();

    std::cout << GREEN;
    third.whoAmI();

    std::cout << RED;
    return 0;
}
