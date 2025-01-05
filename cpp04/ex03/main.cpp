/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:07:07 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/05 23:35:52 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// Prueba 1: Creación y Destrucción de Objetos
void test_creation_and_destruction() {
    std::cout << "\n--- PRUEBA 1: CREACIÓN Y DESTRUCCIÓN ---\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* character = new Character("Hero");

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    character->equip(ice);
    character->equip(cure);

    delete character;
    delete src;
}

// Prueba 2: Copia profunda
void test_deep_copy() {
    std::cout << "\n--- PRUEBA 2: COPIA PROFUNDA ---\n";
    Character* original = new Character("Original");
    original->equip(new Ice());
    original->equip(new Cure());

    Character* copy = new Character(*original); // Constructor de copia

    original->unequip(0);
    original->unequip(1);

    delete original;
    
    copy->use(0, *copy);
    copy->use(1, *copy);

    delete copy;
}

// Prueba 3: Equipar y Desequipar Materias
void test_equip_and_unequip() {
    std::cout << "\n--- PRUEBA 3: EQUIPAR Y DESEQUIPAR ---\n";
    Character* character = new Character("Equipper");

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    character->equip(ice);
    character->equip(cure);
    character->equip(ice); // Intento duplicado (debe fallar)

    character->unequip(0);
    character->unequip(1);

    delete character; // Asegurar que no hay fugas de memoria.
}

// Prueba 4: Uso de Materias
void test_materia_usage() {
    std::cout << "\n--- PRUEBA 4: USO DE MATERIAS ---\n";
    Character* character = new Character("User");
    Character* target = new Character("Target");

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    character->equip(ice);
    character->equip(cure);

    character->use(0, *target); // Ice
    character->use(1, *target); // Cure
    character->use(2, *target); // Índice vacío (error esperado)

    delete character;
    delete target;
}

// Prueba 5: MateriaSource
void test_materia_source() {
    std::cout << "\n--- PRUEBA 5: MATERIASOURCE ---\n";
    MateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); // Slot lleno (debe fallar)

    AMateria* materia = src->createMateria("ice");
    if (materia) {
        std::cout << "Materia creada correctamente: " << materia->getType() << std::endl;
        delete materia;
    } else {
        std::cout << "Fallo al crear materia 'ice'" << std::endl;
    }

    delete src;
}

// Prueba 6: Escenarios límite
void test_edge_cases() {
    std::cout << "\n--- PRUEBA 6: ESCENARIOS LÍMITE ---\n";
    Character* character = new Character("EdgeTester");

    character->equip(NULL); // No debe fallar

    character->use(5, *character); // Índice fuera de rango
    character->unequip(-1); // Índice inválido

    delete character;
}

// Prueba 7: Flujo Completo
void test_full_flow() {
    std::cout << "\n--- PRUEBA 7: FLUJO COMPLETO ---\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("Player");
    ICharacter* enemy = new Character("Enemy");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->use(0, *enemy);
    me->use(1, *enemy);

    me->unequip(0);
    me->unequip(1);

    delete enemy;
    delete me;
    delete src;
}

// Función Principal
int main() {
    std::cout << "======= INICIO DE LAS PRUEBAS =======\n";

    test_creation_and_destruction();
    test_deep_copy();
    // test_equip_and_unequip();
    // test_materia_usage();
    // test_materia_source();
    // test_edge_cases();
    // test_full_flow();

    std::cout << "\n======= TODAS LAS PRUEBAS COMPLETADAS =======\n";
    return 0;
}
