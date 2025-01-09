#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

private:

    std::string name;

public:

    Zombie();
    
    Zombie(std::string zombieName);

    ~Zombie();

    void setName(std::string &name);

    std::string getName() const;
};

Zombie* zombieHorde(int N, std::string name);

const std::string R = "\033[31m";
const std::string G = "\033[32m";
const std::string B = "\033[34m";
const std::string W = "\033[0m";

#endif