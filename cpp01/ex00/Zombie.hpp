#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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

    // Getter
    std::string getName() const;

    // Funcion miembro
    void announce(void);

    // Funcion estatica
    static Zombie* newZombie(std::string name);  // Crea un nuevo Zombie en memoria dinámica
    static void randomChump(std::string name);   // Crea un Zombie en el stack y lo anuncia
};

#endif