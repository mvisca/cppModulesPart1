/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:01:52 by mvisca            #+#    #+#             */
/*   Updated: 2025/01/02 13:56:32 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain& brain);
		~Brain();

        Brain& operator=(const Brain& other);

        void setIdea(int index, const std::string idea);
        std::string getIdea(int index) const;
};

#endif