#include "Zombie.hpp"

Zombie::Zombie() : name("noName") {
    std::cout << R << "Zombie: " << W << this->name << G << " created @ " << W << this << B << "." << W << std::endl;
}

Zombie::Zombie(std::string zombieName) : name(zombieName) {
        std::cout << R << "Zombie: " << W << this->name << G << " created @ " << W << &this->name << B << "." << W << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed!" << std::endl;
}

void Zombie::setName(std::string& name) { 
    std::cout << R << "Set name from " << W << this->name;
    this->name = name;
    std::cout << G << " to " << W << this->name << B << "." << W << std::endl;
}

std::string Zombie::getName() const {
    return name;
}