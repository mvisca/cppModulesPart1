#include "PhoneBook.hpp"
#include "GlobalHeader.hpp"

// Default Constructor
PhoneBook::PhoneBook(void) : _contactsCount(0) { }

// Destroyer
PhoneBook::~PhoneBook() { }

// Getters
int     PhoneBook::getMaxContacts(void) const {
	return PhoneBook::_maxContacts;
}

int		PhoneBook::getContactsCount(void) const {
	return _contactsCount;
}

// Getters
Contact    PhoneBook::searchContacts(const std::string& name) {

	for (int i = 0; i < _maxContacts; i++) {

		if (toUppercase(_contacts[i].getFirstName()) == toUppercase(name)) {

			return _contacts[i];

		}
	}

	return Contact();
}

Contact PhoneBook::getIndexContacts(const int i) const {
	return PhoneBook::_contacts[i];
}

// Setter
void	PhoneBook::addContact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret) {

	if (_contactsCount < _maxContacts) {

		_contacts[_contactsCount].setFirstName(firstName);
		_contacts[_contactsCount].setLastName(lastName);
		_contacts[_contactsCount].setNickname(nickname);
		_contacts[_contactsCount].setPhoneNumber(phoneNumber);
		_contacts[_contactsCount].setSecret(darkestSecret);
		incrementCount();

	} else {

		for (int i = 0; i < _contactsCount - 1; i++) {

			std::string tmp = _contacts[i + 1].getFirstName();
			_contacts[i].setFirstName(tmp);
			tmp = _contacts[i + 1].getLastName();
			_contacts[i].setLastName(tmp);
			tmp = _contacts[i + 1].getNickname();
			_contacts[i].setNickname(tmp);
			tmp = _contacts[i + 1].getPhoneNumber();
			_contacts[i].setPhoneNumber(tmp);
			tmp = _contacts[i + 1].getDarkestSecret();
			_contacts[i].setSecret(tmp);

		}

		_contacts[_maxContacts - 1].setFirstName(firstName);
		_contacts[_maxContacts - 1].setLastName(lastName);
		_contacts[_maxContacts - 1].setNickname(nickname);
		_contacts[_maxContacts - 1].setPhoneNumber(phoneNumber);
		_contacts[_maxContacts - 1].setSecret(darkestSecret);
	}
}

// Handlers
void	PhoneBook::incrementCount(void) {

	_contactsCount++;
}