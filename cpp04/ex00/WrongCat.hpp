#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {

    public:
    //----- Constructor -----//
    WrongCat();

    //----- Member function -----//
    void makeSound(void) const;
	
    //----- Destructor -----//
    ~WrongCat();

};

#endif