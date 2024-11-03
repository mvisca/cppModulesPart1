#include "GlobalHeader.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void) {

	PhoneBook	phoneBook;
	std::string	option;
	bool		isEsp = true;

	displayTitle();

	for (bool execution = true; execution;) {

		option = toUppercase(displayMenuGetValue(isEsp));

		// ADD
		if (option == "ADD") {
			displayTitle();
			if (isEsp)
				std::cout << "Agregando Contacto\n";
			else {
				std::cout << "Adding Contact\n";
			}
			inputContact(phoneBook, isEsp);
		}

		// SEARCH
		else if (option == "SEARCH") {
			displayTitle();
			if (phoneBook.getContactsCount() > 0) {
				if (isEsp)
					std::cout << "Buscando Contacto\n";
				else
					std::cout << "Searching Contact\n";
				printContacts(phoneBook, isEsp);
				const int optionIndex = getIndexValue(phoneBook, isEsp);
				const Contact contact = phoneBook.getIndexContacts(optionIndex);
				printContact(contact, isEsp);
			} else {
				const int optionIndex = getIndexValue(phoneBook, isEsp);
			}
			std::cin.get();
			displayTitle();
		}

		// SWITCH ENG
		else if (option == "ENG" && isEsp) {
			isEsp = false;
			displayTitle();
			std::cout << "Switch to English" << std::endl;
		}

		// SWITCH ESP
		else if (option == "ESP" && !isEsp) {
			isEsp = true;
			displayTitle();
			std::cout << "Cambio a Español" << std::endl;
		}

		// EXIT
		else if (option == "EXIT") {
			if (isEsp)
				std::cout << "Saliendo de PhoneBook!\n";
			else
				std::cout << "Leaving PhoneBook!\n";
			execution = false;
		}

		else {
			displayTitle();
			if (isEsp)
				std::cout << "Comando inválido: " << option << std::endl;
			else	
				std::cout << "Invalid command: " << option << std::endl;
		}
	}
	return (0);
}