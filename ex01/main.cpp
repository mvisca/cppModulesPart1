#include "GlobalHeader.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void) {

	bool		isEsp = true;
	PhoneBook	phoneBook;
	std::string	option;

	displayTitle();

	for (bool execution = true; execution;) {

		option = displayMenuGetValue(isEsp);
		option = toUppercase(option);

		if (option == "EXIT") {
			if (isEsp)
				std::cout << "Saliendo de PhoneBook!\n";
			else
				std::cout << "Leaving PhoneBook!\n";
			execution = false;

		} else if (option == "ADD") {
			displayTitle();
			if (isEsp)
				std::cout << "Agregando Contacto\n";
			else {
				std::cout << "Adding Contact\n";
			}
			inputContact(phoneBook, isEsp);

		} else if (option == "SEARCH") {
			displayTitle();
			if (isEsp)
				std::cout << "Buscando Contacto\n";
			else
				std::cout << "Searching Contact\n";

			printContacts(phoneBook, isEsp);
			const int optionIndex = getIndexValue(phoneBook, isEsp);
			const Contact contact = phoneBook.getIndexContacts(optionIndex);
			printContact(contact, isEsp);
//			std::this_thread::sleep_for(std::chrono::seconds(1));

		} else if (option == "ENG" && isEsp) {
			isEsp = false;
			displayTitle();
			std::cout << "Switch to English\n";

		} else if (option == "ESP" && !isEsp) {
			isEsp = true;
			displayTitle();
			std::cout << "Cambio a Español\n";

		} else {
			displayTitle();
			if (isEsp)
				std::cout << "Comando inválido: " << option << std::endl;
			else	
				std::cout << "Invalid command: " << option << std::endl;
		}
		std::cout << std::endl;
/*		for (int i = 0; i < phoneBook.getContactsCount(); i++) {
			std::cout << "Nombre: " << phoneBook.getIndexContacts(i).getFirstName() << std::endl;
		} */
	}
	return (0);
}