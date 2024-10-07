 #include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) { }

HumanB::~HumanB() { }

void HumanB::setWeapon(Weapon& weaponObj) {
    this->weapon = &weaponObj;
 }

void HumanB::attack() {
    std::cout << name << " attacks with their ";
    std::cout << this->weapon->getType() << std::endl;
}