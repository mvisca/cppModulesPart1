/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:25:50 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/15 23:50:54 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
 
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm(void);

	protected:
		void executeAction(const Bureaucrat& bureaucrat) const;

	private:
		const std::string	_target;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);	
};

#endif
