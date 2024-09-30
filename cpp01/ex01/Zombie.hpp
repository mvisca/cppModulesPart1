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

    // Funcion estatica
    Zombie* zombiHorde(int N, std::string name):
};

#endif