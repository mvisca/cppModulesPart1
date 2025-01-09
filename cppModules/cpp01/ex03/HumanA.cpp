#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponObj) : name(name), weapon(weaponObj) { }

HumanA::~HumanA() { }

void HumanA::attack() const {
    std::cout << name << " attacks with their ";
    std::cout << weapon.getType() << std::endl;
}