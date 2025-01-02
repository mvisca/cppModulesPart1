/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:59:35 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 14:19:02 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* animals[100];

    for (int i = 0; i < 100; i++)
    {
        if (i % 2)
        {
            animals[i] = new Dog();
        }
        else
        {
            animals[i] = new Cat();
        }
        std::cout << "animals[" << i << "]" << std::endl;
        animals[i]->makeSound();
    }

    std::cout << "Get Dog" << std::endl;
    Dog* dog = dynamic_cast<Dog*>(animals[11]);
    if (dog)
    {
        std::cout << "Set Dog idea" << std::endl;
        (*dog).getBrain().setIdea(1, "Hola idea de Dog!");
    }

    std::cout << "Read Dog idea" << std::endl;
    std::cout << "animals[11]._ideas[0]= " << (*dog).getBrain().getIdea(0) << std::endl;
    std::cout << "animals[11]._ideas[1]= " << (*dog).getBrain().getIdea(1) << std::endl;
    std::cout << "animals[11]._ideas[2]= " << (*dog).getBrain().getIdea(2) << std::endl;

    for (int i = 0; i < 100; i++)
    {
        std::cout << "Destruyendo animals[" << i << "]" << std::endl;
        delete animals[i];
    }

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;

    return 0;
}