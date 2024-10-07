#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static int validParams(int ac, char** av) {

	if (ac != 4){
		std::cerr << "Invalid number of arguments" << std::endl;
		std::cerr << "./replace <filename> <find> <replace>" << std::endl;
		return 1;
	}
	
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cerr << "Not valid; inputs can't be empty." << std::endl;
		return 1;
	}
	return 0;
}

static int	validFilename(std::string filename) {
	std::ifstream file(filename.c_str());
	if (!file) {
		std::cerr << "Failed to open file." << std::endl;
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
		std::cerr << "Something went wrong." << std::endl;
		return 1;
	}
	std::ostringstream buf;
	buf << file.rdbuf();
	std::string content = buf.str();

	std::string s1(av[2]);
	std::string s2(av[3]);

// reemplazar en content s1x s2

	file.close();
	return 0;
}


// std::ifstream file(filename.c_str()); diff

// str.find(needle, initPos)