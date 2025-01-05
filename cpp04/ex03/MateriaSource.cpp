/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:09:23 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/05 23:15:58 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = 0;
        std::cout << "+ Creando _materias en idx " << i << std::endl;
    }
    std::cout << "+ MateriaSource def constructor llamado." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
        {
            delete _materias[i];
            _materias[i] = 0;
        }
        if (other._materias[i])
        {
            _materias[i] = other._materias[i]->clone();
        }   
    }    
    std::cout << "+ MateriaSource copia constructor llamado." << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        delete _materias[i];
        _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias && _materias[i])
            {
                delete _materias[i];
                _materias[i] = 0;
                std::cout << "= Limpiando _materias en " << i << std::endl;
            }
            else
            {
                std::cout << "= Nada en _materias al " << i << std::endl;
            }
            if (other._materias && other._materias[i])
            {
                _materias[i] = other._materias[i]->clone();
                std::cout << "= Copiando _materias en " << i << std::endl;

            }
        }
    }
    std::cout << "= MateriaSource operador asignación llamado." << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = m;
            std::cout << "Materia aprendida." << std::endl;
            return;
        }
    }

    delete m;
    std::cout << "No hay espacio para aprender más Materias." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            std::cout << "MateriaSource clonando [" << type << "]" << std::endl;
            return _materias[i]->clone();
        }
    }
    std::cout << "No se pudo clonar por falta de espacio o type no conocido" << std::endl;
    return 0;
}