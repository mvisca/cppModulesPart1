/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:32:20 by mvisca            #+#    #+#             */
/*   Updated: 2025/03/06 19:25:46 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main(int ac, char **av)
{
    
    if (ac != 3)
    {
        std::cout << "Use: ./bureaucrat 'name' (int)grade" << std::endl;
        return (1);
    }
    
    Bureaucrat *buro = NULL;
    try
    {
        int num = std::stoi(av[2]);
        buro = new Bureaucrat(av[1], std::stoi(av[2]));
        std::cout << "Bureaucrat creado:" << std::endl;
        std::cout << (*buro) << std::endl;
        std::cout << "getName: " << buro->getName() << std::endl;
        std::cout << "getGrade: " << buro->getGrade() << std::endl;
        std::cout << "upGrade()..." << std::endl;
        buro->upGrade();
        std::cout << "getGrade: " << buro->getGrade() << std::endl;
        std::cout << "downGrade()..." << std::endl;
        buro->downGrade();
        std::cout << "getGrade: " << buro->getGrade() << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Exception: Out of range at " << e.what() << std::endl;
    }
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Exception: Invalid argument at " << e.what() << std::endl;
	}
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unknown exception raised: " << e.what() << std::endl;
    }

    if (buro)
        delete buro;
    std::cout << "Done." << std::endl;

    return (0);
}
    