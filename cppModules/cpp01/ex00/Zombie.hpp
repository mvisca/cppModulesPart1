#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
    // Atributo privado
    std::string name;

public:
    // Constructor
    Zombie(std::string zombieName);

    // Destructor
    ~Zombie();

    // Función miembro announce
    void announce() const;

    // Getter Zombie name
    std::string getName() const;

    // Funciones estáticas
    // Zombie heap
    static Zombie* newZombie(std::string name);

    // Zombie stack con announce
    static void randomChump(std::string name);
};

#endif