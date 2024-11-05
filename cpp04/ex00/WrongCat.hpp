#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
    //----- Constructor -----//
    WrongCat();
    WrongCat(const WrongCat& other);

    WrongCat& operator=(const WrongCat& other);

    //----- Destructor -----//
    ~WrongCat();

    //----- Member function -----//
    void makeSound(void) const;
};

#endif