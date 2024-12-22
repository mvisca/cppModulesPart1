#include "DiamondTrap.hpp"

// Colores ANSI
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define RED "\033[31m"
#define GREEN "\033[32m"

// Función para verificar si un objeto está vivo
bool isAlive(ClapTrap& character) {
    return character.getLife() > 0;
}
 
int main() {

/*FragTrap fdef(¨fdef, 100, 100, 50);
    DiamondTrap* d_fdef;
    d_fdef = &fdef;
*/
    DiamondTrap ddef;
    ddef.whoAmI();


    /*// Inicializamos los personajes
    std::cout << "Crea DiamondTrap" << std::endl;
    DiamondTrap diamond("DIAMONDER");
    std::cout << std::endl;

    std::cout << "Crea FragTrap" << std::endl;
    FragTrap frag("FRAGER");
    std::cout << std::endl;

    std::cout << "Crea ScavTrap" << std::endl;
    ScavTrap scav("SCAVER");
    std::cout << std::endl;

    std::cout << "\n--- ¿Quién es DIAMONDER? ---" << std::endl;
    diamond.whoAmI();
    std::cout << std::endl;

    // Punteros a los personajes para facilitar el acceso en un orden cíclico
    ClapTrap* fighters[3] = { &diamond, &frag, &scav };
    int aliveCount = 3;

    // Comienza el combate
    while (aliveCount > 1) {
        for (int i = 0; i < 3; ++i) {
            // Verifica si el personaje actual está vivo
            if (!isAlive(*fighters[i])) continue;

            // Determinar el índice del objetivo en orden cíclico
            int targetIndex = (i + 1) % 3;

            // Si el objetivo no está vivo, continúa al siguiente
            if (!isAlive(*fighters[targetIndex])) continue;

            // Ataque del personaje actual al objetivo
            if (fighters[i] == &diamond) {
                std::cout << MAGENTA;
                diamond.FragTrap::attack(fighters[targetIndex]->getName());
                fighters[targetIndex]->takeDamage(diamond.getAttack());
                std::cout << RESET;
            } else if (fighters[i] == &frag) {
                std::cout << RED;
                frag.attack(fighters[targetIndex]->getName());
                fighters[targetIndex]->takeDamage(frag.getAttack());
                std::cout << RESET;
            } else if (fighters[i] == &scav) {
                std::cout << GREEN;
                scav.attack(fighters[targetIndex]->getName());
                fighters[targetIndex]->takeDamage(scav.getAttack());
                std::cout << RESET;
            }

            // Actualizamos el contador de personajes vivos
            aliveCount = 0;
            for (int j = 0; j < 3; ++j) {
                if (isAlive(*fighters[j])) aliveCount++;
            }

            // Si solo queda uno con vida, terminamos el combate
            if (aliveCount == 1) break;
        }
    }

    // Declarar el ganador
    std::cout << "\n--- RESULTADO DEL COMBATE ---" << std::endl;
    for (int i = 0; i < 3; ++i) {
        if (isAlive(*fighters[i])) {
            if (fighters[i] == &diamond) std::cout << MAGENTA << diamond.getName() << " es el ganador!" << RESET << std::endl;
            else if (fighters[i] == &frag) std::cout << RED << frag.getName() << " es el ganador!" << RESET << std::endl;
            else if (fighters[i] == &scav) std::cout << GREEN << scav.getName() << " es el ganador!" << RESET << std::endl;
        }
    }
*/
    return 0;
}
