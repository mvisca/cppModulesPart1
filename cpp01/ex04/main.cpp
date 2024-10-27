#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static int validParams(int ac, char** av) {

	if (ac != 4){
		std::cerr << "Error: Número incorrecto de argumentos." << std::endl;
		std::cerr << "Debe incluir: ./replace <filename> <find> <replace>" << std::endl;
		return 1;
	}
	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (filename.empty()) {
		std::cerr << "Error: El nombre del archivo no puede estar vacío." << std::endl;
		return 1;
	}
	if (s1.empty()) {
		std::cerr << "Error: El texto a buscar no puede estar vacío." << std::endl;
		return 1;
	}
	if (s2.empty()) {
		std::cerr << "Error: El texto de reemplazo no puede estar vacío." << std::endl;
		return 1;
	}
	return 0;
}

static int	validFilename(std::string filename) {
	std::ifstream file(filename.c_str());
	if (!file) {
		std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
		return 1;
	}
	file.close();
	return 0;
}

int main(int ac, char** av) {

	if (validParams(ac, av) == 1) {
		return 1;
	}

	if (validFilename(av[1]) == 1) {
		return 1;
	}

	std::string filename(av[1]);
	std::ifstream file(filename.c_str());

	if (!file) {
		std::cerr << "Error: Algo salió mal al intentar abrir el archivo." << std::endl;
		return 1;
	}

	std::ostringstream buf;
	buf << file.rdbuf();
	std::string content = buf.str();

	file.close();

	std::string s1(av[2]);
	std::string s2(av[3]);

	// Busqueda no encontrada
	if (content.find(s1) == std::string::npos) {
			std::cerr << "Error: El texto '" << s1 << "' no se encontró en el archivo." << std::endl;
		}

	// Reemplazo manual
	size_t start = 0;
	size_t end = 0;
	size_t s1Len = s1.length();
	std::string result;

	while ((end = content.find(s1, start)) != std::string::npos) {
		result.append(content.substr(start, end));
		result.append(s2);
		start = end + s1Len;
	}
	result.append(content.substr(start));

	std::string newFilename = filename + ".replace";
	std::ofstream newFile(newFilename.c_str());
	if (!newFile) {
		std::cerr << "Error: No se pudo crear el archivo de salida '" << newFilename << "'." << std::endl;
		return 1;
	}

	newFile << result;
	newFile.close();

	std::cout << "Reemplazo completado. '" << newFilename << "' creado con éxito." << std::endl;

	return 0;
}