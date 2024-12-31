/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:05:19 by mvisca            #+#    #+#             */
/*   Updated: 2024/12/31 15:07:37 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    // Ex00
    std::cout << "---------- clap -----------" << std::endl;
    ClapTrap first_c;
    std::cout << "Name: " << first_c.getName() << std::endl;
    ClapTrap second_c("Second");
    std::cout << "Name: " << second_c.getName() << std::endl;
    // ClapTrap third("Third");
    // third = second;
    // std::cout << "Name: " << third.getName() << std::endl;
    // first.beRepaired(10);
    first_c.attack(second_c.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    // first.attack(second.getName());
    first_c.beRepaired(10);
    first_c.takeDamage(5);
    // second.takeDamage(1);
    // second.takeDamage(10);

    //Ex01
    std::cout << "---------- scav -----------" << std::endl;
    ScavTrap first_s;
    std::cout << "Name: " << first_s.getName() << " Attack: " << first_s.getAtta() << std::endl;
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
    std::cout << "---------- frag -----------" << std::endl;
    // FragTrap first("First");
    // std::cout << "Name: " << first.getName() << std::endl;
    // first.takeDamage(1);
    // first.attack("Dummy");
    // FragTrap second(first);
    // second.setName("Second");
    // second.takeDamage(2);
    // second.highFivesGuys();
    // FragTrap third;
    // third = first;
    // third.setName("Third");
    // third.beRepaired(8);
    // third.takeDamage(1);

    //Ex03
    std::cout << "---------- diamond -----------" << std::endl;
    DiamondTrap first_d;
    first_d.whoAmI();
    DiamondTrap second_d("Second_D");
    second_d.whoAmI();
    return 0;
}