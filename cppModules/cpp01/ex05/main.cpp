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

	// Crea objeto Harl
	Harl harl;

	// Entra en test sin parámetros
	if (argc == 1) {
		std::cout << "Ejecutando test estándar:" << std::endl << std::endl;

		standardTest();

		std::cout << "Haz un test personalizado agregando una de estas opciones:" << std::endl;
		std::cout << "\"DEBUG\" | \"INFO\" | \"WARNING\" | \"ERROR\"" << std::endl;
		return 0;
	}

	// Lee parámetros y lo valida, ejecuta o da error
	std::string level = argv[1];

	if (validateLevel(level)) {

		harl.complain(level);

	} else {

		std::cerr << "Error: argumento no válido." << std::endl;
		std::cout << "Haz un test personalizado agregando una de estas opciones:" << std::endl;
		std::cout << "\"DEBUG\" | \"INFO\" | \"WARNING\" | \"ERROR\"" << std::endl;
		return 1;
	}

	return 0;
}
