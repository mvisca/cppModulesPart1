#include "Zombie.hpp"

void Zombie::randomChump(std::string name) {
    Zombie mrChump(name);
    mrChump.announce();
}