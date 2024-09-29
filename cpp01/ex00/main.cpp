#include "Zombie.hpp"

int main() {
    Zombie* zOne = Zombie::newZombie("Z @ Heap One");
    zOne->announce();
    Zombie* zTwo = Zombie::newZombie("Z @ Heap Two");
    zTwo->announce();

    Zombie::randomChump("Z @ Stack One");
    Zombie::randomChump("Foo (Z @ Stack Two)");

    Zombie* zThree = Zombie::newZombie("Goo @ Heap");
    zThree->announce();

    delete zOne;
    delete zTwo;
    delete zThree;
}
 