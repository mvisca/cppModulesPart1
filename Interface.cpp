#include "GlobalHeader.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	displayTitle(void) {

	system("clear");

	std::cout << "__        __   _                            _         \n";
	std::cout << "\\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   \n";
	std::cout << " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  \n";
	std::cout << "  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | \n";
	std::cout << " __\\_/\\_/ \\___|_|\\___\\___/|_| |_|_|_|\\___|  \\__\\___/  \n";
	std::cout << "|  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __ \n";
	std::cout << "| |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ / \n";
	std::cout << "|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   <  \n";
	std::cout << "|_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\  \n";
	std::cout << std::endl;
}

std::string	displayMenuGetValue(bool isEsp) {

	if (isEsp) {
		std::cout << "Qué quieres hacer?\n";
		std::cout << "   [EXIT]\tpara Salir\n";
		std::cout << "   [ADD]\tpara Agregar Contacto\n";
		std::cout << "   [SEARCH]\tpara Buscar Contacto\n";
		std::cout << "   [ENG]\tpara cambiar menú a Inglés\n";
		std::cout << std::endl;
		std::cout << "Elige una opción: ";
	} else {
		std::cout << "What do you want to do?\n";
		std::cout << "   [EXIT]\tto Exit\n";
		std::cout << "   [ADD]\tto Add Contact\n";
		std::cout << "   [SEARCH]\tto Search Contact\n";
		std::cout << "   [ESP]\tto switch menu to English\n";
		std::cout << std::endl;
		std::cout << "Choose an option: ";
	}

	std::string	option;
	std::getline(std::cin, option);

	return (option);
}

void	inputContact(PhoneBook& phoneBook, const bool& isEsp) {

	std::string firstName;
	if (isEsp) {
		std::cout << "Entre el primer nombre: " << std::endl;
	} else {
		std::cout << "Enter first name: " << std::endl;
	}
	std::getline(std::cin, firstName);
	
	std::string lastName;
	if (isEsp) {
		std::cout << "Entre el segundo nombre: " << std::endl;
	} else {
		std::cout << "Enter last name: " << std::endl;
	}
	std::getline(std::cin, lastName);

	std::string nickname;
	if (isEsp) {
		std::cout << "Entre el apodo: " << std::endl;
	} else {
		std::cout << "Enter nickname: " << std::endl;
	}
	std::getline(std::cin, nickname);
	
	std::string phoneNumber;
	if (isEsp) {
		std::cout << "Entre el número de teléfono: " << std::endl;
	} else {
		std::cout << "Enter phone numbrer: " << std::endl;
	}
	std::getline(std::cin, phoneNumber);
	
	std::string darkestSecret;
	if (isEsp) {
		std::cout << "Entre el secreto más oscuro: " << std::endl;
	} else {
		std::cout << "Enter darkest secret: " << std::endl;
	}
	std::getline(std::cin, darkestSecret);

	phoneBook.addContact(
		firstName,
		lastName,
		nickname,
		phoneNumber,
		darkestSecret
	);
}