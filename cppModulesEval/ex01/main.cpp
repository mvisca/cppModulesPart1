/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:32:20 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/14 00:10:42 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "TEST 1: Crear Form inválido" << std::endl;
    try {
        Form invalidForm("Invalid Form", -1);
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "TEST 2: Crear Bureaucrat inválido" << std::endl;
    try {
        Bureaucrat invalidBureaucrat("Invalid Bureaucrat", 151);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "TEST 3: Crear Bureaucrat y Forms que puede y no puede firmar" << std::endl;
    try {
        Bureaucrat validBureaucrat("Buro", 100);
        std::cout << "Buro: " << validBureaucrat << std::endl;

        Form validForm110("Contract110", 110);
        std::cout << "Form Contract110: " << validForm110 << std::endl;
        validBureaucrat.signForm(validForm110);
        std::cout << "Form Contract110: " << validForm110 << std::endl;

        Form validForm90("Contract90", 90);
        std::cout << "Form Contract90: " << validForm90 << std::endl;
        validBureaucrat.signForm(validForm90);
        std::cout << "Form Contract90: " << validForm90 << std::endl;

    }
    catch (Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
    