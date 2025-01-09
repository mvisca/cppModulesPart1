#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;

}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string key) {

	// Crea las "KEYS"
	std::string keys[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	// Crea el type para las funciones
	typedef void (Harl::*HarlFunctions)(void);

	// Crea los "VALUES" que son referencia a las funciones correlativas a los "KEYS"
	HarlFunctions values[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	// Itera las "KEYS" para ejecutar la función
	for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); ++i) {
		if (key == keys[i]) {
			(this->*values[i])();
			return;
		}
	}

	// Último recuso para informar error de parámetro, debe atraparse antes sin llegar aquí
	std::cerr << "Error: parámetro no valído detectado en 'void Harl::complain(std:string level)' @ Harl.cpp." << key << std::endl;
}