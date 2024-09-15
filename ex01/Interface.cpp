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
		std::cout << "   [ADD]\tpara Agregar Contacto\n";
		std::cout << "   [SEARCH]\tpara Buscar Contacto\n";
		std::cout << "   [ENG]\tpara Cambiar a Inglés\n";
		std::cout << "   [EXIT]\tpara Salir\n";
		std::cout << std::endl;
		std::cout << "Elige una opción: ";
	} else {
		std::cout << "What do you want to do?\n";
		std::cout << "   [ADD]\tto Add Contact\n";
		std::cout << "   [SEARCH]\tto Search Contact\n";
		std::cout << "   [ESP]\tto Switch to English\n";
		std::cout << "   [EXIT]\tto Exit\n";
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
	if (!std::getline(std::cin, firstName)) {
		std::cout << "Error! Input set to 'Default'\n";
		firstName = "Default";
	}
	
	std::string lastName;
	if (isEsp) {
		std::cout << "Entre el segundo nombre: " << std::endl;
	} else {
		std::cout << "Enter last name: " << std::endl;
	}
	if (!std::getline(std::cin, lastName)) {
		std::cout << "Error! Input set to 'Default'\n";
		lastName = "Default";
	}

	std::string nickname;
	if (isEsp) {
		std::cout << "Entre el apodo: " << std::endl;
	} else {
		std::cout << "Enter nickname: " << std::endl;
	}
	if (!std::getline(std::cin, nickname)) {
		std::cout << "Error! Input set to 'Default'\n";
		nickname = "Default";
	}
	
	std::string phoneNumber;
	if (isEsp) {
		std::cout << "Entre el número de teléfono: " << std::endl;
	} else {
		std::cout << "Enter phone numbrer: " << std::endl;
	}
	if (!std::getline(std::cin, phoneNumber)) {
		std::cout << "Error! Input set to 'Default'\n";
		nickname = "Default";
	}
	
	std::string darkestSecret;
	if (isEsp) {
		std::cout << "Entre el secreto más oscuro: " << std::endl;
	} else {
		std::cout << "Enter darkest secret: " << std::endl;
	}
	if (!std::getline(std::cin, darkestSecret)) {
		std::cout << "Error! Input set to 'Default'\n";
		darkestSecret = "Default";
	}

	phoneBook.addContact(
		firstName,
		lastName,
		nickname,
		phoneNumber,
		darkestSecret
	);
}

void	printContacts(const PhoneBook& phoneBook, const bool& isEsp) {

	std::string spaces(10, ' ');
	spaces.push_back('|');
	int	contactsCount = phoneBook.getContactsCount();

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < contactsCount; i++) {
		
		std::string firstName = phoneBook.getIndexContacts(i).getFirstName();
		size_t firstNameLen = firstName.length();

		std::string lastName = phoneBook.getIndexContacts(i).getLastName();
		size_t lastNameLen = lastName.length();

		std::string nickname = phoneBook.getIndexContacts(i).getNickname();
		size_t nicknameLen = nickname.length();

		std::cout << "|" << i + 1 << spaces.substr(1, 11);

		std::cout << firstName.substr(0, 10);
		if (firstNameLen > 9) {
			std::cout << "\b.|";
		}
		else {
			std::cout << spaces.substr(firstNameLen, 11);
		}

		std::cout << lastName.substr(0, 10);
		if (lastNameLen > 9) {
			std::cout << "\b.|";
		}
		else {
			std::cout << spaces.substr(lastNameLen, 11);
		}

		std::cout << nickname.substr(0, 10);
		if (nicknameLen > 9) {
			std::cout << "\b.|";
		}
		else {
			std::cout << spaces.substr(nicknameLen, 11);
		}

		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

const int	getIndexValue(const bool& isEsp) {
	if (isEsp) {
		std::cout << "Elija un índice: ";
		std::string optionIndex;
		std::getline(std::cin, optionIndex);
	}

	return 1;
}