/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:05:19 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/07 16:21:55 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    //Ex03
    std::cout << "---------- diamond -----------" << std::endl;
    DiamondTrap first_d;
    first_d.whoAmI();
    DiamondTrap second_d("Second_D");
    second_d.whoAmI();
    return 0;
}
