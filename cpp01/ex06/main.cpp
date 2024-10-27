#include "Harl.hpp"

// Ejencuta test sin parámetros
void standardTest() {
	Harl harl;
	
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	for (int i = 0; i < 4; ++i) {
		harl.complain(levels[i]);
		std::cout << std::endl << "<------------>" << std::endl << std::endl;
	}
	std::cout << std::endl;
}

// Valida que el parámetros sea válido 
bool validateLevel(const std::string &level) {
	return (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR");
}

int main(int argc, char** argv) {


	// Valida parámetro
	if (argc != 2) {
		std::cerr << "Error: Se necesita un nivel de error:" << std::endl;
		std::cout << "\"DEBUG\" | \"INFO\" | \"WARNING\" | \"ERROR\"" << std::endl;

		return 1;
	}

	// Crea objeto Harl
	Harl harl;

	// Lee parámetros y lo valida, ejecuta o da error
	std::string key = argv[1];

	if (validateLevel(key)) {
		switch (key[0]) {
			case 'D':
				harl.complain("DEBUG");
				/* fall through */
			case 'I':
				harl.complain("INFO");
				/* fall through */
			case  'W':
				harl.complain("WARNING");
				/* fall through */
			case 'E':
				harl.complain("ERROR");
				/* fall through */
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}

	} else {

		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
   
		return 1;
	}

	return 0;
}
