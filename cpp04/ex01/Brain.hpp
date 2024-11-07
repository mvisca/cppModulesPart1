#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private:
		//----- Empty string for index out of range (0..99) -----//
		static const std::string empty;

		//----- Member variable -----//
		std::string _ideas[100];

	public:
		//----- Constructors -----/
		Brain();
		Brain(const Brain& other);

		//----- Assign operator -----//
		Brain& operator=(const Brain& other);

		//----- Descructor -----/
		~Brain();

		//----- Getter -----//
		const std::string& getIdea(int i) const;

		//----- Setter -----/
		void setIdea(int i, const std::string idea);
}

#endif