/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:05:19 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/30 18:43:08 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    // Ex00
    // ClapTrap first("First");
    // std::cout << "Name: " << first.getName() << std::endl;
    // ClapTrap second("Second");
    // std::cout << "Name: " << second.getName() << std::endl;
    // ClapTrap third("Third");
    // third = second;
    // std::cout << "Name: " << third.getName() << std::endl;
    // first.beRepaired(10);
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.beRepaired(10);
    // second.takeDamage(1);
    // second.takeDamage(10);

    //Ex01
    // ScavTrap first("First");
    // std::cout << "Name: " << first.getName() << std::endl;
    // first.takeDamage(1);
    // first.attack("Dummy");
    // ScavTrap second(first);
    // second.setName("Second");
    // second.takeDamage(2);
    // second.guardGate();
    // ScavTrap third;
    // third = first;
    // third.setName("Third");
    // third.beRepaired(8);
    // third.takeDamage(1);

    //Ex02
    FragTrap first("First");
    std::cout << "Name: " << first.getName() << std::endl;
    first.takeDamage(1);
    first.attack("Dummy");
    FragTrap second(first);
    second.setName("Second");
    second.takeDamage(2);
    second.highFivesGuys();
    FragTrap third;
    third = first;
    third.setName("Third");
    third.beRepaired(8);
    third.takeDamage(1);
    return 0;
}