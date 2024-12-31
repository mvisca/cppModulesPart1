/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:05:19 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 16:53:27 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    // Ex00
    ClapTrap first("First");
    std::cout << "Name: " << first.getName() << std::endl;
    ClapTrap second("Second");
    std::cout << "Name: " << second.getName() << std::endl;
    ClapTrap third("Third");
    third = second;
    std::cout << "Name: " << third.getName() << std::endl;
    first.beRepaired(10);
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.attack(second.getName());
    first.beRepaired(10);
    second.takeDamage(1);
    second.takeDamage(10);
    return 0;
}