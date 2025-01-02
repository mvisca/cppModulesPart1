/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:59:35 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 14:36:46 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j;//should not create a leak
    delete i;

    std::cout << "Quitar comentario en main.cpp para probar clase abstracta pura." << std::endl;
//    Animal a; // Animal es clase abstracta pura, no puede instanciarse.

    return 0;
}