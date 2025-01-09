#include "Zombie.hpp"

int main() {
    Zombie* zOne = Zombie::newZombie("Z one @ Heap One");
    zOne->announce();
    Zombie* zTwo = Zombie::newZombie("Z two @ Heap Two");
    zTwo->announce();

    Zombie::randomChump("Z random 1 @ Stack One");
    Zombie::randomChump("Z random 2 (Z @ Stack Two)");

    Zombie* zThree = Zombie::newZombie("Goo @ Heap");
    zThree->announce();

    delete zOne;
    delete zTwo;
    delete zThree;
}