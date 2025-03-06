/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:09:15 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/17 16:35:44 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm(const std::string& target);
        virtual ~RobotomyRequestForm(void);

        virtual void executeAction(const Bureaucrat& bureaucrat) const;

    private:
        const std::string _target;
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        static bool _initialized;
};

#endif 