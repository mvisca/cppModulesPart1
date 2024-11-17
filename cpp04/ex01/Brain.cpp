#include "Brain.hpp"

//----- Constructor -----/
Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "emptyIdea_" + std::to_string(i);
	}
	std::cout << "Constructor default de Brain llamado." << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
	std::cout << "Constructor por copia profunda de Brain llamado." << std::endl;
}

//----- Assign operator -----//
Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	std::cout << "Operador de asignación ('=') de Brain llamado." << std::endl;
}

//----- Descructor -----/
Brain::~Brain() {
	std::cout << "Destructor de Brain llamado." << std::endl;
}

//----- Getters -----//
const std::string& Brain::getIdea(int i) const {
	if (i >= 0 && i < 100) {
		return _ideas[i];
	}
	return _ideas[0];
}

//----- Setter -----/
void Brain::setIdea(int i, std::string idea) {
	if (i >= 0 && i < 100) {
		_ideas[i] = idea;
	}	
}

// //----- Estática para retorno de _idea fuera de rango -----//
// const std::string Brain::empty = "";