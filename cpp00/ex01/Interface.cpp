#include "GlobalHeader.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	inputControl(void) {
	std::string input;

	while (true) {
		if (std::getline(std::cin, input)) {
			if (!input.empty()) {
				return (input);
			}
			else {
				std::cout << "Empty/Vacía." << std::endl;
				continue;
			}
		}
		else if (std::cin.eof()) {
			std::cout << "Invalid / Inválido." << std::endl;
			exit(1);
		}
		else if (std::cin.fail()) {
			std::cout << "Fail / Fallo." << std::endl;
			std::cin.clear();
		}
	}
}

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
	option = inputControl();
	return (option);
}

void	inputContact(PhoneBook& phoneBook, const bool& isEsp) {

	std::string firstName;
	if (isEsp) {
		std::cout << "Entre el primer nombre: " << std::endl;
	} else {
		std::cout << "Enter first name: " << std::endl;
	}
	firstName = inputControl();

	std::string lastName;
	if (isEsp) {
		std::cout << "Entre el segundo nombre: " << std::endl;
	} else {
		std::cout << "Enter last name: " << std::endl;
	}
	lastName = inputControl();

	std::string nickname;
	if (isEsp) {
		std::cout << "Entre el apodo: " << std::endl;
	} else {
		std::cout << "Enter nickname: " << std::endl;
	}
	nickname = inputControl();
	
	std::string phoneNumber;
	if (isEsp) {
		std::cout << "Entre el número de teléfono: " << std::endl;
	} else {
		std::cout << "Enter phone numbrer: " << std::endl;
	}
	phoneNumber = inputControl();
	
	std::string darkestSecret;
	if (isEsp) {
		std::cout << "Entre el secreto más oscuro: " << std::endl;
	} else {
		std::cout << "Enter darkest secret: " << std::endl;
	}
	darkestSecret = inputControl();

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

void	printContact(const Contact& contact, const bool& isEsp) {

	if (isEsp) {
		std::cout << "Nombre: " << contact.getFirstName() << std::endl;
		std::cout << "Apellido: " << contact.getLastName() << std::endl;
		std::cout << "Apodo: " << contact.getNickname() << std::endl;
		std::cout << "Teléfono: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Secreto: " << contact.getDarkestSecret() << std::endl;
		std::cout << "Presiona [Enter] para continuar...";
	}
	else {
		std::cout << "First Name: " << contact.getFirstName() << std::endl;
		std::cout << "Last Name: " << contact.getLastName() << std::endl;
		std::cout << "Nickname: " << contact.getNickname() << std::endl;
		std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Secret: " << contact.getDarkestSecret() << std::endl;
		std::cout << "Press [Enter] to continue...";
	}
}

const int	getIndexValue(const PhoneBook& phoneBook, const bool& isEsp) {

	int	option;

	if (phoneBook.getContactsCount() == 0) {
		if (isEsp) {
			std::cout << "No se encontraron contactos." << std::endl;
			std::cout << "Presiona [Enter] para continuar..." << std::endl;
		} else {
			std::cout << "No contacts found." << std::endl;
			std::cout << "Press [Enter] to continue..." << std::endl;
		}
		return (-1);
	}
	while (true) {

		if (isEsp) {
			std::cout << "Elija un índice: ";
		}
		else {
			std::cout << "Chose an index: ";
		}

		std::string characters;

		characters = inputControl();

		if (characters.length() > 1)
			continue ;

		option = (characters[0] - '0') - 1;
		if (std::isdigit(characters[0])) {
			if (option >= 0 && option < phoneBook.getContactsCount()) {
				break ;
			}
		}
	}

	return option;
}
