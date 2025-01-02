/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:59:35 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 17:59:38 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Animal type: " << animal->getType() << std::endl;
    animal->makeSound(); 

    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();

    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << "---------------------------------" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    wrongAnimal->makeSound();

    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); 

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}