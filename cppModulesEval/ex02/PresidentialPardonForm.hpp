/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:25:30 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/17 09:54:14 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm(const std::string& target);
        virtual ~PresidentialPardonForm(void);

    protected:
        void	executeAction(const Bureaucrat& bureaucrat) const;

    private:
        const std::string	_target;
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

#endif 

