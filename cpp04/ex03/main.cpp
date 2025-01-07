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

// Prototipos de las pruebas
void runSubjectTest();
void runManualTest();
void runAllFullTest();
void runCharacterCopyTest();
void runMateriaSourceLimitTest();
void runDestructionOrderTest();
void runStressTest();

void displayMenu()
{
    std::cout << "\n====== 🛠️ MENU DE PRUEBAS 🛠️ ======\n";
    std::cout << "1. 🧪 Test del Subject\n";
    std::cout << "2. 🛠️ Creación Manual de Materias y Characters\n";
    std::cout << "3. 🧩 Prueba de Llenado de _all\n";
    std::cout << "4. 🔄 Copia y Asignación de Character\n";
    std::cout << "5. ⚔️ Comportamiento de MateriaSource con Slots Llenos\n";
    std::cout << "6. 🧠 Destrucción en Orden Inesperado\n";
    std::cout << "7. 💻 Stress Test\n";
    std::cout << "0. 🚪 Salir\n";
    std::cout << "=====================================\n";
    std::cout << "Seleccione una opción: ";
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
                std::cout << "🚪 Saliendo del programa...\n";
                break;
            default:
                std::cout << "❌ Opción inválida, intente nuevamente.\n";
        }
        AMateria::clearAll(); // Limpieza global después de cada test
    }

    std::cout << "✅ Todos los recursos han sido liberados correctamente.\n";
    return 0;
}

// Implementaciones de las pruebas

void runSubjectTest()
{
    std::cout << "\n🧪 Ejecutando Test del Subject...\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void runManualTest()
{
    std::cout << "\n🛠️ Creación Manual de Materias y Characters...\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* hero = new Character("Hero");
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    hero->equip(ice);
    hero->equip(cure);

    hero->use(0, *hero);
    hero->unequip(0);

    delete hero;
    delete src;
}

void runAllFullTest()
{
    std::cout << "\n🧩 Llenando _all hasta el límite...\n";
    try {
        for (int i = 0; i < 101; i++) {
            new Ice();
        }
        new Cure(); // Debería fallar
    } catch (const std::exception& e) {
        std::cout << "❌ Excepción capturada: " << e.what() << "\n";
    }
}

void runCharacterCopyTest()
{
    std::cout << "\n🔄 Probando Copia y Asignación de Character...\n";
    Character hero("Hero");
    hero.equip(new Ice());
    hero.equip(new Cure());

    Character copy(hero); // Constructor de copia
    Character assigned = hero; // Operador de asignación

    hero.use(0, hero);
    copy.use(1, copy);
    assigned.use(0, assigned);
}

void runMateriaSourceLimitTest()
{
    std::cout << "\n⚔️ Probando Slots Llenos en MateriaSource...\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); // Debería fallar

    AMateria* tmp = src->createMateria("ice");
    delete tmp;

    delete src;
}

void runDestructionOrderTest()
{
    std::cout << "\n🧠 Probando Destrucción en Orden Inesperado...\n";
    Character* hero = new Character("Hero");
    Character* sidekick = new Character("Sidekick");

    hero->equip(new Ice());
    sidekick->equip(new Cure());
    sidekick->unequip(0);

    delete hero; // Destruir primero al personaje con materias
    delete sidekick;
}

void runStressTest()
{
    std::cout << "\n💻 Ejecutando Stress Test...\n";
    for (int i = 0; i < 4200; i++) {
        Character* temp = new Character("Temp");
        temp->equip(new Ice());
        temp->equip(new Cure());
        delete temp;
    }
}
