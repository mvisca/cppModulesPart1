#include "Zombie.hpp"

Zombie::Zombie() : name("noName") {
    std::cout << "Zombie: " << this->name << " created." << std::endl;
}

Zombie::Zombie(std::string zombieName) : name(zombieName) {
        std::cout << "Zombie: " << this->name << " created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed!" << std::endl;
}

void Zombie::setName(std::string& name) { 
    std::cout << "Set name from " << this->name;
    this->name = name;
    std::cout << " to " << this->name << "." << std::endl;
}

std::string Zombie::getName() const {
    return name;
}