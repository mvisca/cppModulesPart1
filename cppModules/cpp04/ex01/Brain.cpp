/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:35:23 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 13:54:54 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        _ideas[i] = "Empty idea.";
    }
    std::cout << "Constructor default Brain llamado." << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "Constructor copia Brain llamado." << std::endl;
}

Brain::~Brain()
{
    std::cout << "Destructor Brain llamado." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            _ideas[i] = other._ideas[i];
        }
        std::cout << "Operador assign Brain llamado." << std::endl;
    }
    else
    {
        std::cout << "This y other son el mismo objeto." << std::endl;
    }
    return *this;
}

void Brain::setIdea(int index, const std::string idea) {_ideas[index] = idea;}
std::string Brain::getIdea(int index) const {return _ideas[index];}