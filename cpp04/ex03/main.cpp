/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:32:15 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/07 13:55:32 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <exception>


void runSubjectTest();
void runManualTest();
void runAllFullTest();
void runCharacterCopyTest();
void runMateriaSourceLimitTest();
void runDestructionOrderTest();
void runStressTest();

void displayMenu()
{
    std::cout << "TESTS\n";
    std::cout << "1. El test del Subject\n";
    std::cout << "2. Creacion de Materias y Characters\n";
    std::cout << "3. Llenar AMateria::_all\n";
    std::cout << "4. Crea, copia y asigna Character\n";
    std::cout << "5. Llenar MateriaSource\n";
    std::cout << "6. Orden de destruccion\n";
    std::cout << "7. 4200 instancias\n";
    std::cout << "0. Salir\n";
    std::cout << "=====================================\n";
    std::cout << "Elige un test: ";
}

int main()
{
    int option = -1;
    while (option != 0)
    {
        displayMenu();
        std::cin >> option;
        switch (option)
        {
            case 1: runSubjectTest(); break;
            case 2: runManualTest(); break;
            case 3: runAllFullTest(); break;
            case 4: runCharacterCopyTest(); break;
            case 5: runMateriaSourceLimitTest(); break;
            case 6: runDestructionOrderTest(); break;
            case 7: runStressTest(); break;
            case 0: 
                break;
            default:
                std::cout << "Elige otra vez\n";
        }
        AMateria::clearAll();
    }

    std::cout << "Saliendo...\n";
    return 0;
}

void runSubjectTest()
{
    std::cout << "\nEl test del Subject\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* him = new Character("bob");
    me->use(0, *him);
    me->use(1, *him);

    delete him;
    delete me;
    delete src;
}

void runManualTest()
{
    std::cout << "\nCrear Materias y Characters\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* personaje = new Character("Personaje");
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    personaje->equip(ice);
    personaje->equip(cure);

    personaje->use(0, *personaje);
    personaje->unequip(0);

    delete personaje;
    delete src;
}

void runAllFullTest()
{
    std::cout << "\nLlenar AMateria::_all\n";
    try {
        for (int i = 0; i < 101; i++) {
            new Ice();
        }
        new Cure(); // Tiene que fallar
    } catch (const std::exception& e) {
        std::cout << "try-catch: " << e.what() << "\n";
    }
}

void runCharacterCopyTest()
{
    std::cout << "\n Crea, copiar y asignar Character\n";
    Character personaje("Personaje");
    personaje.equip(new Ice());
    personaje.equip(new Cure());

    Character copy(personaje);
    Character assigned = personaje;

    personaje.use(0, personaje);
    copy.use(1, copy);
    assigned.use(0, assigned);
}

void runMateriaSourceLimitTest()
{
    std::cout << "\n Llenar MateriaSource\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); // Tiene que fallar

    AMateria* tmp = src->createMateria("ice");
    delete tmp;

    delete src;
}

void runDestructionOrderTest()
{
    std::cout << "\n Orden de destruccion\n";
    Character* personaje = new Character("personaje");
    Character* rival = new Character("rival");

    personaje->equip(new Ice());
    rival->equip(new Cure());
    rival->unequip(0); // Queda sin duenyo

    delete rival;
    delete personaje;
}

void runStressTest()
{
    std::cout << "\n 4200 instancias\n";
    for (int i = 0; i < 4200; i++) {
        std::cout << "Instancia " << i + 1 << std::endl;
        Character* temp = new Character("Temp");
        temp->equip(new Ice());
        temp->equip(new Cure());
        delete temp;
    }
}
