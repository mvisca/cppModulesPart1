#include "Zombie.hpp"

// Imp constructor
Zombie::Zombie(std::string zombieName) : name(zombieName) {}

// Imp destructor implicito para que imprima
Zombie::~Zombie() {
    std::cout << name << " is destroyed!" << std::endl;
}

// Getter de name
std::string Zombie::getName() const {
    return name;
}

// Implementación de la función announce
void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}